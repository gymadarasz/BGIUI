#include "Switch.h"

#include "Graph.h"

Switch::Switch(
    Graph* graph, int top, int left, int width, int height,
    int bgcolor, int txcolor, int brcolor, const char* labelOff, const char* labelOn):
        Button(graph, top, left, width, height, bgcolor, txcolor, brcolor, labelOff) {
    this->labelOff = labelOff;
    this->labelOn = labelOn;
}

//void Switch::draw() {
//    Button::draw();
//}

void Switch::onMouseDown(int x, int y) {
    setPushed(!getPushed());
    setText(getPushed() ? labelOn : labelOff);
}

void Switch::onMouseUp(int x, int y) {

}

// ---- protected

int Switch::calcWidth() {
    int wOff = textwidth((char*)labelOff);
    int wOn = textwidth((char*)labelOn);
    int max = wOff > wOn ? wOff : wOn;
    
    return max + GD_BTN_WPADDING*2;
}
