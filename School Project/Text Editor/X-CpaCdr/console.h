#ifndef CODERPZ_CONSOLE_H
#define CODERPZ_CONSOLE_H

#include "bconsole.h"

using bio::BConsole;

namespace cio {

    class Console : public BConsole {
        private:
            void _insert(char*, int, int, int, int*, int*, bool);
        public:
            Console();
            void display(const char*, int, int, int = 0); 
            int edit(char*, int, int, int, int, bool*, int*, int*, bool = false, bool = false);
    };

    Console& operator>>(Console&, int&);
    Console& operator<<(Console&, char);
    Console& operator<<(Console&, const char*);

    extern unsigned int CIO_TABSIZE;
    extern Console console;

}

#endif
