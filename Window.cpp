/*
 * Window.cpp
 *
 *  Created on: Jun 21, 2018
 *      Author: Gyula
 */

#include "Window.h"

namespace gui {

Window::Window(Canvas* parent, int width, int height, char* title, int left, int top, bool dbflag, bool closeflag): Canvas(parent) {
	Painter::init(width, height, title, left, top, dbflag, closeflag);
	box.width = Painter::getMaxWidth();
	box.height = Painter::getMaxHeight();
	box.top = 0;
	box.left = 0;
	margin.horizontal = 0;
	margin.vertical = 0;
	border.size = 0;
	border.color = NOCOLOR;
	adjust.toParentCursor = false;
	halt = false;
	disabled = true;
}

void Window::run(/*loop function*/) {
	Mouse::reset();
	halt = false;
	while (!halt) {
		calc();
		Mouse::check();
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i]) {
				canvases[i]->draw();
				canvases[i]->tick();
			}
		}
		delay(1);
	}
}

} /* namespace gui */

