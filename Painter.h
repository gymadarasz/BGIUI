#ifndef PAINTER_H
#define PAINTER_H

#include <graphics.h>

namespace GUI {

    class Painter {
    public:
        static void hline(int x, int y1, int y2, int color);
        static void vline(int x1, int y, int x2, int color);
        static void box(int top, int left, int width, int height, int color, bool fill);
        static void text(int top, int left, int color, int bgcolor, const char* txt);
    };

}
#endif
