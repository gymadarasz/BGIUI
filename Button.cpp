#include "Button.h"

#include "Graph.h"

Button::Button(
    Graph* graph, int top, int left, int width, int height,
    int bgcolor, int txcolor, int brcolor, const char* text):
        Canvas(graph, top, left, width, height, bgcolor, brcolor) {
    this->txcolor = txcolor;
    this->text = NULL;
    setText(text);
    changed = true;
}

void Button::draw() {
    Canvas::draw();
    int w = textwidth((char*)getText());
    int h = textheight((char*)getText());
    graph->text(top + (getHeight()-h)/2, left + (getWidth()-w)/2, txcolor, getBgColor(), getText());
}

const char* Button::getText() {
    return text;
}

void Button::setText(const char* text) {
    // clear current text first if already set
    if (NULL != getText()) {
        int w = textwidth((char*)getText());
        int h = textheight((char*)getText());
        graph->text(top + (getHeight()-h)/2, left + (getWidth()-w)/2, getBgColor(), getBgColor(), getText());
    }
    this->text = text;
    changed = true;
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

