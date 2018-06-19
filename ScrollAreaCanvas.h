/*
 * ScrollAreaCanvas.h
 *
 *  Created on: Jun 18, 2018
 *      Author: Gyula
 */

#ifndef SCROLLAREACANVAS_H_
#define SCROLLAREACANVAS_H_

#include "Canvas.h"
#include "Scroll.h"

namespace GUI {

class ScrollAreaCanvas: public Canvas {
public:
	ScrollAreaCanvas(Canvas* parent = 0);
	virtual void onClick(int mouseLeft, int mouseTop);
	virtual void onMouseDrag(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent);
};

} /* namespace GUI */

#endif /* SCROLLAREACANVAS_H_ */
