#include "Cursor.h"

namespace GUI {

    void Cursor::reset(int w) {
        this->w=w;
        cx=0;
        cy=0;
        px=cx;
        py=cy;
        maxy=0;
    }

    void Cursor::step(int x, int y, int nx) {
        px=cx;
        py=cy;
        cx+=x;
        maxy=maxy<y?y:maxy;
        if(cx+nx>w)nl();
    }

    void Cursor::nl(int h) {
        cx=0;
        cy+=maxy<h?h:maxy;
        maxy=0;
    }
    
    int Cursor::getx() {
        return px;
    }
    
    int Cursor::gety() {
        return py;
    }
}
