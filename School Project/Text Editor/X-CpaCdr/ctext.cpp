#include "console.h"
#include "ctext.h"

namespace cio {

    CText::CText(int row, int col, int width, int height, bool* insertMode, bool displayOnly, const char* border) : CField(row, col, width, height, (void*)0, true, border) {
        _displayOnly = displayOnly;
        _insertMode = insertMode;
        _curpos = 0;
        _offset = 0;
        _lcurpos = 0;
        _loffset = 0;
    }

    CText::CText(const char* str, int row, int col, int width, int height, bool* insertMode, bool displayOnly, const char* border) : CField(row, col, width, height, (void*)0, true, border) {
        set(str);
        _displayOnly = displayOnly;
        _insertMode = insertMode;
        _curpos = 0;
        _offset = 0;
        _lcurpos = 0;
        _loffset = 0;
    }

    CText::~CText() {
        delete _insertMode;
    }

    void CText::draw(int frame) {
        CField::draw(frame);
        for (int i = 0; i < height() - 2; i++) {
            if (_T[i + _loffset].strlen() > _offset) {
                console.display(&_T[i + _loffset][_offset], absRow() + i + 1, absCol() + 1, width() - 2);
            }
        }
    }
 
    void CText::set(const void* str) {
        _T = (char*)str;
    }
  
    void* CText::data() const {
        return (void*)_T.exportString();
    }
 
    int CText::edit() {
        bool done = false;
        int key = 0;
        int tempCurpos = _curpos;
        int tempLineCurpos = _lcurpos;
        int tempLineOffset = _loffset;
        int tempOffset = _offset;
        Text tempText(_T);
        draw();
        while (!done) {
            key = console.edit((char*)_T[_loffset + _lcurpos], absRow() + _lcurpos + 1, absCol() + 1, width() - 2, _T[_lcurpos].size(), _insertMode, &_offset, &_curpos, true, _displayOnly);
            if (key == UP) {
                if (_lcurpos) {
                    _lcurpos--;
                }
                else if (_loffset) {
                    _loffset--;
                    draw();
                }
            }
            else if (key == DOWN) {
                if (_lcurpos + _loffset < _T.size()) {
                    if (_lcurpos + 1 < height() - 2) {
                        _lcurpos++;
                    }
                    else if (_loffset + _lcurpos < _T.size()) {
                        _loffset++;
                        draw();
                    }
                }
            }
            else if (key == ESCAPE) {
                done = true;
            }
            else if (key == ENTER) {
                _T.insertAndBreakAt(_lcurpos + _loffset + 1, _offset + _curpos + 1);
                if (_lcurpos + _loffset < _T.size()) {
                    if (_lcurpos + 1 < height() - 2) {
                        _lcurpos++;
                    }
                    else if (_loffset + _lcurpos < _T.size()) {
                        _loffset++;
                        draw();
                    }
                }
                _offset = _curpos = 0;
                draw();
            }
            else if (key == PGDN) {
                if(_loffset < _T.textLines()){
                    _loffset += height();
                }
                draw();
            }
            else if (key == PGUP) {
                if(_loffset > 0){
                    _loffset -= height();
                }
                draw();
            }
            else if (key == 0) {
                draw();
            }
            else {
                done = true;
                draw();
            }
        }
        if (key == ESCAPE) {
            _curpos = tempCurpos;
            _lcurpos = tempLineCurpos;
            _loffset = tempLineOffset;
            _offset = tempOffset;
            _T = tempText;
        }
        draw();
        return key;
        return 0;
    }
  
    bool CText::editable() const {
        return true;
    }

    bool CText::displayOnly() {
        return _displayOnly;
    }

    void CText::displayOnly(bool val) {
        _displayOnly = val;
    }

}