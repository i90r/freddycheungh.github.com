#ifndef CODERPZ_CCHECKMARK_H
#define CODERPZ_CCHECKMARK_H

#include "cfield.h"
#include "clabel.h"

namespace cio {

    class CCheckMark : public CField {
        private:
            bool _flag;
            bool _radio;
            char _format[4];
            CLabel _label;
        public:
            CCheckMark(bool, const char*, const char*, int, int, int, bool = false);
            CCheckMark(const CCheckMark&);
            virtual ~CCheckMark();
            void draw(int = C_NO_FRAME);
            int edit();
            bool editable() const;
            void set(const void*);
            bool checked() const;
            void checked(bool);
            bool radio();
            void radio(bool);
            operator bool();
            operator char*();
            bool operator=(bool);
    };

}

#endif
