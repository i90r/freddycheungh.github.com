#ifndef CODERPZ_CDIALOG_H
#define CODERPZ_CDIALOG_H

#include "cuigh.h"
#include "cframe.h"

namespace cio {

    class CField;

    class CDialog : public CFrame {
        private:
            bool _dynamic[C_MAX_NO_FIELDS];
            bool _editable;
            int _fieldNum;
            int _current;
            CField* _fields[C_MAX_NO_FIELDS];
        public:
            CDialog(CFrame* = (CFrame*) 0, int = -1, int = -1, int = -1, int = -1, bool = false, const char* = C_BORDER_CHARS);
            virtual ~CDialog();
            int add(CField*, bool = true);
            int add(CField&, bool = false);
            int curIndex() const;
            void draw(int = C_FULL_FRAME);
            int edit(int = C_FULL_FRAME);
            bool editable();
            int fieldNum() const;
            CField& curField();

            CDialog& operator<<(CField*);
            CDialog& operator<<(CField&);
            CField& operator[](unsigned int);
    };

}

#endif