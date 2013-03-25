#include "bconsole.h"
#include "cvaledit.h"

using namespace bio;

namespace cio {

    CValEdit::CValEdit(int row, int col, int width, int maxDataLen, bool* insertMode, bool (*validate)(const char* , CDialog&), void (*help)(MessageStatus, CDialog&), bool bordered, const char* border) : CLineEdit(row, col, width, maxDataLen, insertMode, bordered, border) {
        _help = help;
        _validate = validate;
    }

    CValEdit::CValEdit(char* str, int row, int col, int width, int maxDataLen, bool* insertMode, bool (*validate)(const char* , CDialog&), void (*help)(MessageStatus, CDialog&), bool bordered, const char* border) : CLineEdit(str, row, col, width, maxDataLen, insertMode, bordered, border) {
        _help = help;
        _validate = validate;
    }

    int CValEdit::edit() {
        int key;
        if (!container()) {
            key = CLineEdit::edit();
        }
        else {
            if (_help) {
                _help(MessageStatus::SetMessage, *container());
            }
            key = CLineEdit::edit();
            if (_validate) {
                while (!_validate((const char*) _data, *container())) {
                    if (key == UP || key == DOWN || key == TAB || key == ENTER) {
                        key = CLineEdit::edit();
                    }
                    else {
                        break;
                    }
                }
            }
            if (_help) {
                _help(MessageStatus::ClearMessage, *container());
            }
        }
        return key;
    }

}