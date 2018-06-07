#ifndef CANVAS_H
#define CANVAS_H

#include <graphics.h>
#include "style.h"

class Graph;

class Canvas {
    static int nxt;
protected:
    int id;
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
    int getWidth();
    int getHeight();
    void setGraph(Graph* graph);
    bool inside(POINT point);
    void tick();
    virtual void onTick();
    virtual void onClick(int x, int y);
    virtual void onDblClick(int x, int y);
    virtual void onMouseMove(int x, int y, int prevx, int prevy);
    virtual void onMouseOver(int x, int y);
    virtual void onMouseLeave(int x, int y);
};
#endif
