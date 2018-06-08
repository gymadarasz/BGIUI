#include "Button.h"

namespace GUI {

    Button::Button(
        Graph* graph, int top, int left, const char* text,
        int width, int height,
        int bgcolor, int txcolor, int brcolor):
            Label(graph, top, left, text, width, height, bgcolor, txcolor, brcolor) {

    }
    
    void Button::onMouseDown(int x, int y) {
        setPushed(true);
    }

    void Button::onMouseUp(int x, int y) {
        setPushed(false);
    }

    // ---- protected

    int Button::calcWidth() {
        return textwidth((char*)getText()) + GD_BTN_WPADDING*2;
    }

    int Button::calcHeight() {
        return textheight((char*)getText()) + GD_BTN_HPADDING*2;
    }

}

