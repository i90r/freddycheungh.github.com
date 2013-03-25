#include "bconsole.h"
#include "cdialog.h"
#include "cfield.h"
#include "console.h"

using namespace bio;

namespace cio {

    CDialog::CDialog(CFrame* container, int row, int col, int width, int height, bool borderd, const char* border) : CFrame(row, col, width, height, borderd, border, container) {
        _current = -1;
        _editable = false;
        _fieldNum = 0;
        for (int i = 0; i < C_MAX_NO_FIELDS; i++) {
            _dynamic[i] = false;
            _fields[i] = (CField*) 0;
        }
    }

    CDialog::~CDialog() {
        for (int i = 0; i < _fieldNum; i++) {
            if (_dynamic[i]) {
                delete _fields[i];
            }
        }
    }

    int CDialog::add(CField* field, bool dynamic) {
        if (_fieldNum < C_MAX_NO_FIELDS) {
            if (field->editable()) {
                _editable = true;
            }
            _fields[_fieldNum] = field;
            _dynamic[_fieldNum] = dynamic;
            _fields[_fieldNum]->container(this);
            return _fieldNum++;
        }
        return _fieldNum;
    }

    int CDialog::add(CField& field, bool dynamic) {
        return add(&field, dynamic);
    }

    int CDialog::curIndex() const {
        return _current;
    }

    void CDialog::draw(int field) {
        if (field = C_FULL_FRAME) {
            CFrame::draw(field);
            for (int i = 0; i < _fieldNum; i++) {
                _fields[i]->draw();
            }
        }
        else if (field != C_FULL_FRAME) {
            if (field > 0) {
                _fields[field - 1]->draw();
            }
            else {
                for (int i = 0; i < _fieldNum; i++) {
                    _fields[i]->draw();
                }
            }
        }
    }

    int CDialog::edit(int field) {
        if (!_editable) {
            draw();
            return console.getKey();
        }
        else {
            if (field < 1) {
                draw(field);
            }
            int key = 0;
            bool flag = true;
            for (int i = (field < 1 ? 0 : field - 1); i <= _fieldNum && i >= -1; i += flag ? 1 : -1) {
                if (i == -1) {
                    i = _fieldNum - 1;
                }
                if (i == _fieldNum) {
                    i = 0;
                }
                if (_fields[i]->editable()) {
                    _current = i;
                    key = _fields[i]->edit();
                    if (key == ENTER || key == TAB || key == DOWN) {
                        flag = true;
                    }
                    else if (key == UP) {
                        flag = false;
                    }
                    else {
                        break;
                    }
                }
            }
            return key;
        }
    }

    bool CDialog::editable() {
        return _editable;
    }

    int CDialog::fieldNum() const {
        return _fieldNum;
    }

    CField& CDialog::curField() {
        return *_fields[_current];
    }

    CDialog& CDialog::operator<<(CField* field) {
        add(field);
        return *this;
    }

    CDialog& CDialog::operator<<(CField& field) {
        add(field);
        return *this;
    }

    CField& CDialog::operator[](unsigned int index) {
        return *_fields[index];
    }

}
