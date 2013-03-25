#ifndef CODERPZ_CCHECKLIST_H
#define CODERPZ_CCHECKLIST_H

#include "ccheckmark.h"
#include "cfield.h"

namespace cio {
 
    class CCheckList : public CField {
        private:
            CCheckMark* _checkmarks[32];
            bool _radio;
            char _format[4];
            unsigned int _flags;
            unsigned int _count;
            unsigned int _current;
        public:
            CCheckList(const char*, int, int, int, bool, bool = true, const char* = C_BORDER_CHARS);
            virtual ~CCheckList(void);
            CCheckList& add(const char*, bool = false);
            CCheckList& operator<<(const char*);
            void draw(int = C_FULL_FRAME);
            int edit();
            void* data();
            void set(const void*);
            CCheckMark& operator[](unsigned int);
            bool editable() const;
            bool radio() const;
            void radio(bool);
            unsigned int flags() const;
            void flags(unsigned int);
            int selectedIndex() const;
            void selectedIndex(int);
            unsigned int length();
    };

}

#endif