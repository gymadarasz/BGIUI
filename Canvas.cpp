#include "Canvas.h"

#include "Graph.h"

#define WINDOW_DEFAULT_WIDTH 800
#define WINDOW_DEFAULT_HEIGHT 600
#define CANVAS_DEFAULT_WIDTH 128
#define CANVAS_DEFAULT_HEIGHT 160

class graph;

int Canvas::nxt = 0;

Canvas::Canvas(Graph* graph, int top, int left, int width, int height, int bgcolor, int brcolor) {
    id = ++nxt;
    setGraph(graph);
    if (NULL != graph) {
        this->graph->registry(this);
    } else {
        top = 0;
        left = 0;
        if (width == GD_AUTO) {
            width = WINDOW_DEFAULT_WIDTH;
        }
        if (height == GD_AUTO) {
            height = WINDOW_DEFAULT_HEIGHT;
        }
    }
    this->top = top;
    this->left = left;
    setWidth(width);
    setHeight(height);
    this->bgcolor = bgcolor;
    this->brcolor = brcolor;
    changed = true;
}

bool Canvas::isChanged() {
    bool ret = changed;
    changed = false;
    return ret;
}

void Canvas::draw() {
    int width = getWidth();
    int height = getHeight();
    graph->box(top-1, left-1, width+2, height+2, brcolor, EMPTY_FILL);
    graph->box(top, left, width, height, bgcolor);
}

RECT* Canvas::getRect(RECT* rect) {
    rect->top = top;
    rect->left = left;
    rect->right = left + getWidth();
    rect->bottom = top + getHeight();
    return rect;
}

int Canvas::getWidth() {
    return width != GD_AUTO ? width : calcWidth();
}

int Canvas::getHeight() {
    return height != GD_AUTO ? height : calcHeight();
}

int Canvas::getBgColor() {
    return bgcolor;
}

void Canvas::setWidth(int width) {
    this->width = width;
    changed = true;
}

void Canvas::setHeight(int height) {
    this->height = height;
    changed = true;
}

void Canvas::setBgColor(int bgcolor) {
    this->bgcolor = bgcolor;
    changed = true;
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
//    graph->highlight(this, true);
}

void Canvas::onMouseLeave(int x, int y) {
//    printf("Canvas[%d]::onMouseLeave\n", id);
//    graph->highlight(this, false);
}

int Canvas::calcWidth() {
    return CANVAS_DEFAULT_WIDTH;
}

int Canvas::calcHeight() {
    return CANVAS_DEFAULT_HEIGHT;
}

