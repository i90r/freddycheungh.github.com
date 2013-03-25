#include "application.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <iostream>

using namespace std;
#define CpAttr(x,n) strncpy(this->x,x,n);this->x[n]=0

struct Movie{
    char name[71];
    char actors[301];
    char desc[1656];
    char releaseDate[11];
    unsigned long genre;
    unsigned long rating;    
    Movie(char name[]="",char actors[]="",char desc[]="",char releaseDate[]="",unsigned long genre=1,unsigned long rating=1){
        CpAttr(name, 70);
        CpAttr(actors, 300);
        CpAttr(desc, 1655);
        CpAttr(releaseDate, 10);
        this->genre = genre;
        this->rating = rating;
    }
};

void operator<<(CDialog& D, Movie& M){
    D[4].set(M.name);
    D[6].set(M.releaseDate);
    D[7].set(M.actors);
    D[9].set(M.desc);
    D[11].set(&M.rating);
    D[13].set(&M.genre);
}

void operator<<(Movie& M,CDialog& D){
    strcpy(M.name, (char*)D[4].data());
    strcpy(M.releaseDate, (char*)D[6].data());
    strncpy(M.actors, (char*)D[7].data(),300);
    M.actors[300] = 0;
    strncpy(M.desc, (char*)D[9].data(),1655);
    M.desc[1655] = 0;
    M.rating = *(unsigned long *)D[11].data();
    M.genre = *(unsigned long *)D[13].data();
}

bool operator==(Movie& M, CDialog& D) {
    if (strcmp(M.name, (char*)D[4].data()) != 0)
        return false;
    if (strcmp(M.releaseDate, (char*)D[6].data()) != 0)
        return false;
    if (strcmp(M.actors, (char*)D[7].data()) != 0)
        return false;
    if (strcmp(M.desc, (char*)D[9].data()) != 0)
        return false;
    return true;
}

int messageFieldIndex = 0; // Global valrable? YUCK!!!!

bool Yes(const char* message, CDialog* owner){
    int key;
    bool res = false;
    bool done = false;
    CButton bt_yes("Yes", 4, 4, true);
    CButton bt_no("No", 4, 15, true);
    CDialog YesNo(owner, (console.getRows()- 10) / 2, (console.getCols() - 40) / 2, 40, 10, true);
    YesNo << new CLabel(2, 2, 36) << bt_yes << bt_no;
    YesNo[0].set(message);
    YesNo.draw(C_FULL_FRAME);
    while(!done) {
        key = YesNo.edit();
        if (key == C_BUTTON_HIT) {
            res = &YesNo.curField() == &bt_yes;
            done = true;
        }
    }
    YesNo.hide();
    return res;
}

void Help(CDialog* owner){
    CDialog help(owner, (console.getRows() - 10) / 2, (console.getCols() - 40) / 2, 40, 12, true);
    help<<new CLabel("F1 Key: Open This Window", 0, 3)
        <<new CLabel("F2 Key: Save", 2, 3)
        <<new CLabel("F3 Key: Re-Load", 4, 3)
        <<new CLabel("F6: Move", 6, 3)
        <<new CLabel("ESC: Exit.", 8, 3);
    help.edit(C_FULL_FRAME);
    help.hide();
}

bool ValidDate(const char* datestr , CDialog& owner){
  bool ok = true;

  //validation for a date  dd/mm/yyyy

  if(ok){
    owner[messageFieldIndex].set("");
  }
  else{
    owner[messageFieldIndex].set("Invlid phone number, please use the specified phone number format!");
  }
  owner.draw(messageFieldIndex+1);
  return ok;
}

#define Action           0X1
#define Adventure        0X2
#define Comedy           0X4
#define Crime            0X8
#define Documentary      0X10  
#define Drama            0X20 
#define Fantasy          0X40
#define Horror           0X80
#define Mystery          0X100
#define Romance          0X200
#define Satire           0X400
#define Sci Fi           0X800
#define Thriller         0X1000 

#define     R_G        0x1
#define     R_PG       0x2
#define     R_PG13     0x4
#define     R_18A      0x8
#define     R_R        0x10
#define     R_A        0x20

Movie Mv[100];
Movie currentMovie;

void loadMovie(Movie* des, char* file, int index);

#define ToRec(x) App<<Mv[mi=x];App.draw()

void deleteMovie(char* file, int index) {
    int end;
    int len;
    char* cpyName = new char[strlen(file) + 6];
    strcpy(cpyName, file);
    strcat(cpyName, "_CPY");
    Movie temp;
    fstream read(file, ios::in|ios::out|ios::binary);
    fstream copy(cpyName, ios::out|ios::binary|ios::trunc);
    read.seekg((ios::off_type)0, ios::end);
    end = read.tellg();
    len = end / sizeof(Movie);
    if (index > len) {
        copy.close();
        read.close();
        delete [] cpyName;
        return;
    }
    else {
        for (int i = 0; i < len; i++) {
            if (i != index) {
                loadMovie(&temp, file, i);
                copy.write((const char*)&temp, sizeof(Movie));
            }
        }
        copy.close();
        read.close();
        remove(file);
        rename(cpyName, file);
        delete [] cpyName;
    }
}

void saveMovie(Movie* src, char* file, int index) {
    int end;
    fstream read(file, ios::in|ios::out|ios::binary);
    read.seekg((ios::off_type)0, ios::end);
    end = read.tellg();
    int t = end / sizeof(Movie);
    if (end / sizeof(Movie) < index) {
        index = end / sizeof(Movie) + 1;
    }
    read.seekp((ios::pos_type)(index * sizeof(Movie)));
    read.write((const char*)src, sizeof(Movie));
    read.close();
}

void loadMovie(Movie* des, char* file, int index) {
    int end;
    fstream read(file, ios::in|ios::binary);
    read.seekg((ios::off_type)0, ios::end);
    end = read.tellg();
    if (end < sizeof(Movie) && (end / sizeof(Movie) > index)) {
        *des = Movie();
    }
    else {
        for (int i = 0; i * sizeof(Movie) < end; i++) {
            if (i == index) {
                read.seekg((ios::pos_type)(i * sizeof(Movie)));
                read.read((char*)des, sizeof(Movie));
                break;
            }
        }
    }
    read.close();
}

int numMovies(char* file) {
    int retVal;
    int end;
    fstream read(file, ios::in|ios::binary);
    read.seekg((ios::off_type)0, ios::end);
    end = read.tellg();
    retVal = end / sizeof(Movie);
    read.close();
    return retVal;
}

int main(int argc, char* argv[]){

    /*if (argc < 2) {
        cout << "no file selected " << endl;
        return 0;
    }*/

    int count = numMovies(argv[1]);
    Movie cur;
    loadMovie(&cur, argv[1], 0);
    bool insert = true;
    bool done = false;
    int fn;
    CDialog Screen;
    int mi = 0;

    Screen<< new CLabel("F1: HELP ", 0, 0);
    Screen.draw();

    CDialog App(&Screen,1, 2, 75, 22, true);

    CCheckList Genre("[X]", 6, 58, 15, false,true,"+-+|+-+|");
    Genre.add("Action");           
    Genre.add("Adventure");        
    Genre.add("Comedy");           
    Genre.add("Crime");            
    Genre.add("Documentary");
    Genre.add("Drama");
    Genre.add("Fantasy");
    Genre.add("Horror");
    Genre.add("Mystery");
    Genre.add("Romance");
    Genre.add("Satire");
    Genre.add("Sci Fi");
    Genre.add("Thriller");

    CCheckList Rating("(0)",7, 46, 10, true,true,"+-+|+-+|");  
    Rating.add("G");
    Rating.add("PG");
    Rating.add("PG13");
    Rating.add("18A");
    Rating.add("R");
    Rating.add("A");

    CMenu FileMenu("File", "[]", 0, 1, 9, 6, true);
    FileMenu<<"Load"<<"Save"<<"Add New"<<"Delete"<<"Help"<<CMenu::Select<<"Quit";

    CMenu NavMenu("Navigate","[]", 0, 8, 9, 5, true);
    NavMenu<<"Next"<<CMenu::Select<<"Prev"<<"First"<<"Last";

    CButton BtFrst("First (F7)",18,1, true," -   -  ");
    CButton BtPrev("Prev  (F8)",18,15, true," -   -  ");
    CButton BtNext("Next  (F9)",18,29, true," -   -  ");
    CButton BtLast("Last (F10)",18,43, true," -   -  ");

    App<<FileMenu
        <<NavMenu
        <<new CLabel("<< CpaCoderpz Movie Browser >>", 0, 25)
        <<new CLabel("Name:", 2, 2)
        <<new CLineEdit(1, 8, 34, 70, &insert, true,"+-+|+-+|")
        <<new CLabel("Release Date:", 2, 44)
        <<new CValEdit(1, 58, 12, 10, &insert, ValidDate, NO_HELPFUNC, true,"+-+|+-+|")
        <<new CText(5,2,40,5,&insert,false, "+-+|+-+|")
        <<new CLabel("Actors:", 4, 2)
        <<new CText(11, 2, 40, 7, &insert, false,"+-+|+-+|")<<new CLabel("Story:",10,2)
        <<Rating
        <<new CLabel("Rating:", 6, 46)
        <<Genre<<new CLabel("Genre", 5, 58)<<BtFrst<<BtPrev<<BtNext<<BtLast;

    messageFieldIndex = App.add(new CLabel(4, 14, 60));

    fn = 5;
    App<<cur;
    App.draw(C_FULL_FRAME);
    while(!done){
        switch(App.edit(fn)) {
            case F(2):
                cur<<App;
                saveMovie(&cur, argv[1], mi);
            break;
            case F(3):
                loadMovie(&cur, argv[1], mi);
                App<<cur;
            break;
            case F(1):
                Help(&App);
            break;
            case F(6):
                App.move();
            break;
            case F(7):
                if (mi != 0) {
                    if (!(cur == App) && Yes("Do you want to save changes?", &App)) {
                        cur<<App;
                        saveMovie(&cur, argv[1], mi);
                    }
                    mi = 0;
                    loadMovie(&cur, argv[1], mi);
                    App<<cur;
                    App.draw();
                }
            break;
            case F(8):
                if (mi > 0) {
                    if (!(cur == App) && Yes("Do you want to save changes?", &App)) {
                        cur<<App;
                        saveMovie(&cur, argv[1], mi);
                    }
                    loadMovie(&cur, argv[1], --mi);
                    App<<cur;
                    App.draw();
                }
            break;
            case F(9):
                if (mi + 1 < count) {
                    if (!(cur == App) && Yes("Do you want to save changes?", &App)) {
                        cur<<App;
                        saveMovie(&cur, argv[1], mi);
                    }
                    loadMovie(&cur, argv[1], ++mi);
                    App<<cur;
                    App.draw();
                }
            break;
            case F(10):
                if (mi + 1 != count - 1) {
                    if (!(cur == App) && Yes("Do you want to save changes?", &App)) {
                        cur<<App;
                        saveMovie(&cur, argv[1], mi);
                    }
                    mi = numMovies(argv[1]) - 1;
                    loadMovie(&cur, argv[1], mi);
                    App<<cur;
                    App.draw();
                }
            break;
            case F(11):
                // File Menu Focus
                fn = 1;
            break;
            case F(12):
                // Navigate Menu Focus
                fn = 2;
            break;
            case ESCAPE:
                if (Yes("Do you want to save?", &App)) {
                    cur<<App;
                    saveMovie(&cur, argv[1], mi);
                }
                done = true;
            break;
            case C_BUTTON_HIT:
                if (&App.curField() == &BtFrst) {
                    if (mi != 0) {
                        if (!(cur == App) && Yes("Do you want to save changes?", &App)) {
                            cur<<App;
                            saveMovie(&cur, argv[1], mi);
                        }
                        mi = 0;
                        loadMovie(&cur, argv[1], mi);
                        App<<cur;
                        App.draw();
                    }
                }
                else if (&App.curField() == &BtNext) {
                    if (mi + 1 < count) {
                        if (!(cur == App) && Yes("Do you want to save changes?", &App)) {
                            cur<<App;
                            saveMovie(&cur, argv[1], mi);
                        }
                        loadMovie(&cur, argv[1], ++mi);
                        App<<cur;
                        App.draw();
                    }
                }
                else if(&App.curField() == &BtPrev ) {
                    if (mi > 0) {
                        if (!(cur == App) && Yes("Do you want to save changes?", &App)) {
                            cur<<App;
                            saveMovie(&cur, argv[1], mi);
                        }
                        loadMovie(&cur, argv[1], --mi);
                        App<<cur;
                        App.draw();
                    }
                }
                else if (&App.curField() == &BtLast) {
                    if (mi + 1 != count - 1) {
                        if (!(cur == App) && Yes("Do you want to save changes?", &App)) {
                            cur<<App;
                            saveMovie(&cur, argv[1], mi);
                        }
                        mi = numMovies(argv[1]) - 1;
                        loadMovie(&cur, argv[1], mi);
                        App<<cur;
                        App.draw();
                    }
                }
            case SPACE:
                fn = App.curIndex() + 1;
                if (&App.curField() == &FileMenu){
                    switch (FileMenu.selectedIndex()){
                        case 0:
                            loadMovie(&cur, argv[1], mi);
                            App<<cur;
                        break;
                        case 1:
                            cur<<App;
                            saveMovie(&cur, argv[1], mi);
                        break; 
                        case 2:
                            cur = Movie();
                            strcpy(cur.actors, "");
                            strcpy(cur.desc, "");
                            strcpy(cur.name, "");
                            strcpy(cur.releaseDate, "");
                            mi = count;
                            count++;
                            App<<cur;
                            App.draw();
                        break;
                        case 3:
                            deleteMovie(argv[1], mi);
                            count = numMovies(argv[1]);
                            if (count > 0) {
                                if (mi >= count) {
                                    mi = count - 1;
                                }
                                loadMovie(&cur, argv[1], mi);
                            }
                            else {
                                cur = Movie();
                            }
                            App<<cur;
                            App.draw();
                        break;
                        case 4:
                            Help(&App);
                        break;
                        case 5:
                            if (Yes("Do you want to save?", &App)){
                                cur<<App;
                                saveMovie(&cur, argv[1], mi);
                            }
                            done = true;
                        break;
                    }
                }
                else if(&App.curField() == &NavMenu) {
                    switch (NavMenu.selectedIndex()){
                        case 0:
                            if (mi + 1 < count) {
                                if (!(cur == App) && Yes("Do you want to save changes?", &App)) {
                                    cur<<App;
                                    saveMovie(&cur, argv[1], mi);
                                }
                                loadMovie(&cur, argv[1], ++mi);
                                App<<cur;
                                App.draw();
                            }
                        break;
                        case 1:
                            if (mi > 0) {
                                if (!(cur == App) && Yes("Do you want to save changes?", &App)) {
                                    cur<<App;
                                    saveMovie(&cur, argv[1], mi);
                                }
                                loadMovie(&cur, argv[1], --mi);
                                App<<cur;
                                App.draw();
                            }
                        break;
                        case 2:
                            if (mi != 0) {
                                if (!(cur == App) && Yes("Do you want to save changes?", &App)) {
                                    cur<<App;
                                    saveMovie(&cur, argv[1], mi);
                                }
                                mi = 0;
                                loadMovie(&cur, argv[1], mi);
                                App<<cur;
                                App.draw();
                            }
                        break;
                        case 3:
                            if (mi + 1 != count - 1) {
                                if (!(cur == App) && Yes("Do you want to save changes?", &App)) {
                                    cur<<App;
                                    saveMovie(&cur, argv[1], mi);
                                }
                                mi = numMovies(argv[1]) - 1;
                                loadMovie(&cur, argv[1], mi);
                                App<<cur;
                                App.draw();
                            }
                        break;
                    }
                }
            break;
        }
    }
    return 0;
}