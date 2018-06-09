#ifndef APP_H
#define APP_H

#include "Window.h"
#include "Mouse.h"
#include "Painter.h"
#include "Canvas.h"

#define APP_CANVASES 100

namespace GUI {
    
    class Canvas;

    class App {
    private:
        void cleanup();
        void ticks();
    protected:
        Window window;
        Mouse mouse;
        Painter painter;
        Canvas* canvas;
        Canvas* canvases[APP_CANVASES];
        virtual void init();
    public:
        App(const char* title,
            int top = GD_WIN_DEFAULT_TOP, int left = GD_WIN_DEFAULT_LEFT,
            int width = GD_WIN_DEFAULT_WIDTH, int height = GD_WIN_DEFAULT_HEIGHT,
            int bgcolor = GD_WIN_BGCOLOR);
        void run();
        void registry(Canvas* canvas);
        Canvas* getCanvas();
        Mouse getMouse();
        Window getWindow();
        Painter getPainter();
    };

}

#endif
