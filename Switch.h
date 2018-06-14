#ifndef SWITCH_H
#define SWITCH_H

#include "Button.h"

namespace GUI {

    class Switch: public Button {
    protected:
        virtual int calcWidth();
    public:
        const char* labelOff;
        const char* labelOn;
        
        Switch(Canvas* parent = NULL);
        virtual Switch* setup(
            const char* labelOff = "Off",
            const char* labelOn = "On",
            int top = GD_AUTOPOSITION,
            int left = GD_AUTOPOSITION,
            int width = GD_AUTOSIZE,
            int height = GD_AUTOSIZE,
            RECT margin = {
                GD_SWITCH_LMARGIN,
                GD_SWITCH_RMARGIN,
                GD_SWITCH_TMARGIN,
                GD_SWITCH_BMARGIN
            },
            RECT padding = {
                GD_SWITCH_LPADDING,
                GD_SWITCH_RPADDING,
                GD_SWITCH_TPADDING,
                GD_SWITCH_BPADDING
            },
            int bgcolor = GD_SWITCH_BGCOLOR,
            int txcolor = GD_SWITCH_TXCOLOR,
            int brcolor = GD_SWITCH_BRCOLOR
        );
    };

//    int onSwitchMouseOver(Canvas* swtch, ...);
//    int onSwitchMouseLeave(Canvas* swtch, ...);
    int onSwitchMouseDown(Canvas* swtch, ...);
//    int onSwitchMouseUp(Canvas* swtch, ...);
}

#endif
