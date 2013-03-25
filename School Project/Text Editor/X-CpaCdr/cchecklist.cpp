#include "bconsole.h"
#include "cchecklist.h"
#include "ccheckmark.h"
#include "cfield.h"
#include "console.h"

using bio::strcpy;
using bio::strlen;

namespace cio {

    CCheckList::CCheckList(const char* format, int row, int col, int width, bool radio, bool bordered, const char* border) : CField(row, col, width, 0, (void*)0, bordered, border) {
        _data = &_flags;
        strcpy(_format, format);
        _count = 0;
        _current = 0;
        _flags = 0;
    }

    CCheckList::~CCheckList() {
        for (int i = 0; i < _count; i++) {
            delete _checkmarks[i];
        }
    }

    CCheckList& CCheckList::add(const char* text, bool selected) {
        if (_count < 32) {
            _checkmarks[_count] = new CCheckMark(selected, _format, text, _count + 1, 1, strlen(text) + 4);
            _checkmarks[_count]->frame(this);
            if (_checkmarks[_count]->width() + 2 > this->width()) {
                this->width(_checkmarks[_count]->width() + 2);
            }
            this->height(_count + 3);
            selectedIndex(_count);
            _count++;
        }
        return *this;
    }
    
    CCheckList& CCheckList::operator<<(const char* text) {
        return add(text);
    }
    
    void CCheckList::draw(int frame) {
        CField::draw(frame);
        for (int i = 0; i < _count; i++) {
            _checkmarks[i]->draw();
        }
        if (_flags == 0) {
            console.setPos(absRow() + 1, absCol() + 2);
        }
        else {
            for (int i = 0; i < 32; i++) {
                if (_flags & (1 << i)) {
                    console.setPos(absRow() + i, absCol() + 2);
                    break;
                }
            }
        }
    }
    
    int CCheckList::edit() {
        int key;
        while (key = _checkmarks[_current]->edit()) {
            if (key == DOWN || key == RIGHT) {
                if (_current >= _count - 1) {
                    break;
                }
                else {
                    _current ++;
                }
            }
            else if (key == UP || key == LEFT) {
                if(_current == 0) {
                    break;
                }
                else{
                    _current--;
                }
            }
            else if (key == SPACE) {
                selectedIndex(_current);
                draw();
            }
            else {
                break;
            }
        }
        return key;
    }

    void* CCheckList::data() {
        return &_flags;
    }
    
    void CCheckList::set(const void* data) {
        _flags = *(int*)data;
        for (int i = 0; i < _count; i++) {
            _checkmarks[i]->checked((_flags >> i) % 2 == 1);
        }
    }
    
    CCheckMark& CCheckList::operator[](unsigned int index) {
        return *_checkmarks[index];
    }
    
    bool CCheckList::editable() const {
        return true;
    }
    
    bool CCheckList::radio() const {
        return _radio;
    }
    
    void CCheckList::radio(bool val) {
        _radio = val;
    }
    
    unsigned int CCheckList::flags() const {
        return _flags;
    }
    
    void CCheckList::flags(unsigned int flags) {
        _flags = flags;
    }
    
    int CCheckList::selectedIndex() const {
        int toReturn = -1;
        for (int i = 0; i < 32; i++) {
            if (_checkmarks[i]->checked()) {
                toReturn = i;
                break;
            }
        }
        return toReturn;
    }
    
    void CCheckList::selectedIndex(int index) {
        if (index < 0 || _radio) {
            _flags = 0;
            for (int i = 0; i < _count; i++) {
                _checkmarks[i]->checked(false);
            }
            _flags = 1 << index;
            set(&_flags);
        }
        else if (index < 32)  {
            _flags |= 1 << index;
            set(&_flags);
        }
    }
    
    unsigned int CCheckList::length() {
        return _count;
    }

}