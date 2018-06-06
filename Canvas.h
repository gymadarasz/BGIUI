#ifndef CANVAS_H
#define CANVAS_H

#include "Graph.h"
#include "style.h"

class Graph;

class Canvas {
protected:
    Graph* graph;
    int top;
    int left;
    int width;
    int height;
    int bgcolor;
public:
    Canvas(Graph* graph, int top, int left, int width, int height, int bgcolor = GD_CANVAS_BGCOLOR);
    void clear();
    RECT* getRect(RECT* rect);
    bool inside(POINT point);
    void tick();
    virtual void onTick();
    virtual void onClick(int x, int y);
    virtual void onMouseMove(int x, int y, int prevx, int prevy);
    virtual void onMouseOver(int x, int y);
    virtual void onMouseLeave(int x, int y);
};
#endif
