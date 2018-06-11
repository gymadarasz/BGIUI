#include "Switch.h"

namespace GUI {
    
    Switch::Switch(Container* container): Button(container) {
        setup();
    }

    Switch* Switch::setup(
        const char* labelOff,
        const char* labelOn,
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
        this->labelOff = labelOff;
        this->labelOn = labelOn;
        Button::setup(labelOff, top, left, width, height, margin, padding, bgcolor, txcolor, brcolor);
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

        return max + padding.left + padding.right;
    }
    
}

