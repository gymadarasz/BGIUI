#ifndef BUTTON_H
#define BUTTON_H

#include "Canvas.h"

class Button: public Canvas {
protected:
    int txcolor;
    const char* label;
    int padding;
    virtual int calcWidth();
    virtual int calcHeight();
public:
    Button(
        Graph* graph, int top, int left, int width = GD_AUTO, int height = GD_AUTO,
        int bgcolor = GD_BTN_BGCOLOR, int txcolor = GD_BTN_TXCOLOR, int brcolor = GD_BTN_BRCOLOR,
        const char* label = GD_BTN_TEXT);
    virtual void draw();
    virtual void setLabel(const char* label);
    //virtual void onClick(int x, int y);
};

#endif
