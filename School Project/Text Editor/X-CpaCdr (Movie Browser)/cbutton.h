#pragma once
#include "cfield.h"
namespace cio{
   class  CButton: public CField{

   public:
     CButton(const char *Str, int Row, int Col, 
              bool Bordered = true,
              const char* Border=C_BORDER_CHARS);
     virtual ~CButton();
     void draw(int rn=C_FULL_FRAME);
     int edit();
     bool editable()const;
     void set(const void* str);
   };
}