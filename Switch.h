#ifndef SWITCH_H
#define SWITCH_H

#include "Button.h"

class Switch: public Button {
protected:
    bool on;
    const char* labelOff;
    const char* labelOn;
    virtual int calcWidth();
public:
    Switch(
        Graph* graph, int top, int left, int width = GD_AUTO, int height = GD_AUTO,
        int bgcolor = GD_SWITCH_BGCOLOR, int txcolor = GD_SWITCH_TXCOLOR, int brcolor = GD_SWITCH_BRCOLOR,
        const char* labelOff = GD_SWITCH_OFF_TEXT, const char* labelOn = GD_SWITCH_ON_TEXT);
    virtual void draw();
    virtual void onClick(int x, int y);
    virtual void onDblClick(int x, int y);
};

#endif
