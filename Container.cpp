#include "Container.h"

namespace GUI {
    
    Container::Container(int top, int left, int width, int height) {
        (new Canvas(this))->setup(0, 0, width, height, GD_NOMARGIN, GD_NOPADDING, GD_NOCOLOR);
        offset.y = top;
        offset.x = left;
        this->width = width;
        cursor.reset(width);
    }


    bool Container::add(Canvas* canvas) {
        for (int i=0; i < CANVASES; i++) {
            if (NULL == canvases[i]) {
                canvases[i] = canvas;
                //floatCanvas(canvas);
                canvas->setContainer(this); // join canvas into this container
                return true;
            }
        }
        printf("container is full\n");
        return false;
    }
    
    void Container::findNextWidthAndStepCursor(int current) {
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
            cursor.step(fullWidth, fullHeight, nxtw);
        }
    }
    
    void Container::ticks() {
        cursor.reset(width);
        // for each canvases..
        for (int i=0; i < CANVASES; i++) {
            if (NULL != canvases[i]) {
                findNextWidthAndStepCursor(i);
                canvases[i]->tick();
            }
        }
    }

    bool Container::draws() {
        cursor.reset(width);
        // for each canvases..
        for (int i=0; i < CANVASES; i++) {
            if (NULL != canvases[i]) {
                findNextWidthAndStepCursor(i);
                canvases[i]->draw();
            }
        }
    }
//
//    void Container::stepCursorNext(Canvas* canvas) {
//
//        if (canvas->isAutoPositioned()) {
//            
//
//            int canvasFullWidth = canvas->getFullWidth();
//            int canvasFullHeight = canvas->getFullHeight();
//            
//
//            if (cursor.position.x + canvasFullWidth >= size.x) {
//                breakCursor(lnheight);
//                if (cursor.position.y + canvasFullHeight > size.y) {
//                    printf("canvas[%d] overflows\n", canvas->getId());
//                }
//            } else {
//                cursor.next.x += canvasFullWidth;
//                cursor.floatMax = canvasFullHeight > cursor.floatMax ? canvasFullHeight : cursor.floatMax;
//            }
//            
//        }
//    }
//    
//    void Container::stepCursorPost(Canvas* canvas) {
//        if (canvas->isAutoPositioned()) {
//            cursor.position = cursor.next;
//        }
//    }
//    
//    // carriage return and start a new line
//    void Container::breakCursor(int minheight) {
//        cursor.next.x = 0;
//        cursor.next.y += cursor.floatMax > minheight ? cursor.floatMax : minheight;
//        cursor.floatMax = 0;
//    }
//    
//    void Container::setCursor(int x, int y) {
//        cursor.position.x = x;
//        cursor.position.y = y;
//        cursor.next.x = x;
//        cursor.next.y = y;
//        cursor.floatMax = 0;
//    }
}
