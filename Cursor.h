#ifndef CURSOR_H
#define CURSOR_H

namespace GUI {
    class Cursor {
    protected:
        int w;
        int cx;
        int cy;
        int px;
        int py;
        int maxy;
    public:
        
        void reset(int w);
        void step(int x, int y, int nx);
        void nl(int h=0);
        int getx();
        int gety();
    };
}

#endif
