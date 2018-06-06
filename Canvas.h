#ifndef CANVAS_H
#define CANVAS_H

#include "Graph.h"

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
    Canvas(Graph* graph, int top, int left, int width, int height, int bgcolor);
    void clear();
    void tick();
    virtual void onClick(int x, int y);
};
#endif
