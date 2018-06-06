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

RECT* Canvas::getRect(RECT* rect) {
    rect->top = top;
    rect->left = left;
    rect->right = left + width;
    rect->bottom = top + height;
    return rect;
}

bool Canvas::inside(POINT point) {
    RECT rect;
    getRect(&rect);
    return point.x >= rect.left && point.x <= rect.right && point.y >= rect.top && point.y <= rect.bottom;
}

void Canvas::tick() {
    

    onTick();
    
        //printf("click at (%d, %d) but we in (%d, %d, %d, %d)\n", x, y, left, top, width, height);
    if (graph->events.onClick.happend && inside(graph->events.onClick.position)) {
        onClick(graph->events.onClick.position.x-left, graph->events.onClick.position.y-top);
    }
    
    if (graph->events.onMouseMove.happend) {
        if (inside(graph->events.onMouseMove.current) && inside(graph->events.onMouseMove.previous)) {
            onMouseMove(
                graph->events.onMouseMove.current.x-left, graph->events.onMouseMove.current.y-top,
                graph->events.onMouseMove.previous.x-left, graph->events.onMouseMove.previous.y-top
            );
        } else if (inside(graph->events.onMouseMove.current)) {
            onMouseOver(graph->events.onMouseMove.current.x-left, graph->events.onMouseMove.current.y-top);
        } else if (inside(graph->events.onMouseMove.previous)) {
            onMouseLeave(graph->events.onMouseMove.previous.x-left, graph->events.onMouseMove.previous.y-top);
        }
    }
    
}

void Canvas::onTick() {
    //printf("Canvas::onTick\n");
}

void Canvas::onClick(int x, int y) {
    printf("Canvas::onClick\n");
}

void Canvas::onMouseMove(int x, int y, int prevx, int prevy) {
    
}

void Canvas::onMouseOver(int x, int y) {
    printf("Canvas::onMouseOver\n");
    graph->highlight(this, true);
}

void Canvas::onMouseLeave(int x, int y) {
    printf("Canvas::onMouseLeave\n");
    graph->highlight(this, false);
}



