#include "Cursor.h"

namespace GUI {

    void Cursor::reset(int width) {
        this->width = width;
        currentx = 0;
        currenty = 0;
        positionx = currentx;
        positiony = currenty;
        maxy = 0;
        autowidth = 0;
    }

    void Cursor::step(int x, int y, int nextx, bool br) {
        if (br) {
            newline();
        }
        positionx = currentx;
        positiony = currenty;
        currentx += x;
        maxy = maxy < y ? y : maxy;
        autowidth = currentx + nextx;
        if (autowidth > getwidth()) {
            newline();
        }
    }

    void Cursor::newline(int height) {
        currentx = 0;
        currenty += maxy < height ? height : maxy;
        maxy = 0;
    }

    int Cursor::getpositionx() {
        return positionx;
    }

    int Cursor::getpositiony() {
        return positiony;
    }


    int Cursor::getcurrentx() {
        return currentx;
    }

    int Cursor::getcurrenty() {
        return currenty;
    }

    int Cursor::getwidth() {
        return width == GD_AUTOSIZE ? autowidth : width;
    }
    
    int Cursor::getheight() {
        return currenty + maxy;
    }

}
