#ifndef WINDOW_H
#define WINDOW_H

#include <graphics.h>
#include "style.h"

namespace GUI {

    class Window {
    protected:
        HWND hWnd;
    public:
        void init(
            const char* title,
            int top = GUI_WINDOW_DEFAULT_TOP,
            int left = GUI_WINDOW_DEFAULT_LEFT,
            int width = GUI_WINDOW_DEFAULT_WIDTH,
            int height = GUI_WINDOW_DEFAULT_HEIGHT
        );
        HWND getHWnd();
    };

}

#endif
