#ifndef CODERPZ_CFIELD_H
#define CODERPZ_CFIELD_H

#include "cframe.h"

namespace cio {

    class CDialog;

    class CField : public CFrame {
        protected:
            void* _data;
        public:
            CField(int = 0, int = 0, int = 0, int = 0, void* = (void*) 0, bool = false, const char* = C_BORDER_CHARS);
            virtual ~CField();
            void container(CDialog*);
            virtual void* data();
            virtual int edit() = 0;
            virtual bool editable() const = 0;
            virtual void set(const void*) = 0;
            CDialog* container();
    };

}

#endif
