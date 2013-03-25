#include <cstring>
#include "bconsole.h"
#include "clabel.h"
#include "console.h"

namespace cio {

    using bio::strcpy;
    using bio::strncpy;
    using bio::strlen;

    CLabel::CLabel(const CLabel& label) : CField(label.row(), label.col(), label.width()) {
        _data = new char[strlen(label._data)+1];
        for (int i = 0, c = width(); i <= c; i++) {
            ((char*)_data)[i] = 0;
        }
        strncpy(_data, label._data, strlen(label._data));
    }

    CLabel::CLabel(const char* str, int row, int col, int len) : CField(row, col, len) {
        if (len <= 0) {
            _data = new char[strlen(str) + 1];
            for (int i = 0, c = width(); i <= c; i++) {
                ((char*)_data)[i] = 0;
            }
            strcpy(_data, str);
        }
        else {
            _data = new char[len + 1];
            for (int i = 0, c = width(); i <= c; i++) {
                ((char*)_data)[i] = 0;
            }
            strncpy(_data, str, len);
        }
    }

    CLabel::CLabel(int row, int col, int len) : CField(row, col, len) {
        _data = new char[len + 1];
        for (int i = 0, c = width(); i <= c; i++) {
            ((char*)_data)[i] = 0;
        }
    }

    CLabel::~CLabel() {
        delete [] _data;
    }

    void CLabel::draw(int frame) {
        console.display((char*)_data, absRow(), absCol(), width());
    }

    int CLabel::edit() {
        draw();
        return 0;
    }

    bool CLabel::editable() const {
        return false;
    }

    void CLabel::set(const void* str) {
        delete [] _data;
        if (width() > 0) {
            _data = new char[width() + 1];
            strcpy(_data, str);
        }
        else if (width() == 0) {
            delete _data;
            _data = new char[strlen(str) + 1];
            strcpy(_data, str);
        }
    }

}
