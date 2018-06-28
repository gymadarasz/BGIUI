/*
 * Mouse.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#ifndef GUI_UIMOUSE_H_
#define GUI_UIMOUSE_H_


#include "../defs.h"

namespace gui {

typedef struct {
	int top;
	int left;
} EventPoint;

typedef struct {
    bool happend;
    EventPoint position;
} EventMousePoint;

typedef struct {
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

class UIMouse {
    int lastMouseLeft;
    int lastMouseTop;
    bool lbtndown;
    MouseEvents events;
    EventPoint* initEventPoint(EventPoint* eventPoint);
    EventMousePoint* initEventMousePoint(EventMousePoint* eventMousePoint);
    EventMouseMove* initEventMouseMove(EventMouseMove* eventMouseMove);
    void initMouseEvents();

public:
    MouseEvents getEvents();
    void reset();
    void check();
};

} /* namespace gui */

#endif /* GUI_UIMOUSE_H_ */
