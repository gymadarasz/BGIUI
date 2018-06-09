#include "Canvas.h"

#include "Painter.h"

#define CANVAS_DEFAULT_WIDTH 128
#define CANVAS_DEFAULT_HEIGHT 160

namespace GUI {

    //class graph;

    int Canvas::nxt = 0;

    Canvas::Canvas(App* app, int top, int left, int width, int height, int bgcolor, int brcolor) {
        id = ++nxt;
        setApp(app);
        this->top = top;
        this->left = left;
        setWidth(width);
        setHeight(height);
        setBgColor(bgcolor);
        setBrColor(brcolor);
        setHighlighted(false);
        setPushed(false);
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
        app->getPainter().box(top-1, left-1, width+2, height+2, getBrColor(), EMPTY_FILL);
        app->getPainter().box(top, left, width, height, getBgColor());
    }
    
    void Canvas::clear() {
        int width = getWidth();
        int height = getHeight();
        app->getPainter().box(top-1, left-1, width+2, height+2, app->getCanvas()->getBgColor(), EMPTY_FILL);
        app->getPainter().box(top, left, width, height, app->getCanvas()->getBgColor());
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
        return getPushed() ? GD_PSBGCOLOR : bgcolor;
    }

    int Canvas::getBrColor() {
        return getHighlighted() ? GD_HLBRCOLOR : brcolor;
    }

    bool Canvas::getHighlighted() {
        return highlighted;
    }

    bool Canvas::getPushed() {
        return pushed;
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

    void Canvas::setBrColor(int brcolor) {
        this->brcolor = brcolor;
        changed = true;
    }

    void Canvas::setHighlighted(bool highlighted) {
        this->highlighted = highlighted;
        changed = true;
    }

    void Canvas::setPushed(bool pushed) {
        this->pushed = pushed;
        changed = true;
    }

    void Canvas::setApp(App* app) {
        this->app = app;
        this->app->registry(this);
    }

    bool Canvas::inside(POINT point) {
        RECT rect;
        getRect(&rect);
        return point.x >= rect.left && point.x <= rect.right && point.y >= rect.top && point.y <= rect.bottom;
    }

    void Canvas::tick() {

        onTick();

        MouseEvents events = app->getMouse().getEvents();

        if (events.onClick.happend && inside(events.onClick.position)) {
            onClick(events.onClick.position.x-left, events.onClick.position.y-top);
        }

        if (events.onDblClick.happend && inside(events.onDblClick.position)) {
            onDblClick(events.onDblClick.position.x-left, events.onDblClick.position.y-top);
        }

        if (events.onMouseMove.happend) {
            if (inside(events.onMouseMove.current) && inside(events.onMouseMove.previous)) {
                onMouseMove(
                    events.onMouseMove.current.x-left, events.onMouseMove.current.y-top,
                    events.onMouseMove.previous.x-left, events.onMouseMove.previous.y-top
                );
            } else if (inside(events.onMouseMove.current)) {
                onMouseOver(events.onMouseMove.current.x-left, events.onMouseMove.current.y-top);
            } else if (inside(events.onMouseMove.previous)) {
                onMouseLeave(events.onMouseMove.previous.x-left, events.onMouseMove.previous.y-top);
            }
        }

        if (events.onMouseDown.happend && inside(events.onMouseDown.position)) {
            onMouseDown(events.onMouseDown.position.x-left, events.onMouseDown.position.y-top);
        }

        if (events.onMouseUp.happend && inside(events.onMouseUp.position)) {
            onMouseUp(events.onMouseUp.position.x-left, events.onMouseUp.position.y-top);
        }

    }

    void Canvas::onTick() {}

    void Canvas::onClick(int x, int y) {}

    void Canvas::onDblClick(int x, int y) {}

    void Canvas::onMouseMove(int x, int y, int prevx, int prevy) {}

    void Canvas::onMouseOver(int x, int y) {
        setHighlighted(true);
    }

    void Canvas::onMouseLeave(int x, int y) {
        setHighlighted(false);
    }

    void Canvas::onMouseDown(int x, int y) {}

    void Canvas::onMouseUp(int x, int y) {}

    // --- private

    int Canvas::calcWidth() {
        return CANVAS_DEFAULT_WIDTH;
    }

    int Canvas::calcHeight() {
        return CANVAS_DEFAULT_HEIGHT;
    }

}
