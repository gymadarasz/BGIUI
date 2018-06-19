#ifndef CURSOR_H
#define CURSOR_H

#include "style.h"

namespace GUI {
    class Cursor {
    protected:
        int width;
        int currentx;
        int currenty;
        int positionx;
        int positiony;
        int maxy;
        int autowidth;
    public:
        void reset(int width = GUI_AUTOSIZE);
        void step(int x, int y, int nextx, bool br);
        void newline(int height = 0);
        int getpositionx();
        int getpositiony();
        int getcurrentx();
        int getcurrenty();
        int getwidth();
        int getheight();
    };
}

#endif
