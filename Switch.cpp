#include "Switch.h"

#include "Graph.h"

Switch::Switch(
    Graph* graph, int top, int left, int width, int height,
    int bgcolor, int txcolor, int brcolor, const char* labelOff, const char* labelOn):
        Button(graph, top, left, width, height, bgcolor, txcolor, brcolor, labelOff) {
    this->labelOff = labelOff;
    this->labelOn = labelOn;
    on = false;
}

void Switch::draw() {
    Button::draw();
}

void Switch::onClick(int x, int y) {
    on = !on;
    setLabel(on ? labelOn : labelOff);
}

void Switch::onDblClick(int x, int y) {
    onClick(x, y);
}

// ---- protected

int Switch::calcWidth() {
    int wOff = textwidth((char*)labelOff);
    int wOn = textwidth((char*)labelOn);
    int max = wOff > wOn ? wOff : wOn;
    
    return max + GD_BTN_WPADDING*2;
}
