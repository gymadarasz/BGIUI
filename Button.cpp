#include "Button.h"

namespace GUI {

    Button::Button(
        App* app, int top, int left, const char* text,
        int width, int height,
        int bgcolor, int txcolor, int brcolor):
            Label(app, top, left, text, width, height, bgcolor, txcolor, brcolor) {

    }

    void Button::onMouseOver(int x, int y) {
        Canvas::onMouseOver(x, y);
    }

    void Button::onMouseLeave(int x, int y) {
        Canvas::onMouseLeave(x, y);
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

