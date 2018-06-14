#include "Painter.h"

#include "App.h"

namespace GUI {
    
    void Painter::hline(int x, int y1, int y2, int color) {
        if (color == GD_NOCOLOR) {
            return ;
        }

        int c = getcolor();
        setcolor(color);
        line(x, y1, x, y2);
        setcolor(c);
    }
    
    void Painter::vline(int x1, int y, int x2, int color) {
        if (color == GD_NOCOLOR) {
            return ;
        }

        int c = getcolor();
        setcolor(color);
        line(x1, y, x2, y);
        setcolor(c);
    }

    void Painter::box(int top, int left, int width, int height, int color, bool fill) {
        if (color == GD_NOCOLOR) {
            return ;
        }
        int bottom = top+height;
        int right = left+width;
        if (fill) {
            for (int y=top; y<bottom; y++) {
                vline(left, y, right, color);
            }
        } else {
            hline(left, top, bottom, color);
            vline(left, top, right, color);
            hline(right, top, bottom, color);
            vline(left, bottom, right, color);
        }
    }

    void Painter::text(int top, int left, int color, int bgcolor, const char* txt) {

        if (color == GD_NOCOLOR) {
            if (bgcolor != GD_NOCOLOR) {
                box(top, left, textwidth((char*)txt), textheight((char*)txt), bgcolor, GD_FILL);
            }
            return ;
        }
        
        int c = getcolor();
        int b = getbkcolor();
        setcolor(color);
        setbkcolor(bgcolor);
        outtextxy(left, top, (char*)txt);
        setcolor(c);
        setbkcolor(b);
    }
    
}
