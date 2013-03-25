#ifndef CODERPZ_CLABEL_H
#define CODERPZ_CLABEL_H

#include "cfield.h"

namespace cio {

    class CLabel : public CField {
        public:
            CLabel(const CLabel&);
            CLabel(const char*, int, int, int = 0);
            CLabel(int, int, int);
            virtual ~CLabel();
            void draw(int = C_NO_FRAME);
            int edit();
            bool editable() const;
            void set(const void*);
    };

}

#endif
