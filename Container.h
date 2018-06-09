#ifndef CONTAINER_H
#define CONTAINER_H

#include "Canvas.h"

#define CANVASES 100

namespace GUI {
    
    class Canvas;
    
    class Container {
    protected:
    public:
        POINT offset;
        Canvas* canvases[CANVASES] = {NULL};
        
        Container(int top = 0, int left = 0);
        bool add(Canvas* canvas);
        virtual void ticks();
        virtual bool draws();
    };

}

#endif
