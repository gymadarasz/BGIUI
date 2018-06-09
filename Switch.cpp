#include "Switch.h"

namespace GUI {

    Switch::Switch(
        App* app, int top, int left, const char* labelOff, const char* labelOn,
        int width, int height,
        int bgcolor, int txcolor, int brcolor):
            Button(app, top, left, labelOff, width, height, bgcolor, txcolor, brcolor) {
        this->labelOff = labelOff;
        this->labelOn = labelOn;
    }

    void Switch::onMouseOver(int x, int y) {
        Canvas::onMouseOver(x, y);
    }

    void Switch::onMouseLeave(int x, int y) {
        Canvas::onMouseLeave(x, y);
    }
    
    void Switch::onMouseDown(int x, int y) {
        setPushed(!getPushed());
        setText(getPushed() ? labelOn : labelOff);
    }
    
    void Switch::onMouseUp(int x, int y) {}

    // ---- protected

    int Switch::calcWidth() {
        int wOff = textwidth((char*)labelOff);
        int wOn = textwidth((char*)labelOn);
        int max = wOff > wOn ? wOff : wOn;

        return max + GD_BTN_WPADDING*2;
    }
    
}

