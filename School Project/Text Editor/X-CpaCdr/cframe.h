// Console UI Core Classes
// cframe.h
//
// Fardad Soleimanloo, Chris Szalwinski
// Feb 12 2012
// Version 1.0

#ifndef CODERPZ_CFRAME_H
#define CODERPZ_CFRAME_H

#include "cuigh.h"

namespace cio {

    class CFrame {
        private:
            bool _visible;
            char _border[9];
            char* _covered;
            int _col;
            int _height;
            int _row;
            int _width;
            CFrame* _frame;
            void capture();
            void free();
            void setLine(char*, char, char, char) const;
        protected:
            int absCol() const;
            int absRow() const;
        public:
            CFrame(int = -1, int = -1, int = -1, int = -1, bool = false, const char* = C_BORDER_CHARS, CFrame* = (CFrame*) 0);
            virtual ~CFrame();
            int col() const;
            void col(int);
            virtual void draw(int = C_FULL_FRAME);
            int height() const;
            void height(int);
            CFrame* frame();
            void frame(CFrame*);
            bool fullscreen() const;
            virtual void hide();
            virtual void move();
            virtual void move(CDirection);
            void refresh();
            int row() const;
            void row(int);
            bool visible() const;
            void visible(bool);
            int width() const;
            void width(int);
    };

}

#endif