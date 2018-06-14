#ifndef MOUSE_H
#define MOUSE_H

#include <graphics.h>

namespace GUI {
    
    typedef struct {
        bool happend;
        POINT position;
    } MousePointEvent;
    
    typedef struct{
        bool happend;
        POINT current;
        POINT previous;
    } MouseMoveEvent;
    
    
    typedef struct {
        MousePointEvent onClick;
        MousePointEvent onDblClick;
        MouseMoveEvent onMouseMove;
        MouseMoveEvent onMouseDrag;
        MousePointEvent onMouseDown;
        MousePointEvent onMouseUp;
    } MouseEvents;

    class Mouse {
    private:
        int lastMouseX;
        int lastMouseY;
        bool lbtndown;
    public:
        MouseEvents events;
        Mouse();
        void check();
    };

}

#endif
