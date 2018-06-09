#ifndef WINDOW_H
#define WINDOW_H

#include <graphics.h>

namespace GUI {

    class Window {
    protected:
        HWND hWnd;
    public:
        void init(const char* title, int top, int left, int width, int height);
        HWND getHWnd();
    };

}

#endif
