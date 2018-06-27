/*
 * Mouse.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#include "../UI/Mouse.h"

namespace gui {

MouseEvents Mouse::getEvents() {
	return events;
}

void Mouse::reset() {
	lastMouseLeft = mousex();
	lastMouseTop = mousey();
	lbtndown = false;
}

void Mouse::check() {
	int top, left;

	// mouse released (mouse up)?
	events.mouseUp.happend = false;
	if (ismouseclick(WM_LBUTTONUP)) {
		getmouseclick(WM_LBUTTONUP, left, top);
		events.mouseUp.happend = true;
		events.mouseUp.position.left = left;
		events.mouseUp.position.top = top;
		lbtndown = false;
	}

	// any mouse click event (or mouse down - same thing..)?
	events.mouseDown.happend = false;
	events.click.happend = false;
	if (ismouseclick(WM_LBUTTONDOWN)) {
		getmouseclick(WM_LBUTTONDOWN, left, top);
		events.mouseDown.happend = true;
		events.mouseDown.position.left = left;
		events.mouseDown.position.top = top;
		events.click.happend = true;
		events.click.position.left = left;
		events.click.position.top = top;
		lbtndown = true;
	}

	// double click?
	events.dblClick.happend = false;
	if (ismouseclick(WM_LBUTTONDBLCLK)) {
		getmouseclick(WM_LBUTTONDBLCLK, left, top);
		events.mouseDown.happend = true;
		events.mouseDown.position.left = left;
		events.mouseDown.position.top = top;
		events.dblClick.happend = true;
		events.dblClick.position.left = left;
		events.dblClick.position.top = top;
		events.click.happend = true;
		events.click.position.left = left;
		events.click.position.top = top;
		lbtndown = false;
	}

	// maybe mouse moved or dragged?
	events.mouseMove.happend = false;
	events.mouseDrag.happend = false;
	left = mousex();
	top = mousey();
	if (left != lastMouseLeft || top != lastMouseTop) {
		events.mouseMove.happend = true;
		events.mouseMove.current.left = left;
		events.mouseMove.current.top = top;
		events.mouseMove.previous.left = lastMouseLeft;
		events.mouseMove.previous.top = lastMouseTop;
		if (lbtndown) {
			events.mouseDrag.happend = true;
			events.mouseDrag.current.left = left;
			events.mouseDrag.current.top = top;
			events.mouseDrag.previous.left = lastMouseLeft;
			events.mouseDrag.previous.top = lastMouseTop;
		}
		lastMouseLeft = left;
		lastMouseTop = top;
	}

}


} /* namespace GUI */
