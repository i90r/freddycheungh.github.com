#ifndef CODERPZ_CTEXT_H
#define CODERPZ_CTEXT_H

#include "cfield.h"
#include "text.h"
 
namespace cio {
 
    class CText : public CField {
        private:
            Text _T;
            bool _displayOnly;
            bool* _insertMode;
            int _curpos;
             int _lcurpos;
            int _offset;
            int _loffset;
        public:
            CText(int, int, int, int, bool*, bool = false, const char* = C_BORDER_CHARS);
            CText(const char*, int, int, int, int, bool*, bool = false, const char* = C_BORDER_CHARS);
            virtual ~CText();
            void draw(int = C_FULL_FRAME);
            void set(const void *Str);
            void* data() const;
            int edit();
            bool editable() const;
            bool displayOnly();
            void displayOnly(bool);
    };

}

#endif