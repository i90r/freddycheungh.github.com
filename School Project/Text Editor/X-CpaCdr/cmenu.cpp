#include "cmenu.h"
#include "bconsole.h"

namespace cio {

    using bio::strcpy;

    MNode::MNode(CMenuItem* item, unsigned int index, MNode* previous, MNode* next) {
        _item = item;
        _index = index;
        _previous = previous;
        _next = next;
    }

    MNode::~MNode() {
    }

    bool CMenu::goNext() {
        if (_cur->_next == (MNode*)0) {
            return false;
        }
        else {
            _cur = _cur->_next;
            return true;
        }
    }

    bool CMenu::goPrev() {
        if (_cur->_previous == (MNode*)0) {
            return false;
        }
        else {
            _cur = _cur->_previous;
            return true;
        }
    }

    CMenu::CMenu(const char* title, const char* format, int row, int col, int width, int height, bool dropdown, const char* border) : CField((!dropdown ? row : row + 1), col, width, height, (void*)0, true, border), _title(title, -1, 1, false) {
        strcpy(_format, format);
        _count = 0;
        _selectedIndex = -1;
        _data = &_selectedIndex;
        _dropdown = dropdown;
        _dropped = false;
        _title.frame(this);
        _head = _tail = _cur = _first = (MNode*)0;
    }

    CMenu::~CMenu() {
        while (_head != _tail) {
            _tail = _tail->_previous;
            delete _tail->_next;
            if (_tail == _head) {
                delete _tail;
                break;
            }
        }
    }

    CMenu& CMenu::add(const char* text, bool selected) {
        CMenuItem* newMenuItem = new CMenuItem(selected, _format, text, 1, 1, width() - 2);
        newMenuItem->frame(this);
        if (_tail) {
            MNode* newNode = new MNode(newMenuItem, _tail->_index + 1, _tail);
            _tail->_next = newNode;
            _tail = newNode;
        }
        else {
            _head = _tail = new MNode(newMenuItem, 0, (MNode*)0);
            _first = _cur = _head;
        }
        if (selected) {
            selectedIndex(_tail->_index);
        }
        _count++;
        return *this;
    }

    void CMenu::draw(int frame) {
        if (_dropdown)
            _title.draw();
        if (_dropped || !_dropdown) {
            CField::draw();
            MNode* temp = _first;
            for (int i = 0; i < height() - 2; i++) {
                temp->_item->row(i + 1);
                temp->_item->draw();
                temp = temp->_next;
            }
        }
    }

    int CMenu::edit() {
        bool over = false;
        bool browse = true;
        int key;
        while (!over) {
            draw();
            if (_dropdown && !_dropped) {
                key = _title.edit();
                refresh();
                if (key == C_BUTTON_HIT) {
                    _dropped = true;
                }
                else {
                    if (key == LEFT) {
                        key = UP;
                    }
                    if (key == RIGHT) {
                        key = down;
                    }
                    browse = false;
                }
            }
            over = true;
            while (browse) {
                draw();
                key = _cur->_item->edit();
                if (key == ENTER) {
                    if (_selectedIndex > -1) {
                        key = SPACE;
                    }
                    browse = false;
                }
                if (key == SPACE) {
                    selectedIndex(_cur->_index);
                    browse = false;
                }
                if (key == DOWN) {
                    if (!goNext()) {
                        if (_dropdown) {
                            _first = _cur = _head;
                        }
                        else {
                            browse = false;
                        }
                    }
                    else {
                        if (_cur->_index - _first->_index >= height() - 2) {
                            _first = _first->_next;
                        }
                    }
                }
                if (key == UP) {
                    if (!goPrev()) {
                        if (_dropdown) {
                            _cur = _first = _tail;
                            for (int i = 0; i < height() - 3; i++) {
                                _first = _first->_previous;
                            }
                        }
                        else {
                            browse = false;
                        }
                    }
                    else {
                        if (_cur->_next == _first) {
                            _first = _first->_previous;
                        }
                    }
                }
                if (key == ESCAPE) {
                    _dropped = false;
                    browse = false;
                    over = false;
                }
                if (key == RIGHT || key == LEFT || key == TAB || (key >= 32 && key <= 127)) {
                    browse = false;
                }
            }
            draw();
        }
        if (_dropdown) {
            _dropped = false;
            CFrame::hide();
        }
        return key;
    }

    bool CMenu::editable() const {
        return (_count > 0 ? true : false);
    }

    void CMenu::set(const void* data) {
        selectedIndex(*(int*)data);
    }

    int CMenu::selectedIndex() const {
        return _selectedIndex;
    }

    int CMenu::selectedIndex(int index) {
        MNode* temp = _head;
        do {
            if (temp->_index == index) {
                temp->_item->selected(true);
                _cur = temp;
            }
            else {
                temp->_item->selected(false);
            }
            if (temp->_next) {
                temp = temp->_next;
            }
            else {
                break;
            }
        } while (true);
        _selectedIndex = index;
        return _selectedIndex;
    }

    const char* CMenu::selectedText() {
        if (_selectedIndex < 0) {
            return 0;
        }
        else {
            MNode* temp = _head;
            do {
                if (temp->_item->selected()) {
                    return temp->_item->Text();
                }
                if (temp->_next) {
                    temp = temp->_next;
                }
                else {
                    break;
                }
            } while(true);
            return 0;
        }
    }

    CMenu& CMenu::operator<<(const char* text) {
        return add(text);
    }

    CMenu& CMenu::operator<<(bool select) {
        if (select) {
            selectedIndex(_tail->_index);
        }
        return *this;
    }

}
