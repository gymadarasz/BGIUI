#ifndef MOUSE_H
#define MOUSE_H

#include <graphics.h>

namespace GUI {
    
    typedef struct {
        bool happend;
        POINT position;
    } MousePointEvent;
    
    typedef struct {
        bool happend;
        POINT current;
        POINT previous;
    } MouseMoveEvent;
    
    
    typedef struct {
        int checks = 0;
        MousePointEvent onClick;
        MousePointEvent onDblClick;
        MouseMoveEvent onMouseMove;
        MousePointEvent onMouseDown;
        MousePointEvent onMouseUp;
    } MouseEvents;

    class Mouse {
    private:
    protected:
        int lastMouseX;
        int lastMouseY;
        MouseEvents events;
    public:
        void check();
        MouseEvents getEvents();
    };

}

#endif
