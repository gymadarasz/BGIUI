#ifndef BUTTON_H
#define BUTTON_H

#include "Canvas.h"

class Button: public Canvas {
protected:
    int color;
    const char* label;
    int padding;
public:
    Button(Graph* graph, int top, int left, int width = GD_BTN_WIDTH, int height = GD_BTN_HEIGHT, int bgcolor = GD_BTN_BGCOLOR, int color = GD_BTN_COLOR, const char* label = GD_BTN_TEXT, int padding = GD_BTN_PADDING);
    void draw();
    void setLabel(const char* label);
    //virtual void onClick(int x, int y);
};

#endif
