#include "Button.h"

#include "Graph.h"

Button::Button(
    Graph* graph, int top, int left, int width, int height,
    int bgcolor, int txcolor, int brcolor, const char* label):
        Canvas(graph, top, left, width, height, bgcolor, brcolor) {
    this->txcolor = txcolor;
    setLabel(label);
    changed = true;
}

void Button::draw() {
    Canvas::draw();
    int w = textwidth((char*)label);
    int h = textheight((char*)label);
    graph->text(top + (getHeight()-h)/2, left + (getWidth()-w)/2, txcolor, bgcolor, label);
}

void Button::setLabel(const char* label) {
    // clear current label first if already set
    if (this->label) {
        int w = textwidth((char*)this->label);
        int h = textheight((char*)this->label);
        graph->text(top + (getHeight()-h)/2, left + (getWidth()-w)/2, bgcolor, bgcolor, this->label);
    }
    this->label = label;
    changed = true;
}

//void Button::onClick(int x, int y) {
//    printf("Button::onClick\n");
//}


// ---- protected

int Button::calcWidth() {
    return textwidth((char*)label) + GD_BTN_WPADDING*2;
}

int Button::calcHeight() {
    return textheight((char*)label) + GD_BTN_HPADDING*2;
}

