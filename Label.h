#ifndef LABEL_H
#define LABEL_H

#include "Canvas.h"

class Label: public Canvas {
protected:
    int txcolor;
    const char* text;
    virtual int calcWidth();
    virtual int calcHeight();
public:
    Label(
        Graph* graph, int top, int left, int width = GD_AUTO, int height = GD_AUTO,
        int bgcolor = GD_LBL_BGCOLOR, int txcolor = GD_LBL_TXCOLOR, int brcolor = GD_LBL_BRCOLOR,
        const char* text = GD_LBL_TEXT);
    virtual void draw();
    virtual const char* getText();
    virtual void setText(const char* text);
};

#endif
