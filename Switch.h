#ifndef SWITCH_H
#define SWITCH_H

#include "Button.h"

class Switch: public Button {
protected:
    const char* labelOff;
    const char* labelOn;
    virtual int calcWidth();
public:
    Switch(
        Graph* graph, int top, int left, int width = GD_AUTO, int height = GD_AUTO,
        int bgcolor = GD_SWITCH_BGCOLOR, int txcolor = GD_SWITCH_TXCOLOR, int brcolor = GD_SWITCH_BRCOLOR,
        const char* labelOff = GD_SWITCH_OFF_TEXT, const char* labelOn = GD_SWITCH_ON_TEXT);
//    virtual void draw();
    virtual void onMouseDown(int x, int y);
    virtual void onMouseUp(int x, int y);
};

#endif
