#include "Switch.h"

Switch::Switch(Graph* graph, int top, int left, int width, int height, int bgcolor, int color, const char* labelOff, const char* labelOn, int padding): Button(graph, top, left, width, height, bgcolor, color, labelOff, padding) {
    this->labelOff = labelOff;
    this->labelOn = labelOn;
    on = false;
}

void Switch::onClick(int x, int y) {
    on = !on;
    setLabel(on ? labelOn : labelOff);
    draw();
}

void Switch::onDblClick(int x, int y) {
    onClick(x, y);
}
