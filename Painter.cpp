#include "Painter.h"

#include "App.h"

namespace GUI {

    void Painter::box(int top, int left, int width, int height, int color, bool fill) {
        int bottom = top+height;
        int right = left+width;
        int c = getcolor();
        setcolor(color);
        if (fill) {
            for (int y=top; y<bottom; y++) {
                line(left, y, right, y);
            }
        } else {
            line(left, top, left, bottom);
            line(left, top, right, top);
            line(right, top, right, bottom);
            line(left, bottom, right, bottom);
        }
        setcolor(c);
    }

    void Painter::text(int top, int left, int color, int bgcolor, const char* txt) {
        int c = getcolor();
        int b = getbkcolor();
        setcolor(color);
        setbkcolor(bgcolor);
        outtextxy(left, top, (char*)txt);
        setcolor(c);
        setbkcolor(b);
    }
    
}
