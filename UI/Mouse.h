/*
 * Mouse.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#ifndef MOUSE_H_
#define MOUSE_H_

#include <graphics.h>

namespace gui {

typedef struct {
	int top = -1;
	int left = -1;
} EventPoint;

typedef struct {
    bool happend = false;
    EventPoint position;
} EventMousePoint;

typedef struct{
    bool happend = false;
    EventPoint current;
    EventPoint previous;
} EventMouseMove;


typedef struct {
    EventMousePoint click;
    EventMousePoint dblClick;
    EventMouseMove mouseMove;
    EventMouseMove mouseDrag;
    EventMousePoint mouseDown;
    EventMousePoint mouseUp;
} MouseEvents;

class Mouse {
    int lastMouseLeft;
    int lastMouseTop;
    bool lbtndown;
    MouseEvents events;
public:
    MouseEvents getEvents();
    void reset();
    void check();
};

} /* namespace GUI */

#endif /* MOUSE_H_ */
