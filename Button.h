#ifndef BUTTON_H
#define BUTTON_H

#include "Canvas.h"

class Button: public Canvas {
protected:
    int color;
    char* label;
public:
    Button(Graph* graph, int top, int left, int width, int height, int bgcolor, int color, char* label);
    void draw();
    virtual void onClick(int x, int y);
};

#endif
