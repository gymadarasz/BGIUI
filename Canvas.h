#ifndef CANVAS_H
#define CANVAS_H

#include <graphics.h>
#include "style.h"

namespace GUI {

    class Canvas {
    private:
        static int nxt;

        int lastTop;
        int lastLeft;
        int lastWidth;
        int lastHeight;
        bool isChanged();
        
    protected:
        
        int id;
        int top;  // TODO: getter + setter for everything
        int left;
        int width;
        int height;
        int bgcolor;
        int brcolor;
        bool highlighted;
        bool pushed;
        bool changed;
        virtual int calcWidth();
        virtual int calcHeight();
    public:
        
        Canvas(
            int top, int left, int width = GD_AUTO, int height = GD_AUTO,
            int bgcolor = GD_CANVAS_BGCOLOR, int brcolor = GD_CANVAS_BRCOLOR);
        virtual void tick();
        virtual bool draw();
        virtual void clear();
        virtual bool inside(POINT point);
        virtual RECT* getRect(RECT* rect);
//        virtual void setContainer(Container* container);
//        Container* getContainer();
        
        virtual int getWidth();
        virtual int getHeight();
        virtual int getBgColor();
        virtual int getBrColor();
        virtual bool getHighlighted();
        virtual bool getPushed();
        
        virtual void setWidth(int width);
        virtual void setHeight(int height);
        virtual void setBgColor(int bgcolor);
        virtual void setBrColor(int brcolor);
        virtual void setHighlighted(bool highlighted);
        virtual void setPushed(bool pushed);
        
        virtual void onTick();
        virtual void onClick(int x, int y);
        virtual void onDblClick(int x, int y);
        virtual void onMouseMove(int x, int y, int prevx, int prevy);
        virtual void onMouseOver(int x, int y);
        virtual void onMouseLeave(int x, int y);
        virtual void onMouseDown(int x, int y);
        virtual void onMouseUp(int x, int y);
    };

}
#endif
