#ifndef _FS_CONSOLE_H_
#define _FS_CONSOLE_H_

// Console Input Output Library - C++ Module
// console.h
//
// Fardad Soleimanloo, Chris Szalwinski
// Jan 12 2012
// Version 1.0
// to be done by students
#include "bconsole.h"



namespace cio {

    // Console holds the state of the Console Input Output Facility
    class Console : public bio::BConsole {
        unsigned int&  tabsize;       // tab size
    public:
        Console();
        void display(const char *str, int row, int col, int fieldLen=0);
        int  edit(char *str, int row, int col, int fieldLength, int maxStrLength, 
         bool* insertMode, int* strOffset, int* curPosition,  
         bool IsTextEditor = false, bool ReadOnly = false);
    };

    Console& operator>>(Console&, int&);
    Console& operator<<(Console&, char);
    Console& operator<<(Console&, const char*);

    extern Console console; // console object - external linkage
    extern unsigned int CIO_TABSIZE;
} // end namespace cio 
#endif