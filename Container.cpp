#include "Container.h"

namespace GUI {
    
    Container::Container(int top, int left, const char* text, int width, int height,
        int bgcolor, int txcolor, int brcolor):
            Label(top, left, text, width, height, bgcolor, txcolor, brcolor) {
        cleanup();
    }

    void Container::cleanup() {
        // clean canvases
        for (int i=0; i < CANVASES; i++) {
            canvases[i] = NULL;
        }
        changed = true;
    }


    void Container::add(Canvas* canvas) {
        for (int i=0; i < CANVASES; i++) {
            if (NULL == canvases[i]) {
                canvases[i] = canvas;
                break;
            }
        }
    }

    void Container::tick() {
        Canvas::tick();
        // for each canvases..
        for (int i=0; i < CANVASES; i++) {
            if (NULL != canvases[i]) {
                canvases[i]->tick();
            }
        }
    }
    
    bool Container::draw() {
        if(Label::draw()) {
            // for each canvases..
            for (int i=0; i < CANVASES; i++) {
                if (NULL != canvases[i]) {
                    canvases[i]->draw();
                }
            }
            return true;
        }
        return false;
    }
}
