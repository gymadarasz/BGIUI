#include "Canvas.h"

#include "App.h"

#define CANVAS_DEFAULT_WIDTH 128
#define CANVAS_DEFAULT_HEIGHT 160

namespace GUI {

    int Canvas::nxt = 0;

    Canvas::Canvas(int top, int left, int width, int height, int bgcolor, int brcolor) {
        id = ++nxt;
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

    bool Canvas::draw() {
        if (isChanged()) {
            if (
                lastTop != top ||
                lastLeft != left ||
                lastWidth != width ||
                lastHeight != height
            ) {
                clear();
            }
            int width = getWidth();
            int height = getHeight();
            App::painter.box(top-1, left-1, width+2, height+2, getBrColor(), EMPTY_FILL);
            App::painter.box(top, left, width, height, getBgColor());
            lastTop = top;
            lastLeft = left;
            lastWidth = width;
            lastHeight = height;
            return true;
        }
        return false;
    }
    
    void Canvas::clear() {
        int width = getWidth();
        int height = getHeight();
        App::painter.box(top-1, left-1, width+2, height+2, GD_WIN_BGCOLOR, EMPTY_FILL);
        App::painter.box(top, left, width, height, GD_WIN_BGCOLOR);
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

//    void Canvas::setContainer(Container* container) {
//        this->container = container;
//        this->container->add(this);
//    }
    
//    Container* Canvas::getContainer() {
//        return container;
//    }

    bool Canvas::inside(POINT point) {
        RECT rect;
        getRect(&rect);
        return point.x >= rect.left && point.x <= rect.right && point.y >= rect.top && point.y <= rect.bottom;
    }

    void Canvas::tick() {

        onTick();

        if (App::mouse.events.onClick.happend && inside(App::mouse.events.onClick.position)) {
            onClick(App::mouse.events.onClick.position.x-left, App::mouse.events.onClick.position.y-top);
        }

        if (App::mouse.events.onDblClick.happend && inside(App::mouse.events.onDblClick.position)) {
            onDblClick(App::mouse.events.onDblClick.position.x-left, App::mouse.events.onDblClick.position.y-top);
        }

        if (App::mouse.events.onMouseMove.happend) {
            if (inside(App::mouse.events.onMouseMove.current) && inside(App::mouse.events.onMouseMove.previous)) {
                onMouseMove(
                    App::mouse.events.onMouseMove.current.x-left, App::mouse.events.onMouseMove.current.y-top,
                    App::mouse.events.onMouseMove.previous.x-left, App::mouse.events.onMouseMove.previous.y-top
                );
            } else if (inside(App::mouse.events.onMouseMove.current)) {
                onMouseOver(App::mouse.events.onMouseMove.current.x-left, App::mouse.events.onMouseMove.current.y-top);
            } else if (inside(App::mouse.events.onMouseMove.previous)) {
                onMouseLeave(App::mouse.events.onMouseMove.previous.x-left, App::mouse.events.onMouseMove.previous.y-top);
            }
        }

        if (App::mouse.events.onMouseDown.happend && inside(App::mouse.events.onMouseDown.position)) {
            onMouseDown(App::mouse.events.onMouseDown.position.x-left, App::mouse.events.onMouseDown.position.y-top);
        }

        if (App::mouse.events.onMouseUp.happend && inside(App::mouse.events.onMouseUp.position)) {
            onMouseUp(App::mouse.events.onMouseUp.position.x-left, App::mouse.events.onMouseUp.position.y-top);
        }

    }

    void Canvas::onTick() {}

    void Canvas::onClick(int x, int y) {
        printf("Click on elem[%d]\n", id);
    }

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
