#ifndef CODERPZ_CMENUITEM_H
#define CODERPZ_CMENUITEM_H

#include "cfield.h"
#include "clabel.h"

namespace cio {

    class CMenuItem : public CField {
        private:
            bool _selected;
            char _format[3];
            CLabel _label;
        public:
            CMenuItem(bool, const char*, const char*, int, int, int);
            CMenuItem(const CMenuItem&);
            virtual ~CMenuItem();
            void draw(int = C_NO_FRAME);
            int edit();
            bool editable() const;
            bool selected() const;
            void selected(bool);
            void set(const void*);
            const char* Text();
  };

}

#endif