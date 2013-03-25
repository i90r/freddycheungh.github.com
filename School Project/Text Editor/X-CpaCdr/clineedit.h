#ifndef CODERPZ_CLINEEDIT_H
#define CODERPZ_CLINEEDIT_H

#include "cfield.h"

namespace cio {

    class CLineEdit : public CField {
        private:
            bool _dyn;
            bool* _insertmode;
            int _curpos;
            int _offset;
            int _maxdatalen;
        public:
            CLineEdit(char*, int, int, int, int, bool*, bool = false, const char* = C_BORDER_CHARS);
            CLineEdit(int, int, int, int, bool*, bool = false, const char* = C_BORDER_CHARS);
            virtual ~CLineEdit();
            void draw(int = C_FULL_FRAME);
            int edit();
            bool editable() const;
            void set(const void*);
    };

}

#endif