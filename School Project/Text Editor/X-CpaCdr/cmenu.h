#ifndef CODERPZ_CMENU_H
#define CODERPZ_CMENU_H

#include "cbutton.h"
#include "cfield.h"
#include "cmenuitem.h"
#include "cuigh.h"

namespace cio {

    class Cmenu;

    class MNode {
        unsigned int _index;
        CMenuItem* _item;
        MNode* _next;
        MNode* _previous;
        MNode(CMenuItem*, unsigned int, MNode*, MNode* = ((MNode*)0));
        ~MNode(void);
        friend class CMenu;
    };

    class CMenu : public CField {
        private:
            MNode* _first;
            MNode* _head;
            MNode* _tail;
            MNode* _cur;
            char _format[3];
            unsigned int _count;
            int _selectedIndex;
            bool _dropdown;
            bool _dropped;
            bool goNext();
            bool goPrev();
            CButton _title;
        public:
            static const bool Select;
            CMenu(const char*, const char*, int, int, int, int, bool, const char* = C_BORDER_CHARS);
            virtual ~CMenu(void);
            CMenu& add(const char*, bool = false);
            void draw(int = C_FULL_FRAME);
            int edit();
            bool editable() const;
            void set(const void*);
            int selectedIndex() const;
            int selectedIndex(int);
            const char* selectedText();
            CMenu& operator<<(const char*);
            CMenu& operator<<(bool);
    };

    extern const bool Select;

}

#endif