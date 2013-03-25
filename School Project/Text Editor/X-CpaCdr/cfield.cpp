#include "bconsole.h"
#include "cfield.h"

using bio::strcpy;
using bio::strlen;

namespace cio {

    CField::CField(int row, int col, int width, int height, void* data, bool bordered, const char* border) : CFrame(row, col, width, height, bordered, border) {
        _data = data;
    }

    CField::~CField() {
    }

    void CField::container(CDialog* container) {
        CFrame::frame((CFrame*)container);
    }

    void* CField::data() {
        return (void*)_data;
    }

    CDialog* CField::container() {
        return (CDialog*)CFrame::frame();
    } 

}
