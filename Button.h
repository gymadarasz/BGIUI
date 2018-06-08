#ifndef BUTTON_H
#define BUTTON_H

#include "Label.h"

class Button: public Label {
protected:
    virtual int calcWidth();
    virtual int calcHeight();
public:
    Button(
        Graph* graph, int top, int left, int width = GD_AUTO, int height = GD_AUTO,
        int bgcolor = GD_BTN_BGCOLOR, int txcolor = GD_BTN_TXCOLOR, int brcolor = GD_BTN_BRCOLOR,
        const char* text = GD_BTN_TEXT);
    virtual void onMouseDown(int x, int y);
    virtual void onMouseUp(int x, int y);
    virtual void onMouseOver(int x, int y);
    virtual void onMouseLeave(int x, int y);
};

#endif
