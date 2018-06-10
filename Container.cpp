#include "Container.h"

namespace GUI {
    
    Container::Container(int top, int left, int width, int height) {
        offset.y = top;
        offset.x = left;
        size.x = width;
        size.y = height;
        setCursor(0, 0);
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
    
    void Container::ticks() {
        setCursor(0, 0);
        // for each canvases..
        for (int i=0; i < CANVASES; i++) {
            if (NULL != canvases[i]) {
                if (canvases[i]->isAutoPositioned()) {
                    stepCursor(canvases[i]);
                }
                canvases[i]->tick();
            }
        }
    }

    bool Container::draws() {
        setCursor(0, 0);
        // for each canvases..
        for (int i=0; i < CANVASES; i++) {
            if (NULL != canvases[i]) {
                if (canvases[i]->isAutoPositioned()) {
                    stepCursor(canvases[i]);
                }
                canvases[i]->draw();
            }
        }
    }

    bool Container::stepCursor(Canvas* canvas) {

        cursor.previous.x = cursor.position.x;
        cursor.previous.y = cursor.position.y;

        if (canvas->isAutoPositioned()) {
            int canvasFullWidth = canvas->getFullWidth();
            int canvasFullHeight = canvas->getFullHeight();
            cursor.position.x += canvasFullWidth;
            cursor.floatMax = canvasFullHeight > cursor.floatMax ? canvasFullHeight : cursor.floatMax;
            if (cursor.position.x > size.x) {
                breakCursor();
                if (cursor.position.y + canvasFullHeight > size.x) {
                    printf("canvas[%d] overflows\n", canvas->getId());
                    return false;
                }
            }
        }
        return true;
    }
    
    // carriage return and start a new line
    void Container::breakCursor(int minheight) {
        cursor.previous.x = cursor.position.x;
        cursor.previous.y = cursor.position.y;
        cursor.position.x = 0;
        cursor.position.y += cursor.floatMax > minheight ? cursor.floatMax : minheight;
        cursor.floatMax = 0;
    }
    
    void Container::setCursor(int x, int y) {
        cursor.position.x = x;
        cursor.position.y = y;
        cursor.previous.x = x;
        cursor.previous.y = y;
        cursor.floatMax = y;
    }
}
