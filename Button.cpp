#include "Button.h"

namespace GUI {

    Button::Button(Canvas* parent): Label(parent) {
        setup();
    }
    
    Button* Button::setup(
        const char* text,
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
        Label::setup(text, top, left, width, height, margin, padding, bgcolor, txcolor, brcolor);
        setDisabled(false);
        onMouseDown = onButtonMouseDown;
        onMouseUp = onButtonMouseUp;
        onMouseLeave = onButtonMouseLeave;
        return this;
    }

    int onButtonMouseDown(Canvas* button, ...) {
        button->setPushed(true);
        return 0;
    }

    int onButtonMouseUp(Canvas* button, ...) {
        button->setPushed(false);
        return 0;
    }

    int onButtonMouseLeave(Canvas* button, ...) {
        button->setPushed(false);
        return 0;
    }

}


