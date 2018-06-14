#ifndef BUTTON_H
#define BUTTON_H

#include "Label.h"

namespace GUI {
    
    class Button: public Label {
    public:
        Button(Canvas* parent = NULL);
        virtual Button* setup(
            const char* text = "Button",
            int top = GD_AUTOPOSITION,
            int left = GD_AUTOPOSITION,
            int width = GD_AUTOSIZE,
            int height = GD_AUTOSIZE,
            RECT margin = {
                GD_BTN_LMARGIN,
                GD_BTN_RMARGIN,
                GD_BTN_TMARGIN,
                GD_BTN_BMARGIN
            },
            RECT padding = {
                GD_BTN_LPADDING,
                GD_BTN_RPADDING,
                GD_BTN_TPADDING,
                GD_BTN_BPADDING
            },
            int bgcolor = GD_BTN_BGCOLOR,
            int txcolor = GD_BTN_TXCOLOR,
            int brcolor = GD_BTN_BRCOLOR
        );
    };

    int onButtonMouseDown(Canvas*, ...);
    int onButtonMouseUp(Canvas*, ...);
    int onButtonMouseLeave(Canvas*, ...);
}

#endif
