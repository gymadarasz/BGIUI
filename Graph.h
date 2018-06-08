#ifndef GRAPH_H
#define GRAPH_H

#include <graphics.h>
#include "style.h"
#include "App.h"

#define CANVASES 255

namespace GUI {

    class Canvas;

    class Graph {
    private:
        int lastMouseX;
        int lastMouseY;
    protected:
        Canvas* canvases[CANVASES];
    public:
        struct {
            struct {
                bool happend;
                POINT position;
            } onClick;
            struct {
                bool happend;
                POINT position;
            } onDblClick;
            struct {
                bool happend;
                POINT current;
                POINT previous;
            } onMouseMove;
            struct {
                bool happend;
                POINT position;
            } onMouseDown;
            struct {
                bool happend;
                POINT position;
            } onMouseUp;
        } events;

        Graph(int top, int left, Canvas* canvas, const char* title, int bgcolor = GD_WIN_BGCOLOR);
        void box(int top, int left, int width, int height, int color, int fillpattern = SOLID_FILL);
        void text(int top, int left, int color, int bgcolor, const char* txt);
        void registry(Canvas* canvas);
    //    void highlight(Canvas* canvas, bool activate);
        void tick();
        void run();
        Canvas* getCanvas();
    };

}

#endif
