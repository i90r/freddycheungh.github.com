#include <cstring>
#include <ctype.h>
#include "bconsole.h"
#include "ccheckmark.h"
#include "console.h"

namespace cio {

    using bio::strcpy;

    CCheckMark::CCheckMark(bool checked, const char* format, const char* text, int row, int col, int width, bool isRadio) : CField(row, col, width, 1), _label(text, 0, 4, (width - 4)) {
        _label.frame(this);
        _flag = checked;
        _radio = isRadio;
        strcpy(_format, format);
        _data = &_flag;
    }

    CCheckMark::CCheckMark(const CCheckMark& reference) : CField(reference.row(), reference.col(), reference.width(), 1), _label((char*)reference._data, 0, 4, (reference.width() - 4)) {
        _label.frame(this);
        _flag = reference._flag;
        _radio = reference._radio;
        strcpy(_format, reference._format);
        _data = &_flag;
    }

    CCheckMark::~CCheckMark() {
    }

    void CCheckMark::draw(int frame) {
        console.display(_format, absRow(), absCol());
        if (!_flag) {
            console.display(" ", absRow(), absCol() + 1, 1);
        }
       _label.draw();
        console.setPos(absRow(), absCol() + 1); 
    }

    int CCheckMark::edit() {
        int key;
        draw();
        while (key = console.getKey()) {
            if (key == SPACE) {
                if (_radio) {
                    _flag = true;
                }
                else {
                    _flag = !_flag;
                }
                draw();
                break;
            }
            else if (key > 255 || isprint((unsigned char)key) == 0) {
                break;
            }
        }
        return key;
    }

    bool CCheckMark::editable() const {
        return true;
    }

    void CCheckMark::set(const void* flag) {
        _flag = *(bool*) flag;
    }

    bool CCheckMark::checked() const {
        return _flag;
    }

    void CCheckMark::checked(bool val) {
        _flag = val;
    }

    bool CCheckMark::radio() {
        return _radio;
    }

    void CCheckMark::radio(bool isRadio) {
        _radio = isRadio;
    }

    CCheckMark::operator bool() {
        return _flag;
    }

    CCheckMark::operator char*() {
        return (char*) _label.data();
    }

    bool CCheckMark::operator=(bool flag) {
        _flag = flag;
        return flag;
    }
}
