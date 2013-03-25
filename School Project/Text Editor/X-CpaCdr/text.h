// Console UI Core Classes
// text.h
// a class to convert text string to arrays of string for each line of the text and back
//
// Fardad Soleimanloo, Chris Szalwinski
// Nov 1, 2012
// Version 0.9

#ifndef CODERPZ_TEXT_H
#define CODERPZ_TEXT_H

#define INIT_TEXT_LINES 128
#define INIT_LINE_CHARS 512

namespace cio {

    class Text;
    
    class Line {
        private:
            char* _data;
            unsigned int _size;
            static void* memcpy(void*, const void*, unsigned int);
            static unsigned int strlen(const char*);
            static unsigned int strncpy(char*, const char*, unsigned int);
        public:
            Line(const Line &);
            Line(const char* = (char*) 0);
            virtual ~Line();
            void expand(unsigned int);
            unsigned int size() const;
            unsigned int strlen() const;

            friend class Text;

            operator char*();
            Line& operator=(const Line&);
            Line& operator=(const char*);
            Line& operator+=(const Line&);
            Line& operator+=(const char*);
    };

    class Text {
        private:
            unsigned int _size;
            unsigned int _textlines;
            Line** _data;
            void importString(const char*);
            void initialize();
        public:
            Text(const Text&);
            Text(const char* = (char*) 0);
            virtual ~Text();
            void destruct();
            void expand(unsigned int);
            char* exportString() const;
            void insertAt(unsigned int);
            void insertAndBreakAt(unsigned int, unsigned int);
            bool remove(unsigned int);
            unsigned int size() const;
            unsigned int strlen() const;
            unsigned int textLines();

            operator void*();
            Line& operator[](unsigned int);
            Text& operator=(const Text&);
            Text& operator=(const char*);
    };

}

#endif