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
    void tick();
    virtual void onClick(int x, int y);
    virtual void onTick();
};
#endif
