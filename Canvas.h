#ifndef CANVAS_H
#define CANVAS_H

#include <graphics.h>
#include "style.h"
#include "Counted.h"
#include "Container.h"

namespace GUI {

    class Container;

    class Canvas: public Counted {
    private:

        int lastTop;
        int lastLeft;
        int lastWidth;
        int lastHeight;
        

        int top;  // TODO: getter + setter for everything
        int left;
        
        bool isChanged();
        
    protected:
        
        int width;
        int height;
        int bgcolor;
        int brcolor;
        // todo: bool highlightable;
        bool highlighted;
        bool pushed;
        bool changed;
        
        virtual int calcWidth();
        virtual int calcHeight();
        
    public:

        Container* container = {NULL};
        
//        Canvas();
        virtual Canvas* setup(
            int top = 0, int left = 0,
            int width = GD_CANVAS_WIDTH,
            int height = GD_CANVAS_HEIGHT,
            int bgcolor = GD_CANVAS_BGCOLOR,
            int brcolor = GD_CANVAS_BRCOLOR
        );
//        void join(Container* container);
        virtual void tick();
        virtual bool draw();
        virtual void clear();
        virtual bool inside(POINT point);
        virtual RECT* getRect(RECT* rect);
        
        virtual int getTop();
        virtual int getLeft();
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
