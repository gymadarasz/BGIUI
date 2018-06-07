#ifndef GRAPH_H
#define GRAPH_H

#include <graphics.h>
#include "style.h"

#define CANVASES 255

class Canvas;

class Graph {
private:
    int lastMouseX;
    int lastMouseY;
protected:
    Canvas* canvases[CANVASES];
    int bgcolor;
    int hbcolor;
    
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
    } events;
    
    Graph(int top, int left, Canvas* canvas, const char* title, int bgcolor = GD_BGCOLOR, int hbcolor = GD_HBCOLOR);
    void fillBox(int top, int left, int width, int height, int color);
    void text(int top, int left, int color, int bgcolor, const char* txt);
    void registry(Canvas* canvas);
    void highlight(Canvas* canvas, bool activate);
    void tick();
    void run();
};

#endif
