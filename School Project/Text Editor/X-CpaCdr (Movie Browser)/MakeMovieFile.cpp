#include "application.h"
#include <cstdio>
#include <cstring>
#include <fstream>
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

Movie Mv[6] = {
  Movie("The Shawshank Redemption","Tim Robbins, Morgan Freeman and Bob Gunton","Two imprisoned men bond over a number of years,\nfinding solace and eventual redemption through acts \nof common decency.",
            "14/10/1994", Crime|Drama, R_R),
  Movie("The Godfather","Marlon Brando, Al Pacino and James Caan","The aging patriarch of an organized crime dynasty \ntransfers control of his clandestine empire \nto his reluctant son.",
            "24/03/1972", Crime|Drama, R_R),
  Movie("Pulp Fiction","John Travolta, Uma Thurman and Samuel L. Jackson","The lives of two mob hit men, a boxer, \na gangster's wife, and a pair of diner bandits \nintertwine in four tales of violence and redemption.",
            "14/10/1994", Crime|Thriller, R_R),
  Movie("The Lord of the Rings: The Return of the King","Elijah Wood, Viggo Mortensen and Ian McKellen","Aragorn leads the World of Men against \nSauron's army to draw the dark lord's gaze \nfrom Frodo and Sam who are on the doorstep of \nMount Doom with the One Ring.",
            "17/12/2003", Action|Adventure|Fantasy, R_PG13),
  Movie("Star Wars: Episode V - The Empire Strikes Back","Mark Hamill, Harrison Ford and Carrie Fisher","As Luke trains with Master Yoda to become a Jedi Knight, \nhis friends evade the Imperial fleet under the command of \nDarth Vader who is obsessed with turning \nSkywalker to the Dark Side of the Force.",
            "21/05/1980", Crime|Drama, R_R)
};
int main(){
  ofstream outfile("movies.bin", ios::binary);
  for(int x=0;x<5;x++){
    outfile.write((char*)&Mv[x], sizeof(Movie));
  }
  outfile.close();
  return 0;
}