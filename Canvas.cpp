#include "Canvas.h"

#include "App.h"

#define CANVAS_DEFAULT_WIDTH 128
#define CANVAS_DEFAULT_HEIGHT 160

namespace GUI {
    
    Canvas::Canvas(Container* container): Counted() {
        setup();
        setContainer(container);
    }
    
    Canvas* Canvas::setup(
        int top,
        int left,
        int width,
        int height,
        RECT margin,
        RECT padding,
        int bgcolor,
        int brcolor
    ) {
        setTop(top);
        setLeft(left);
        setWidth(width);
        setHeight(height);
        setMargin(margin);
        setPadding(padding);
        setBgColor(bgcolor);
        setBrColor(brcolor);
        setHighlighted(false);
        setPushed(false);
        setDisabled(true);
        return this;
    }
    
    Canvas* Canvas::setContainer(Container* container) {
        if (NULL != container && this->container != container) {
            this->container = container;
            container->add(this);
        }
        changed = true;
        return this;
    }
    
    Container* Canvas::getContainer() {
        return container;
    }
    
    bool Canvas::isChanged() {
        bool ret = changed;
        changed = false;
        return ret;
    }

    void Canvas::tick() {
        

        onTick();

        if (getDisabled()) {
            return ;
        }

        int top = getTop();
        int left = getLeft();
        
        // click?
        if (App::mouse.events.onClick.happend && inside(App::mouse.events.onClick.position)) {
            onClick(App::mouse.events.onClick.position.x-left, App::mouse.events.onClick.position.y-top);
        }

        // dblclick?
        if (App::mouse.events.onDblClick.happend && inside(App::mouse.events.onDblClick.position)) {
            onDblClick(App::mouse.events.onDblClick.position.x-left, App::mouse.events.onDblClick.position.y-top);
        }

        // mouse move, over, leave?
        if (App::mouse.events.onMouseMove.happend) {
            if (inside(App::mouse.events.onMouseMove.current) && inside(App::mouse.events.onMouseMove.previous)) {
                onMouseMove(
                    App::mouse.events.onMouseMove.current.x-left, App::mouse.events.onMouseMove.current.y-top,
                    App::mouse.events.onMouseMove.previous.x-left, App::mouse.events.onMouseMove.previous.y-top
                );
            } else if (inside(App::mouse.events.onMouseMove.current)) {
                setHighlighted(true);
                onMouseOver(App::mouse.events.onMouseMove.current.x-left, App::mouse.events.onMouseMove.current.y-top);
            } else if (inside(App::mouse.events.onMouseMove.previous)) {
                setHighlighted(false);
                onMouseLeave(App::mouse.events.onMouseMove.previous.x-left, App::mouse.events.onMouseMove.previous.y-top);
            }
        }

        // mouse down?
        if (App::mouse.events.onMouseDown.happend && inside(App::mouse.events.onMouseDown.position)) {
            onMouseDown(App::mouse.events.onMouseDown.position.x-left, App::mouse.events.onMouseDown.position.y-top);
        }

        // mouse up?
        if (App::mouse.events.onMouseUp.happend && inside(App::mouse.events.onMouseUp.position)) {
            onMouseUp(App::mouse.events.onMouseUp.position.x-left, App::mouse.events.onMouseUp.position.y-top);
        }

    }
    
    bool Canvas::draw() {
        if (isChanged()) {
            int top = getTop();
            int left = getLeft();
            int width = getWidth();
            int height = getHeight();
            if (
                lastTop != top ||
                lastLeft != left ||
                lastWidth != width ||
                lastHeight != height
            ) {
                clear(/*lasts*/);
            }
            // todo: use class variable instead GD_BRSIZE
            App::painter.box(top-GD_BRSIZE, left-GD_BRSIZE, width+GD_BRSIZE, height+GD_BRSIZE, getBrColor(), GD_NOFILL);
            App::painter.box(top, left, width, height, getBgColor(), GD_FILL);
            lastTop = top;
            lastLeft = left;
            lastWidth = width;
            lastHeight = height;
            return true;
        }
        return false;
    }
    
    void Canvas::clear() {
        int top = getTop();
        int left = getLeft();
        int width = getWidth();
        int height = getHeight();
        //App::painter.box(top-1, left-1, width+2, height+2, App::rootCanvas.getBgColor(), EMPTY_FILL);
        App::painter.box(top-GD_BRSIZE, left-GD_BRSIZE, width+GD_BRSIZE*2, height+GD_BRSIZE*2, App::rootCanvas.getBgColor(), GD_FILL);
    }

    RECT* Canvas::getRect(RECT* rect) {
        int top = getTop();
        int left = getLeft();
        rect->top = top;
        rect->left = left;
        rect->right = left + getWidth();
        rect->bottom = top + getHeight();
        return rect;
    }
    
    int Canvas::getFullWidth() {
        return getWidth() + margin.left + margin.right;
    }
    
    int Canvas::getFullHeight() {
        return getHeight() + margin.top + margin.bottom;
    }
    
    int Canvas::getTop() {
        int ret = container->offset.y;
        ret += top == GD_AUTOPOSITION ? container->cursor.gety() : top;
        return ret;
    }
    
    int Canvas::getLeft() {
        int ret = container->offset.x;
        ret += left == GD_AUTOPOSITION ? container->cursor.getx() : left;
        return ret;
    }

    int Canvas::getWidth() {
        return width == GD_AUTOSIZE ? calcWidth() : width;
    }

    int Canvas::getHeight() {
        return height == GD_AUTOSIZE ? calcHeight() : height;
    }

    RECT Canvas::getMargin() {
        return margin;
    }
    
    RECT Canvas::getPadding() {
        return padding;
    }

    int Canvas::getBgColor() {
        return getPushed() ? GD_PSBGCOLOR : bgcolor;
    }

    int Canvas::getBrColor() {
        return getHighlighted() ? GD_HLBRCOLOR : brcolor;
    }
    
    bool Canvas::getDisabled() {
        return disabled;
    }

    bool Canvas::getHighlighted() {
        return getDisabled() ? false : highlighted;
    }

    bool Canvas::getPushed() {
        return getDisabled() ? false : pushed;
    }

    void Canvas::setTop(int top) {
        this->top = top;
        changed = true;
    }

    void Canvas::setLeft(int left) {
        this->left = left;
        changed = true;
    }

    void Canvas::setWidth(int width) {
        this->width = width;
        changed = true;
    }

    void Canvas::setHeight(int height) {
        this->height = height;
        changed = true;
    }
    
    void Canvas::setMargin(RECT margin) {
        this->margin = margin;
        changed = true;
    }

    void Canvas::setPadding(RECT padding) {
        this->padding = padding;
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
    
    void Canvas::setDisabled(bool disabled) {
        this->disabled = disabled;
        changed = true;
    }

    void Canvas::setHighlighted(bool highlighted) {
        this->highlighted = getDisabled() ? false : highlighted;
        changed = true;
    }

    void Canvas::setPushed(bool pushed) {
        this->pushed = getDisabled() ? false : pushed;
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
    
//    void Canvas::join(Container* container) {
//        this->container = container;
//    }


    void Canvas::onTick() {}

    void Canvas::onClick(int x, int y) {
        printf("Click on elem[%d]\n", getId());
    }

    void Canvas::onDblClick(int x, int y) {}

    void Canvas::onMouseMove(int x, int y, int prevx, int prevy) {}

    void Canvas::onMouseOver(int x, int y) {}

    void Canvas::onMouseLeave(int x, int y) {}

    void Canvas::onMouseDown(int x, int y) {}

    void Canvas::onMouseUp(int x, int y) {}



    // ---- protected
    
    bool Canvas::isAutoPositioned() {
        return top == GD_AUTOPOSITION || left == GD_AUTOPOSITION;
    }

    int Canvas::calcWidth() {
        return GD_CANVAS_WIDTH;
    }

    int Canvas::calcHeight() {
        return GD_CANVAS_HEIGHT;
    }

}
