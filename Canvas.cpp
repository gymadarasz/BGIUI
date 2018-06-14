#include "Canvas.h"

namespace GUI {
    
    Mouse Canvas::mouse;
    Painter Canvas::painter;
    
    Canvas::Canvas(Canvas* parent): Counted() {
        setParent(parent);
        clearEvents();
        setup();
    }
    
    void Canvas::clearEvents() {
        onTick = NULL;
        onClick = NULL;
        onDblClick = NULL;
        onMouseMove = NULL;
        onMouseDrag = NULL;
        onMouseOver = NULL;
        onMouseLeave = NULL;
        onMouseDown = NULL;
        onMouseUp = NULL;
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
        setBreak(false);
        return this;
    }
    
    Canvas* Canvas::setParent(Canvas* parent) {
        if (this->parent != parent) {
            this->parent = parent;
            parent->add(this);
            changed = true;
        }
        return this;
    }
    
    Canvas* Canvas::getParent() {
        return parent;
    }

    bool Canvas::isChanged() {
        bool ret = changed;
        changed = false;
        return ret;
    }

    bool Canvas::isHlBrChanged() {
        bool ret = hlbrchanged;
        hlbrchanged = false;
        return ret;
    }

    
    

    Canvas* Canvas::add(Canvas* canvas) {
        for (int i=0; i < CANVASES; i++) {
            if (NULL == canvases[i]) {
                canvases[i] = canvas;
                canvas->setParent(this); // join canvas into this container
                return canvas;
            }
        }
        printf("container is full of canvases\n");
        return NULL;
    }

    void Canvas::findNextWidthAndStepCursor(int current) {
        if (canvases[current]->isAutoPositioned()) {
            Canvas* _c = NULL;
            int fullWidth = canvases[current]->getFullWidth();
            int fullHeight = canvases[current]->getFullHeight();
            
            _c = NULL;
            for (int j=current+1; j < CANVASES; j++) {
                if (NULL != canvases[j] && canvases[j]->isAutoPositioned()) {
                    _c = canvases[j];
                    break;
                }
            }
            int nxtw = _c?_c->getFullWidth():0;
            cursor.step(fullWidth, fullHeight, nxtw, canvases[current]->br);
        }
    }

    void Canvas::process(int getsizeonly) {
        if (!getsizeonly) {
            process(true);
            tick();
            draw();
        }
        cursor.reset(width);

        // for each canvases..
        for (int i=0; i < CANVASES; i++) {
            if (NULL != canvases[i]) {
                findNextWidthAndStepCursor(i);
                canvases[i]->process(getsizeonly);
            }
        }
    }

    void Canvas::tick() {
        

        if (onTick) {
            onTick(this);
        }

        if (getDisabled()) {
            return ;
        }

        int top = getTop();
        int left = getLeft();
        
        // click?
        if (
            onClick && mouse.events.onClick.happend && inside(mouse.events.onClick.position)) {
            onClick(this, mouse.events.onClick.position.x-left, mouse.events.onClick.position.y-top);
        }

        // dblclick?
        if ((onClick || onDblClick) && mouse.events.onDblClick.happend && inside(mouse.events.onDblClick.position)) {
            if (onDblClick) {
                onDblClick(this, mouse.events.onDblClick.position.x-left, mouse.events.onDblClick.position.y-top);
            }
        }

        // mouse move, over, leave?
        if (mouse.events.onMouseMove.happend) {
            if (onMouseMove && inside(mouse.events.onMouseMove.current) && inside(mouse.events.onMouseMove.previous)) {
                onMouseMove(
                    this,
                    mouse.events.onMouseMove.current.x-left, mouse.events.onMouseMove.current.y-top,
                    mouse.events.onMouseMove.previous.x-left, mouse.events.onMouseMove.previous.y-top
                );
            } else if (inside(mouse.events.onMouseMove.current)) {
                setHighlighted(true);
                if (onMouseOver) {
                    onMouseOver(this, mouse.events.onMouseMove.current.x-left, mouse.events.onMouseMove.current.y-top);
                }
            } else if (inside(mouse.events.onMouseMove.previous)) {
                setHighlighted(false);
                if (onMouseLeave) {
                    onMouseLeave(this, mouse.events.onMouseMove.previous.x-left, mouse.events.onMouseMove.previous.y-top);
                }
            }
        }
        
        if (mouse.events.onMouseDrag.happend) {
            if (onMouseDrag && inside(mouse.events.onMouseDrag.current) && inside(mouse.events.onMouseDrag.previous)) {
                onMouseDrag(
                    this,
                    mouse.events.onMouseDrag.current.x-left, mouse.events.onMouseDrag.current.y-top,
                    mouse.events.onMouseDrag.previous.x-left, mouse.events.onMouseDrag.previous.y-top
                );
            }
        }

        // mouse down?
        if (onMouseDown && mouse.events.onMouseDown.happend && inside(mouse.events.onMouseDown.position)) {
            onMouseDown(this, mouse.events.onMouseDown.position.x-left, mouse.events.onMouseDown.position.y-top);
        }

        // mouse up?
        if (onMouseUp && mouse.events.onMouseUp.happend && inside(mouse.events.onMouseUp.position)) {
            onMouseUp(this, mouse.events.onMouseUp.position.x-left, mouse.events.onMouseUp.position.y-top);
        }

    }
    
    bool Canvas::draw() {
        bool chg = isChanged();
        bool hlchg = isHlBrChanged();
        if (chg || hlchg) {
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
            if (hlchg) {
                // todo: use class variable instead GD_BRSIZE
                painter.box(top-GD_BRSIZE, left-GD_BRSIZE, width+GD_BRSIZE, height+GD_BRSIZE, getBrColor(), GD_NOFILL);
            }
            if (chg) {
                painter.box(top, left, width, height, getBgColor(), GD_FILL);
            }
            lastTop = top;
            lastLeft = left;
            lastWidth = width;
            lastHeight = height;
            return true;
        }
        return false;
    }
    
    void Canvas::clear() {
        int top = lastTop;
        int left = lastLeft;
        int width = lastWidth;
        int height = lastHeight;
        int bgcolor = getBgColor();
        painter.box(top-GD_BRSIZE, left-GD_BRSIZE, width+GD_BRSIZE*2, height+GD_BRSIZE*2, bgcolor, GD_FILL);
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
        int ret = NULL == parent ? top : parent->getTop(); //parent->offset.y;
        ret += top == GD_AUTOPOSITION ? parent->cursor.getpositiony() : top;
        return ret;
    }
    
    int Canvas::getLeft() {
        int ret = NULL == parent ? left : parent->getLeft();  // container->offset.x;
        ret += left == GD_AUTOPOSITION ? parent->cursor.getpositionx() : left;
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
        return getPushed() ? GD_PSBGCOLOR : (bgcolor == GD_NOCOLOR ? (parent ? parent->getBgColor() : bgcolor) : bgcolor);
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
        if (this->top != top) {
            this->top = top;
            changed = true;
        }
    }

    void Canvas::setLeft(int left) {
        if (this->left != left) {
           this->left = left;
           changed = true;
        }
    }

    void Canvas::setWidth(int width) {
        if (this->width != width) {
            this->width = width;
            changed = true;
        }
    }

    void Canvas::setHeight(int height) {
        if (this->height != height) {
            this->height = height;
            changed = true;
        }
    }
    
    bool Canvas::RectEqu(RECT r1, RECT r2) {
        return
            r1.top == r2.top &&
            r1.left == r2.left &&
            r1.bottom == r2.bottom &&
            r1.right == r2.right;
    }
    
    void Canvas::setMargin(RECT margin) {
        if (!RectEqu(this->margin, margin)) {
            this->margin = margin;
            changed = true;
        }
    }

    void Canvas::setPadding(RECT padding) {
        if (!RectEqu(this->padding, padding)) {
            this->padding = padding;
            changed = true;
        }
    }

    void Canvas::setBgColor(int bgcolor) {
        if (this->bgcolor != bgcolor) {
            this->bgcolor = bgcolor;
            changed = true;
        }
    }

    void Canvas::setBrColor(int brcolor) {
        if (this->brcolor != brcolor) {
            this->brcolor = brcolor;
            hlbrchanged = true;
        }
    }
    
    void Canvas::setDisabled(bool disabled) {
        if (this->disabled != disabled) {
            this->disabled = disabled;
            changed = true;
        }
    }

    void Canvas::setHighlighted(bool highlighted) {
        bool newhl = getDisabled() ? false : highlighted;
        if (this->highlighted != newhl) {
            this->highlighted = newhl;
            hlbrchanged = true;
        }
    }

    void Canvas::setPushed(bool pushed) {
        bool newps = getDisabled() ? false : pushed;
        if (this->pushed != newps) {
            this->pushed = newps;
            changed = true;
        }
    }

    void Canvas::setChanged(bool changed) {
        this->changed = changed;
    }

    void Canvas::setBreak(bool br) {
        if (this->br != br) {
            this->br = br;
            changed = true;
        }
    }

    bool Canvas::inside(POINT point) {
        RECT rect;
        getRect(&rect);
        return point.x >= rect.left && point.x <= rect.right && point.y >= rect.top && point.y <= rect.bottom;
    }
    
    bool Canvas::isAutoPositioned() {
        return top == GD_AUTOPOSITION || left == GD_AUTOPOSITION;
    }

    int Canvas::calcWidth() {
        int w = cursor.getwidth();
        if (w == GD_AUTOSIZE) {
            //process(true);
            w = cursor.getwidth();
        }
        return w;
    }

    int Canvas::calcHeight() {
        int h = cursor.getheight();
        if (h == GD_AUTOSIZE) {
            //process(true);
            h = cursor.getwidth();
        }
        return h;
    }

}
