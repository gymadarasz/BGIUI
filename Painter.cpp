#include "Painter.h"

namespace GUI {

    void Painter::box(int top, int left, int width, int height, int color, int fillpattern) {

        int right = left + width;
        int bottom = top + height;

        fillsettingstype fillinfo;
        getfillsettings(&fillinfo);
        int c = getcolor();

        setfillstyle(fillpattern, color);
        setcolor(color);

        rectangle(left, top, right, bottom);
        if (left < right && top < bottom) {
            floodfill(left+1, top+1, color);
        }

        setfillstyle(fillinfo.pattern, fillinfo.color);
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
