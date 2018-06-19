/*
 * ScrollHandlerCanvas.cpp
 *
 *  Created on: Jun 18, 2018
 *      Author: Gyula
 */

#include "ScrollHandlerCanvas.h"

namespace GUI {

// public
ScrollHandlerCanvas::ScrollHandlerCanvas(Canvas* parent): Canvas(parent) {

}

void ScrollHandlerCanvas::onClick(int mouseLeft, int mouseTop) {
	Canvas::onClick(mouseLeft, mouseTop);
// todo??? kell ez?e?
}

} /* namespace GUI */
