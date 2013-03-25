// Console UI Core Classes
// cframe.cpp
//
// Fardad Soleimanloo, Chris Szalwinski
// Feb 12 2012
// Version 1.0

#include "cframe.h"
#include "console.h"

namespace cio {

    void CFrame::capture() {
        if (!_covered) {
            if(!_frame || fullscreen()) {
                _covered =  console.capture(0, 0, console.getRows(), console.getCols());
            }
            else {
                _covered = console.capture(absRow(), absCol(), _height, _width);
            }
        }
    }

    void CFrame::free() {
        if (_covered) {
            delete [] _covered;
        }
        _covered = (char*)0;
    }

    CFrame::CFrame(int row, int col, int width, int height, bool visible, const char* border, CFrame* frame) {
        _row = row;
        _col = col;
        _height = height;
        _width = width;
        _visible = visible;
        _frame = frame;
        _covered = (char*) 0; 
        bio::strcpy(_border, border);
    }

    CFrame::~CFrame(void) {
        free();
    }

    void CFrame::setLine(char* line, char left, char fill, char right) const {
        line[0] = left;
        for (int i = 1; i < _width - 1; i++) {
            line[i] = fill;
        }
        line[_width - 1] = right;
        line[_width] = 0;
    }

    bool CFrame::fullscreen() const {
        return _height < 0 || _width < 0;
    }

    void CFrame::draw(int frame) { 
        int i;
        char* line = new char[_width + 1];
        capture();
        if (_frame && _visible && frame != C_NO_FRAME) {
            setLine(line, _border[0], _border[1], _border[2]);
            console.display(line, absRow(), absCol());
            setLine(line, _border[7], ' ', _border[3]);
            for (i = 1; i < _height - 1; i++) {
                console.display(line, absRow() + i, absCol());
            }
            setLine(line, _border[6], _border[5], _border[4]);
            console.display(line,absRow() + i, absCol()); 
        }
        delete[] line;
    }

    void CFrame::move(CDirection dir) {
        hide();
        switch(dir) {
            case up:
                if (row() > 0) {
                    row(row() - 1);
                }
            break;
            case down:
                if (row() + _height < frame()->height()) {
                    row(row()+1);
                }
            break;
            case left:
                if (col() > 0) {
                    col(col()-1);
                }
            break;
            case right:
                if (col() + _width < frame()->width()) {
                    col(col() + 1);
                }
            break;
        }
        draw();
    }

    void CFrame::move() {
        bool done = false;
        int key;
        char* firstLine = console.capture(0, 0, 1, console.getCols());
        while (!done) {
            console.display("Moving! use arrow keys, or ESC to exit", 0, 0, console.getCols());
            key = console.getKey();
            switch(key) {
                case ESCAPE:
                    done = true;
                break;
                case UP:
                    move(up);
                break;
                case DOWN:
                    move(down);
                break;
                case LEFT:
                    move(left);
                break;
                case RIGHT:
                    move(right);
                break;
                default:
                    console.alarm();
                break;
            }
        }
        console.restore(0, 0, 1, console.getCols(), firstLine);
        delete[] firstLine;
    }

    void CFrame::hide() {
        if(!_frame || fullscreen()) {
            console.restore(0, 0, console.getRows(), console.getCols(), _covered);
        }
        else {
            console.restore(absRow(), absCol(), _height, _width, _covered);
        }
        free();
    }

    void CFrame::visible(bool visible) {
        _visible = visible;
    }
  
    bool CFrame::visible() const {
        return _visible;
    }

    void CFrame::frame(CFrame* container) {
        _frame = container;
    }

    CFrame* CFrame::frame() {
        return _frame;
    }

    void CFrame::row(int row) {
        _row = row;
    }

    void CFrame::col(int col) {
        _col = col;
    }

    void CFrame::height(int height) {
        _height = height;
    }

    void CFrame::width(int width) {
        _width = width;
    }

    int CFrame::absRow() const {
        int row = _row;
        CFrame* frame = _frame;
        while(frame) {
            row += frame->row();
            frame = frame->_frame;
        }
        return row;
    }

    int CFrame::absCol() const {
        int col = _col;
        CFrame* frame = _frame;
        while(frame) {
            col += frame->col();
            frame = frame->_frame;
        }
        return col;
    }

    int CFrame::row() const {
        return fullscreen() ? 0 : _row;
    }

    int CFrame::col() const {
        return fullscreen() ? 0 : _col;
    }

    int CFrame::height() const {
        return fullscreen() ? console.getRows() : _height;
    }

    int CFrame::width() const {
        return fullscreen() ? console.getCols() : _width;
    }

    void CFrame::refresh() {
        if (_frame == (CFrame*) 0) {
            console.clear();
        }
        else {
            _frame->draw();
        }
        draw();
    }

}