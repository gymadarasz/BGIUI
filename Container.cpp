#include "Container.h"

namespace GUI {
    
    Container::Container(int top, int left) {
        offset.y = top;
        offset.x = left;
    }


    bool Container::add(Canvas* canvas) {
        for (int i=0; i < CANVASES; i++) {
            if (NULL == canvases[i]) {
                canvases[i] = canvas;
                canvas->container = this; // join canvas into this container
                return true;
            }
        }
        return false;
    }
    
    void Container::ticks() {
        // for each canvases..
        for (int i=0; i < CANVASES; i++) {
            if (NULL != canvases[i]) {
                canvases[i]->tick();
            }
        }
    }

    bool Container::draws() {
        // for each canvases..
        for (int i=0; i < CANVASES; i++) {
            if (NULL != canvases[i]) {
                canvases[i]->draw();
            }
        }
    }
}
