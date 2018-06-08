#include "Button.h"

Button::Button(
    Graph* graph, int top, int left, int width, int height,
    int bgcolor, int txcolor, int brcolor, const char* text):
        Label(graph, top, left, width, height, bgcolor, txcolor, brcolor, text) {
            
}


void Button::onMouseDown(int x, int y) {
    setPushed(true);
}

void Button::onMouseUp(int x, int y) {
    setPushed(false);
}


void Button::onMouseOver(int x, int y) {
    Canvas::onMouseOver(x, y);
}

void Button::onMouseLeave(int x, int y) {
    Canvas::onMouseLeave(x, y);
}

// ---- protected

int Button::calcWidth() {
    return textwidth((char*)getText()) + GD_BTN_WPADDING*2;
}

int Button::calcHeight() {
    return textheight((char*)getText()) + GD_BTN_HPADDING*2;
}

