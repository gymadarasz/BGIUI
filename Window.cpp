/*
 * Window.cpp
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#include "Window.h"
#include "Canvas.h"

namespace GUI {

Window::Window(int width, int height, const char* title, int left, int top, bool dbflag, bool closeflag, int color, int colorPushed) {
	Painter::init(width, height, title, left, top, dbflag, closeflag);
	(canvas = new Canvas())->setup(Painter::getmaxwidth(), Painter::getmaxheight(), 0, 0, color, colorPushed, 0);
}

Window::~Window() {
	Painter::close();
}

void Window::run() {
	Canvas* canvas;
	while (true) {
		for (int i=0; i<CANVAS_INSTANCES; i++) {
			canvas = Canvas::getInstance(i);
			if (canvas) {
				printf("paint canvas: %d\n", i);
				canvas->draw();
			}
		}
		delay(1);
	}
}

Canvas* Window::getCanvas() {
	return canvas;
}

} /* namespace GUI */
