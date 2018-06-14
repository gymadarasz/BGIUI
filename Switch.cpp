#include "Switch.h"

namespace GUI {
    
    Switch::Switch(Canvas* parent): Button(parent) {
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
        onMouseDown = onSwitchMouseDown;
        onMouseUp = NULL;
        return this;
    }



    // ---- protected

    int Switch::calcWidth() {
        int wOff = textwidth((char*)labelOff);
        int wOn = textwidth((char*)labelOn);
        int max = wOff > wOn ? wOff : wOn;

        return max + padding.left + padding.right;
    }
    
//    // -- events
//    int onSwitchMouseOver(Canvas* swtch, ...) {
//        swtch->onMouseOver(x, y);
//    }
//
//    int onSwitchMouseLeave(Canvas* swtch, ...) {
//        Canvas::onMouseLeave(x, y);
//    }

    int onSwitchMouseDown(Canvas* swtch, ...) {
        swtch->setPushed(!swtch->getPushed());
        ((Switch*)swtch)->setText(swtch->getPushed() ? ((Switch*)swtch)->labelOn : ((Switch*)swtch)->labelOff);
        return 0;
    }

//    int onSwitchMouseUp(Canvas* swtch, ...) {}
    
}

