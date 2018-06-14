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

    int Switch::calcWidth() {
        int wOff = textwidth((char*)labelOff); // TODO: use painter instead
        int wOn = textwidth((char*)labelOn);
        int max = wOff > wOn ? wOff : wOn;
        RECT padding = getPadding();
        return max + padding.left + padding.right;
    }

    int onSwitchMouseDown(Canvas* swtch, ...) {
        swtch->setPushed(!swtch->getPushed());
        ((Switch*)swtch)->setText(swtch->getPushed() ? ((Switch*)swtch)->labelOn : ((Switch*)swtch)->labelOff);
        return 0;
    }
    
}

