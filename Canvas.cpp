#include "Canvas.h"

#include "Graph.h"

class graph;

Canvas::Canvas(Graph* graph, int top, int left, int width, int height, int bgcolor) {
    this->graph = graph;
    this->graph->registry(this);
    this->top = top;
    this->left = left;
    this->width = width;
    this->height = height;
    this->bgcolor = bgcolor;
    clear();
}

void Canvas::clear() {
    graph->fillBox(top, left, width, height, bgcolor);
}

void Canvas::tick() {

        //printf("click at (%d, %d) but we in (%d, %d, %d, %d)\n", x, y, left, top, width, height);
    if(graph->events.onClick.happend) {
        if (
            graph->events.onClick.x > left && graph->events.onClick.x < left + width &&
            graph->events.onClick.y > top && graph->events.onClick.y < top + height
        ) {
            onClick(graph->events.onClick.x-left, graph->events.onClick.y-top);
        }
    }
}

void Canvas::onClick(int x, int y) {
    printf("Canvas::onClick\n");
}


