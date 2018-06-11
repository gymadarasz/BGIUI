#ifndef CONTAINER_H
#define CONTAINER_H

#include "Canvas.h"
#include "Cursor.h"

#define CANVASES 100

namespace GUI {
    
    class Canvas;
    

//    
//    typedef struct {
//        int floatMax;
//        POINT prev;
//        POINT curr;
//        POINT next;
//    } ContainerCursor;
    
    
    class Container {
    private:
        //friend Canvas;
        void findNextWidthAndStepCursor(int current);
    protected:
    public:
        POINT offset;
        int width;
        Canvas* canvases[CANVASES] = {NULL};
        Cursor cursor;

        // cursor
//        int lnheight;
//        ContainerCursor cursor;
        
        Container(int top, int left, int width, int heigth);
        bool add(Canvas* canvas);
        virtual void ticks();
        virtual bool draws();
        
//        // cursor
//        virtual void stepCursorNext(Canvas* canvas);
//        virtual void stepCursorPost(Canvas* canvas);
//        virtual void setCursor(int x, int y);
//        virtual void breakCursor(int minheight = 0);
        
    };

}

#endif
