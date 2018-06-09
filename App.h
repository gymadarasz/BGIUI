#ifndef APP_H
#define APP_H

#include "style.h"
#include "Window.h"
#include "Mouse.h"
#include "Painter.h"

namespace GUI {

    class App {
    public:
        static Window window;
        static Mouse mouse;
        static Painter painter;
        App(const char* title,
            int top = GD_WIN_DEFAULT_TOP, int left = GD_WIN_DEFAULT_LEFT,
            int width = GD_WIN_DEFAULT_WIDTH, int height = GD_WIN_DEFAULT_HEIGHT,
            int bgcolor = GD_WIN_BGCOLOR, int txcolor = GD_WIN_BGCOLOR);
        virtual void init();
        void run();
    };

}

#endif
