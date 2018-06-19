/*
 * ScrollHandlerCanvas.h
 *
 *  Created on: Jun 18, 2018
 *      Author: Gyula
 */

#ifndef SCROLLHANDLERCANVAS_H_
#define SCROLLHANDLERCANVAS_H_

#include "Canvas.h"

namespace GUI {

class ScrollHandlerCanvas: public Canvas {
public:
	ScrollHandlerCanvas(Canvas* parent = 0);
	virtual void onClick(int mouseLeft, int mouseTop);
};

} /* namespace GUI */

#endif /* SCROLLHANDLERCANVAS_H_ */
