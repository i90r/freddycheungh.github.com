// BConsole Input Output Library - Unified Implementation
// conbio.cpp
//
// Fardad Soleimanloo, Chris Szalwinski
// Jan 20 2012
// Version 1.01

#define BIO_LINUX       1
#define BIO_MICROSOFT   2
#define BIO_BORLAND     3
#define BIO_UNIX        4

#if defined __BORLANDC__
    #define BIO_PLATFORM BIO_BORLAND
    #define BIO_LOWER_LEVEL_H_ <conio.h>

#elif defined _MSC_VER
    #define BIO_PLATFORM BIO_MICROSOFT
    #include <windows.h>
    #define BIO_LOWER_LEVEL_H_ <conio.h>

#elif defined __MACH__
    #define BIO_PLATFORM BIO_UNIX
    #define BIO_LOWER_LEVEL_H_ <curses.h>

#elif defined __GNUC__
    #define BIO_PLATFORM BIO_LINUX
    #define BIO_LOWER_LEVEL_H_ <ncurses.h>

#elif !defined __BORLANDC__ && !defined _MSC_VER && !defined __GNUC__ && !defined __MACH__
    #error CONSOLE_PLT is undefined
#endif

extern "C" {
    #include BIO_LOWER_LEVEL_H_
}

#include "bconsole.h"

namespace bio {

    unsigned int strlen(const void* data) {
        const char* str = (const char*) data;
        unsigned int len = 0;
        while (*str++) {
            len++;
        }
        return len;
    }

    char* strcpy(void* d, const void* s) {
        char* des = (char*) d;
        const char* src = (const char*) s;
        char* ret = des;
        while (*des++ = *src++);
        return ret;
    }

    char* strncpy(void* d, const void* s, unsigned int len) {
        char* des = (char*) d;
        const char* src = (const char*) s;
        while (len-- && (*des++ = *src++));
        return (char*) d;
    }

    #if BIO_PLATFORM == BIO_LINUX || BIO_PLATFORM == BIO_UNIX

    BConsole::BConsole() {
        ::initscr();
        ::noecho();
        ::cbreak();
        ::keypad(stdscr, 1);
        bufrows = LINES;
        bufcols = COLS;
        if (bufrows * bufcols > 0) {
            buffer  = new char[bufrows * bufcols];
        }
        else {
            buffer = 0;
        }
        clear();
    }

    BConsole::~BConsole() {
        clear();
        setPos(0, 0);
        delete [] buffer;
        ::endwin();
    }

    void BConsole::clear() {
        ::erase();
        clearBuffer();
    }

    int BConsole::getKey() const {
        int key;
        ::refresh();
        key = ::getch();
        switch(key) {
            case KEY_HOME:      key = HOME;   break;
            case KEY_UP:    key = UP;     break;
            case KEY_DOWN:  key = DOWN;   break;
            case KEY_LEFT:  key = LEFT;   break;
            case KEY_RIGHT: key = RIGHT;  break;
            case KEY_END:   key = END;    break;
            case KEY_NPAGE: key = PGDN;   break;
            case KEY_PPAGE: key = PGUP;   break;
            case KEY_DC:    key = DEL;    break;
            case KEY_IC:    key = INSERT; break;
            case KEY_F(1):  key = F(1);   break;
            case KEY_F(2):  key = F(2);   break;
            case KEY_F(3):  key = F(3);   break;
            case KEY_F(4):  key = F(4);   break;
            case KEY_F(5):  key = F(5);   break;
            case KEY_F(6):  key = F(6);   break;
            case KEY_F(7):  key = F(7);   break;
            case KEY_F(8):  key = F(8);   break;
            case KEY_F(9):  key = F(9);   break;
            case KEY_F(10): key = F(10);  break;
            case KEY_F(11): key = F(11);  break;
            case KEY_F(12): key = F(12);  break;
            case KEY_ENTER: key = ENTER;  break;
            case KEY_BACKSPACE: key = BACKSPACE; break;
            default:
                if (key < 0 || key > '~')
                    key = UNKNOWN;
        }
        return key;
    }

    void BConsole::setPos(int row, int col) {
        curRow = row;
        curCol = col;
        ::move(row, col);
    }

    BConsole& BConsole::putChar(char character) {
        if (curRow >= 0 && curCol >= 0 && curRow < getRows() && curCol < getCols()){
            ::addch(character);
            setBufChar(character);
        }
        return *this;
    }

    void BConsole::alarm() const {
        ::addch(ALARM);
    }

    #elif BIO_PLATFORM == BIO_MICROSOFT

    HANDLE consh;
    CONSOLE_SCREEN_BUFFER_INFO bufinfo;

    BConsole::BConsole() {
        consh = ::GetStdHandle(STD_OUTPUT_HANDLE);
        ::GetConsoleScreenBufferInfo(consh, &bufinfo);
        bufrows = bufinfo.srWindow.Bottom + 1;
        bufcols = bufinfo.srWindow.Right + 1;
        if (bufrows * bufcols > 0) {
            buffer  = new char[bufrows * bufcols];
        }
        else {
            buffer = 0;
        }
        clear();
    }

    BConsole::~BConsole() {
        clear();
        setPos(0, 0);
        delete [] buffer;
    }

    void BConsole::clear() {
        DWORD len = bufrows * bufcols;
        DWORD actual;
        TCHAR ch = ' ';
        COORD coord;
        coord.X = 0;
        coord.Y = 0;
        ::FillConsoleOutputCharacter(consh, ch, len, coord, &actual);
        clearBuffer();
    }

    int BConsole::getKey() const {
        int key = ::_getch();
        #define KEY_ENTER  13
        if (key == 0) {
            key = ::_getch();
            #define KEY_F0     58
            #define KEY_F(n)   (KEY_F0 + (((n) <= 10) ? (n) : ((n) + 64)))
            switch(key) {
                case KEY_F(1):  key = F(1);   break;
                case KEY_F(2):  key = F(2);   break;
                case KEY_F(3):  key = F(3);   break;
                case KEY_F(4):  key = F(4);   break;
                case KEY_F(5):  key = F(5);   break;
                case KEY_F(6):  key = F(6);   break;
                case KEY_F(7):  key = F(7);   break;
                case KEY_F(8):  key = F(8);   break;
                case KEY_F(9):  key = F(9);   break;
                case KEY_F(10): key = F(10);  break;
                default: key = UNKNOWN;
            }
        }
        else if (key == 224) {
            key = ::_getch();
            #define KEY_HOME   71
            #define KEY_UP     72
            #define KEY_DOWN   80
            #define KEY_LEFT   75
            #define KEY_RIGHT  77
            #define KEY_END    79
            #define KEY_NPAGE  81
            #define KEY_PPAGE  73
            #define KEY_DC     83
            #define KEY_IC     82
            #define KEY_ENTER  13
            switch(key) {
                case KEY_HOME:  key = HOME;   break;
                case KEY_UP:    key = UP;     break;
                case KEY_DOWN:  key = DOWN;   break;
                case KEY_LEFT:  key = LEFT;   break;
                case KEY_RIGHT: key = RIGHT;  break;
                case KEY_END:   key = END;    break;
                case KEY_NPAGE: key = PGDN;   break;
                case KEY_PPAGE: key = PGUP;   break;
                case KEY_DC:    key = DEL;    break;
                case KEY_IC:    key = INSERT; break;
                case KEY_F(11): key = F(11);  break;
                case KEY_F(12): key = F(12);  break;
                default: key = UNKNOWN;
            }
        }
        else if (key < 0 || key > '~') {
            key = UNKNOWN;
        }
        else if (key == KEY_ENTER) {
            key = ENTER;
        }
        return key;
    }

    void BConsole::setPos(int row, int col) {
        COORD coord;
        curRow = row;
        curCol = col;
        coord.X = col;
        coord.Y = row;
        ::SetConsoleCursorPosition(consh, coord);
    }

    BConsole& BConsole::putChar(char character) {
        if (curRow >= 0 && curCol >=0 && curRow < getRows() && curCol < getCols()) {
            ::_putch(character);
            setBufChar(character);
        }
        return *this;
    }

    void BConsole::alarm() const {
        ::_putch(ALARM);
    }

    #elif BIO_PLATFORM == BIO_BORLAND

    BConsole::BConsole() {
        struct text_info x;
        ::gettextinfo(&x);
        bufrows = x.screenheight;
        bufcols = x.screenwidth;
        if (bufrows * bufcols > 0) {
            buffer  = new char[bufrows * bufcols];
        }
        else {
            buffer = 0;
        }
        clear();
    }

    BConsole::~BConsole() {
        clear();
        setPos(0, 0);
        delete [] buffer;
    }

    void BConsole::clear() {
        ::clrscr();
        clearBuffer();
    }

    int BConsole::getKey() const {
        int key;
        key = ::getch();
        /* Platform Specific Key Code */
        #define KEY_ENTER  13
        if (key == 0) {
            key = ::getch();
            /* Platform Specific Key Codes */
            #define KEY_HOME   71
            #define KEY_UP     72
            #define KEY_DOWN   80
            #define KEY_LEFT   75
            #define KEY_RIGHT  77
            #define KEY_END    79
            #define KEY_NPAGE  81
            #define KEY_PPAGE  73
            #define KEY_DC     83
            #define KEY_IC     82
            #define KEY_F0     58
            #define KEY_F(n)   (KEY_F0+(((n)<=10)?(n):((n) + 64)))
            switch(key) {
                case KEY_HOME:  key = HOME;   break;
                case KEY_UP:    key = UP;     break;
                case KEY_DOWN:  key = DOWN;   break;
                case KEY_LEFT:  key = LEFT;   break;
                case KEY_RIGHT: key = RIGHT;  break;
                case KEY_END:   key = END;    break;
                case KEY_NPAGE: key = PGDN;   break;
                case KEY_PPAGE: key = PGUP;   break;
                case KEY_DC:    key = DEL; break;
                case KEY_IC:    key = INSERT; break;
                case KEY_F(1):  key = F(1);   break;
                case KEY_F(2):  key = F(2);   break;
                case KEY_F(3):  key = F(3);   break;
                case KEY_F(4):  key = F(4);   break;
                case KEY_F(5):  key = F(5);   break;
                case KEY_F(6):  key = F(6);   break;
                case KEY_F(7):  key = F(7);   break;
                case KEY_F(8):  key = F(8);   break;
                case KEY_F(9):  key = F(9);   break;
                case KEY_F(10): key = F(10);  break;
                case KEY_F(11): key = F(11);  break;
                case KEY_F(12): key = F(12);  break;
                default:
                    key = UNKNOWN;
            }
        } else if (key < 0 || key > '~')
            key = UNKNOWN;
        else if (key == KEY_ENTER)
            key = ENTER;

        return key;
    }

    void BConsole::setPos(int row, int col) {
        curRow = row;
        curCol = col;
        ::gotoxy(col + 1, row + 1);
    }

    BConsole& BConsole::putChar(char character) {
        if (curRow>=0 && curCol >=0 && curRow < getRows() && curCol < getCols()) {
            ::putch(character);
            setBufChar(character);
        }
        return *this;
    }

    void BConsole::alarm() const {
        ::putch(ALARM);
    }

    #endif

    int BConsole::getRows() const {
        return bufrows;
    }

    int BConsole::getCols() const {
        return bufcols;
    }

    void BConsole::getPos(int& row, int& col) const {
        row = curRow;
        col = curCol;
    }

    void BConsole::clearBuffer() {
        for (int i = 0; buffer && i < bufrows * bufcols; i++) {
            buffer[i] = ' ';
        }
        setPos(0, 0);
    }

    void BConsole::pause() const {
        getKey();
    }

    char* BConsole::capture(int row, int col, int height, int width) {
        char* capbuf = new char[height * width];
        int r;
        int c;
        int i = 0;
        if (capbuf) {
            for (r=0;r<height;r++) {
                for (c=0;c<width;c++) {
                    capbuf[i++] = buffer[(row+r)*bufcols+col+c];
                }
            }
        }
        return capbuf;
    }

    void BConsole::restore(int row, int col, int height, int width, char* capbuf){
        int r;
        int c;
        int i = 0;
        if (capbuf) {
            for (r = 0; r < height; r++) {
                for(c = 0; c < width; c++) {
                    setPos(row + r, col + c);
                    putChar(capbuf[i++]);
                }
            }
        }
    }

    void BConsole::setBufChar(char character) {
        if (buffer) {
            buffer[curRow * bufcols + curCol++] = character;
        }
    }

    char BConsole::getBufChar() const {
        return buffer ? buffer[curRow * bufcols + curCol] : ' ';
    }

    BConsole& operator>>(BConsole& is, int& c) {
        c = is.getKey();
        return is;
    }

    BConsole& operator<<(BConsole& is, char c) {
        return is.putChar(c);
    }

    BConsole& operator<<(BConsole& os, const char* str) {
        for (int i = 0; str[i]; i++) {
            os.putChar(str[i]);
        }
        return os;
    }

}