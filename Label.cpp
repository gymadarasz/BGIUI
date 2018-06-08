#include "Label.h"

#include "Graph.h"

Label::Label(
    Graph* graph, int top, int left, int width, int height,
    int bgcolor, int txcolor, int brcolor, const char* text):
        Canvas(graph, top, left, width, height, bgcolor, brcolor) {
    this->txcolor = txcolor;
    this->text = NULL;
    setText(text);
    changed = true;
}

void Label::draw() {
    Canvas::draw();
    int w = textwidth((char*)getText());
    int h = textheight((char*)getText());
    graph->text(top + (getHeight()-h)/2, left + (getWidth()-w)/2, txcolor, getBgColor(), getText());
}

const char* Label::getText() {
    return text;
}

void Label::setText(const char* text) {
    // clear current text first if already set
    if (NULL != getText()) {
        int w = textwidth((char*)getText());
        int h = textheight((char*)getText());
        graph->text(top + (getHeight()-h)/2, left + (getWidth()-w)/2, getBgColor(), getBgColor(), getText());
    }
    this->text = text;
    changed = true;
}

// ---- protected

int Label::calcWidth() {
    return textwidth((char*)getText()) + GD_LBL_WPADDING*2;  // todo: use class variable instead constants for paddings (here and buttons also!)
}

int Label::calcHeight() {
    return textheight((char*)getText()) + GD_LBL_HPADDING*2;
}
