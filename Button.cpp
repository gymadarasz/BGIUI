#include "Button.h"

namespace GUI {

    Button::Button(Container* container): Label(container) {
        setup();
    }
    
    Button* Button::setup(
        const char* text,
        int top,
        int left,
        int width,
        int height,
        RECT margin,
        RECT padding,
        int bgcolor,
        int txcolor,
        int brcolor
    ) {
        Label::setup(text, top, left, width, height, margin, padding, bgcolor, txcolor, brcolor);
        setDisabled(false);
        return this;
    }

//    void Button::onMouseOver(int x, int y) {
//        Canvas::onMouseOver(x, y);
//    }
//
//    void Button::onMouseLeave(int x, int y) {
//        Canvas::onMouseLeave(x, y);
//    }
    
    void Button::onMouseDown(int x, int y) {
        setPushed(true);
    }

    void Button::onMouseUp(int x, int y) {
        setPushed(false);
    }

    // ---- protected
//
//    int Button::calcWidth() {
//        return textwidth((char*)getText()) + GD_BTN_WPADDING*2;
//    }
//
//    int Button::calcHeight() {
//        return textheight((char*)getText()) + GD_BTN_HPADDING*2;
//    }

}

