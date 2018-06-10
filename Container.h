#ifndef CONTAINER_H
#define CONTAINER_H

#include "Canvas.h"

#define CANVASES 100

namespace GUI {
    
    typedef struct {
        int floatMax;
        POINT previous;
        POINT position;
    } ContainerCursor;
    
    class Canvas;
    
    class Container {
    private:
        //friend Canvas;
    protected:
    public:
        POINT offset;
        POINT size;
        Canvas* canvases[CANVASES] = {NULL};

        // cursor
        ContainerCursor cursor;
        
        Container(int top, int left, int width, int heigth);
        bool add(Canvas* canvas);
        virtual void ticks();
        virtual bool draws();
        
        // cursor
        virtual bool stepCursor(Canvas* canvas);
        virtual void setCursor(int x, int y);
        virtual void breakCursor(int minheight = 0);
        
    };

}

#endif
