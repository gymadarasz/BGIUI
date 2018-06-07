#include "Canvas.h"

#include "Graph.h"

class graph;

int Canvas::nxt = 0;

Canvas::Canvas(Graph* graph, int top, int left, int width, int height, int bgcolor) {
    id = ++nxt;
    this->graph = graph;
    if (NULL != graph) {
        this->graph->registry(this);
    }
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

int Canvas::getWidth() {
    return width;
}

int Canvas::getHeight() {
    return height;
}

void Canvas::setGraph(Graph* graph) {
    this->graph = graph;
}

bool Canvas::inside(POINT point) {
    RECT rect;
    getRect(&rect);
    return point.x >= rect.left && point.x <= rect.right && point.y >= rect.top && point.y <= rect.bottom;
}

void Canvas::tick() {
    
    onTick();
    
    if (graph->events.onClick.happend && inside(graph->events.onClick.position)) {
        onClick(graph->events.onClick.position.x-left, graph->events.onClick.position.y-top);
    }
    
    if (graph->events.onDblClick.happend && inside(graph->events.onDblClick.position)) {
        onDblClick(graph->events.onDblClick.position.x-left, graph->events.onDblClick.position.y-top);
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
//    printf("Canvas::onTick\n");
}

void Canvas::onClick(int x, int y) {
//    printf("Canvas[%d]::onClick\n", id);
}

void Canvas::onDblClick(int x, int y) {
//    printf("Canvas[%d]::onDblClick\n", id);
}

void Canvas::onMouseMove(int x, int y, int prevx, int prevy) {
    
}

void Canvas::onMouseOver(int x, int y) {
//    printf("Canvas[%d]::onMouseOver\n", id);
    graph->highlight(this, true);
}

void Canvas::onMouseLeave(int x, int y) {
//    printf("Canvas[%d]::onMouseLeave\n", id);
    graph->highlight(this, false);
}



