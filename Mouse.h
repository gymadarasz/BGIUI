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
	int top;
	int left;
} EventPoint;

typedef struct {
    bool happend;
    EventPoint position;
} EventMousePoint;

typedef struct{
    bool happend;
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
    static int lastMouseLeft;
    static int lastMouseTop;
    static bool lbtndown;
public:
    static MouseEvents events;
    static void reset();
    static void check();
};

} /* namespace GUI */

#endif /* MOUSE_H_ */
