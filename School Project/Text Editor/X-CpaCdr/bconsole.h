#ifndef CODERPZ_BCONSOLE_H
#define CODERPZ_BCONSOLE_H

// BConsole Input Output Library - C++ Module
// conbio.h
//
// Fardad Soleimanloo, Chris Szalwinski
// Jan 12 2012
// Version 1.0

namespace bio {

    #define TAB       '\t'
    #define BACKSPACE '\b'
    #define ALARM     '\a'
    #define ESCAPE    27
    #define ENTER     '\n'
    #define SPACE     ' '
    #define HOME      1000
    #define UP        1001
    #define DOWN      1002
    #define LEFT      1003
    #define RIGHT     1004
    #define END       1005
    #define PGDN      1006
    #define PGUP      1007
    #define DEL       1008
    #define INSERT    1009
    #define F(n)      (1009+(n))
    #define UNKNOWN   9999

    class BConsole {
        private:
            char* buffer;
            int bufcols;
            int bufrows;
            int curCol;
            int curRow;
            BConsole(const BConsole&);
            void clearBuffer();
            void setBufChar(char);
            char getBufChar() const;
            BConsole& operator=(const BConsole&);
        public:
            BConsole();
            virtual ~BConsole();
            void alarm() const;
            char* capture(int, int, int, int);
            void clear();
            int getCols() const;
            int getKey() const;
            void getPos(int&, int&) const;
            int getRows() const;
            void pause() const;
            BConsole& putChar(char);
            void restore(int, int, int, int, char*);
            void setPos(int, int);
    };

    unsigned int strlen(const void*);
    char* strcpy(void*, const void*);
    char* strncpy(void*, const void*, unsigned int);

}

#endif