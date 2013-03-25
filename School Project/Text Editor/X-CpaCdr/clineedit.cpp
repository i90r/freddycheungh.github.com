#include "bconsole.h"
#include "clineedit.h"
#include "console.h"

namespace cio {

    using bio::strcpy;
    using bio::strncpy;

    CLineEdit::CLineEdit(char* str, int row, int col, int width, int maxDataLen, bool* insertMode, bool bordered, const char* border) : CField(row, col, width, (bordered ? 3 : 1), str, bordered, border) {
        _dyn = false;
        _maxdatalen = maxDataLen;
        _insertmode = insertMode;
        _curpos = 0;
        _offset = 0;
        _data = new char[_maxdatalen + 1];
        set("");
    }

    CLineEdit::CLineEdit(int row, int col, int width, int maxDataLen, bool* insertMode, bool bordered, const char* border) : CField(row, col, width, (bordered ? 3 : 1), (void*)0, bordered, border) {
        _dyn = true;
        _maxdatalen = maxDataLen;
        _insertmode = insertMode;
        _curpos = 0;
        _offset = 0;        
        _data = new char[_maxdatalen + 1];
        set("");
    }

    CLineEdit::~CLineEdit() {
        delete [] _data;
    }

    void CLineEdit::draw(int refresh) {
        CFrame::draw(refresh);
        console.display((char*)_data+_offset, (visible() ? absRow() + 1 : absRow()), (visible() ? absCol() + 1 :  absCol()), (visible() ? width() - 2 : width()));
    }

    int CLineEdit::edit() {
        return console.edit((char*)_data, (visible() ? absRow() + 1 : absRow()), (visible() ? absCol() + 1 :  absCol()), (visible() ? width() - 2 : width()), _maxdatalen - 1, _insertmode, &_offset, &_curpos);
    }

    bool CLineEdit::editable() const {
        return true;
    }

    void  CLineEdit::set(const void* str) {
        bio::strcpy(_data, str);
    }

}
