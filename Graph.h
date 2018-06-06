#ifndef GRAPH_H
#define GRAPH_H

#include <graphics.h>
#include "Canvas.h"

#define CANVASES 4

class Canvas;

class Graph {
protected:
    HWND hWnd;
    Canvas* canvases[CANVASES];
public:
    struct {
        struct {
            bool happend;
            int x;
            int y;
        } onClick;
    } events;
    
    Graph(int top, int left, int width, int height, const char* title);
    void fillBox(int top, int left, int width, int height, int color);
    void text(int top, int left, int color, int bgcolor, const char* txt);
    void registry(Canvas* canvas);
    void tick();
    void run();
};

#endif
