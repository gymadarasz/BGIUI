#ifndef SWITCH_H
#define SWITCH_H

#include "Button.h"

class Switch: public Button {
protected:
    bool on;
    const char* labelOff;
    const char* labelOn;
public:
    Switch(Graph* graph, int top, int left, int width = GD_SWITCH_WIDTH, int height = GD_SWITCH_HEIGHT, int bgcolor = GD_SWITCH_BGCOLOR, int color = GD_SWITCH_COLOR, const char* labelOff = GD_SWITCH_OFF_TEXT, const char* labelOn = GD_SWITCH_ON_TEXT, int padding = GD_SWITCH_PADDING);
    virtual void onClick(int x, int y);
    virtual void onDblClick(int x, int y);
};

#endif
