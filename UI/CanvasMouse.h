/*
 * Mouse.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#ifndef GUI_CANVASMOUSE_H_
#define GUI_CANVASMOUSE_H_


#include "../guidefs.h"

namespace gui {

typedef struct {
	int top;
	int left;
} CanvasEventPoint;

typedef struct {
    bool happend;
    CanvasEventPoint position;
} CanvasEventMousePoint;

typedef struct {
    bool happend;
    CanvasEventPoint current;
    CanvasEventPoint previous;
} CanvasEventMouseMove;


typedef struct {
    CanvasEventMousePoint click;
    CanvasEventMousePoint dblClick;
    CanvasEventMouseMove mouseMove;
    CanvasEventMouseMove mouseDrag;
    CanvasEventMousePoint mouseDown;
    CanvasEventMousePoint mouseUp;
} CanvasMouseEvents;

class CanvasMouse {
    int lastMouseLeft;
    int lastMouseTop;
    bool lbtndown;
    CanvasMouseEvents events;
    CanvasEventPoint* initEventPoint(CanvasEventPoint* eventPoint);
    CanvasEventMousePoint* initEventMousePoint(CanvasEventMousePoint* eventMousePoint);
    CanvasEventMouseMove* initEventMouseMove(CanvasEventMouseMove* eventMouseMove);
    void initMouseEvents();

public:
    CanvasMouseEvents getEvents();
    void reset();
    void check();
};

} /* namespace gui */

#endif /* GUI_CANVASMOUSE_H_ */
