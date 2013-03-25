#include "cbutton.h"

namespace cio {

    using bio::strcpy;
    using bio::strlen;

    CButton::CButton(const char* str, int row, int col, bool bordered, const char* border) : CField(row, col, (bordered ? bio::strlen(str) + 4 : bio::strlen(str) + 2), (bordered ? 3 : 1), (void*)0, bordered, border) {
        _data = new char[strlen(str) + 1];
        bio::strcpy(_data, str);
    }

    CButton::~CButton() {
        delete [] _data;
    }

    void CButton::draw(int frame) {
        CFrame::draw(frame);
        console.display((char*)_data, (visible() ? absRow() + 1 : absRow()), (visible() ? absCol() + 2 : absCol() + 1));
    }

    int CButton::edit() {
        int key;
        refresh();
        draw();
        console.display("]", (visible() ? absRow() + 1 : absRow()), (visible() ? absCol() + width() - 2 : absCol() + width() - 1));
        console.display("[", (visible() ? absRow() + 1 : absRow()), (visible() ? absCol() + 1 : absCol()));
        console >> key;
        if (key == ENTER || key == SPACE) {
            return C_BUTTON_HIT;
        }
        else {
            return key;
        }
    }

    bool CButton::editable() const {
        return true;
    }

    void CButton::set(const void* str) {
        delete [] _data;
        _data = new char[strlen(str) + 1];
        bio::strcpy(_data, str);
    }

    void CButton::visible(bool visible) {
        CFrame::visible(visible);
        width(bio::strlen(_data) + (visible ? 4 : 2));
        height(visible ? 3 : 1);
    }

    bool CButton::visible() const {
        return CFrame::visible();
    }

}
