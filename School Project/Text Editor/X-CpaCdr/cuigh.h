#ifndef CODERPZ_CUIGH_H
#define CODERPZ_CUIGH_H

namespace cio {

    #ifndef _CRT_SECURE_NO_DEPRECATE
    #define _CRT_SECURE_NO_DEPRECATE
    #endif

    #ifndef _CRT_SECURE_NO_WARNINGS
    #define _CRT_SECURE_NO_WARNINGS
    #endif
 
    #define C_BORDER_CHARS "/-\\|/-\\|"
    #define C_BUTTON_HIT 1
    #define C_FULL_FRAME -1
    #define C_INITIAL_NUM_OF_LINES (100u)
    #define C_MAX_NO_FIELDS 500
    #define C_MAX_LINE_CHARS (1024u)
    #define C_NO_FRAME 0
    #define C_REFRESH -2

    enum CDirection {centre, left, right, up, down};
    enum MessageStatus{ClearMessage,SetMessage};

    #ifdef NO_HELPFUNC
    #undef NO_HELPFUNC
    #endif
    #define NO_HELPFUNC ((void(*)(MessageStatus, CDialog&))(0))

    #ifdef NO_VALDFUNC
    #undef NO_VALDFUNC
    #endif
    #define NO_VALDFUNC ((bool(*)(const char*, CDialog&))(0))

}

#endif

