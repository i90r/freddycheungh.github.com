#ifndef CODERPZ_CVALEDIT_H
#define CODERPZ_CVALEDIT_H

#include "clineedit.h"

namespace cio {

    class CValEdit : public CLineEdit {
        private:
            void (*_help)(MessageStatus, CDialog&);
            bool (*_validate)(const char*, CDialog&);
        public:
            CValEdit(int, int, int, int, bool*, bool (*)(const char*, CDialog&) = NO_VALDFUNC, void (*)(MessageStatus, CDialog&) = NO_HELPFUNC, bool = false, const char* = C_BORDER_CHARS);
            CValEdit(char*, int, int, int, int, bool*, bool (*)(const char* , CDialog&) = NO_VALDFUNC, void (*)(MessageStatus, CDialog&) = NO_HELPFUNC, bool = false, const char* = C_BORDER_CHARS);
            int edit();
    };

}

#endif
