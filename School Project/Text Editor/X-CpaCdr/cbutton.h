#ifndef CODERPZ_CBUTTON_H
#define CODERPZ_CBUTTON_H

#include "bconsole.h"
#include "cfield.h"
#include "console.h"

namespace cio {

    class  CButton : public CField {
        public:
            CButton(const char*, int, int, bool = true, const char* = C_BORDER_CHARS);
            virtual ~CButton();
            void draw(int = C_FULL_FRAME);
            int edit();
            bool editable() const;
            void set(const void*);
            void visible(bool);
            bool visible() const;
    };

}

#endif
