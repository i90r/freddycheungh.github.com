#include "bconsole.h"
#include "clabel.h"
#include "cmenuitem.h"
#include "console.h"
#include <ctype.h>
#include <cstring>

using bio::strcpy;

namespace cio{

    CMenuItem::CMenuItem(bool selected, const char* format, const char* text, int row, int col, int width) : CField(row, col, width, 1),_label(text, 0, 1, width - 2) {
        _selected = selected;
        strcpy(_format, format);
        _data = &_format;
        _label.frame(this);
    }

    CMenuItem::CMenuItem(const CMenuItem& menuItem) : CField(menuItem.row(), menuItem.col(), menuItem.width(), 1), _label(menuItem._label) {
        strcpy(_format, menuItem._format);
        _selected = menuItem._selected;
        _data = &_format;
        _label.frame(this);
    }

    CMenuItem::~CMenuItem() {
    }

    void CMenuItem::draw(int frame) {
        _label.draw(frame);
        if (_selected) {
            console.display(&_format[0], absRow(), absCol(), 1);
            console.display(&_format[1], absRow(), absCol() + width() - 1, 1);
        }
        else {
            console.display(" ", absRow(), absCol(), 1);
            console.display(" ", absRow(), absCol() + width() - 1, 1);
        }
        console.setPos(absRow(), absCol() + 1); 
    }

    int CMenuItem::edit() {
        int key;
        draw();
        while (key = console.getKey()) {
            if (key == SPACE) {
                _selected = true;
                draw();
                break;
            }
            else if (key > 255 || isprint((unsigned char)key) == 0) {
                break;
            }
        }
        return key;
    }

    bool CMenuItem::editable() const {
        return true;
    }

    bool CMenuItem::selected() const {
        return _selected;
    }

    void CMenuItem::selected(bool value) {
        _selected = value;
    }

    void CMenuItem::set(const void* selected) {
        _selected = *(bool*)selected;
    }

    const char* CMenuItem::Text() {
        return (char*)_label.data();
    }

}