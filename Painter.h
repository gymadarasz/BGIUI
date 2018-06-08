#ifndef PAINTER_H
#define PAINTER_H

#include <graphics.h>

namespace GUI {

    class Painter {
    public:
        static void box(int top, int left, int width, int height, int color, int fillpattern = SOLID_FILL);
        static void text(int top, int left, int color, int bgcolor, const char* txt);
    };

}
#endif
