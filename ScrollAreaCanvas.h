/*
 * ScrollAreaCanvas.h
 *
 *  Created on: Jun 18, 2018
 *      Author: Gyula
 */

#ifndef SCROLLAREACANVAS_H_
#define SCROLLAREACANVAS_H_

#include "Canvas.h"

namespace GUI {

class ScrollAreaCanvas: public Canvas {
public:
	ScrollAreaCanvas(Canvas* parent = 0);
	virtual void onClick(int mouseLeft, int mouseTop);
};

} /* namespace GUI */

#endif /* SCROLLAREACANVAS_H_ */
