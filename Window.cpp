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
	canvas.setup(0, 0, Painter::getmaxwidth(), Painter::getmaxheight(), color, colorPushed, 0);
}

Window::~Window() {
	Painter::close();
}

void Window::run() {
	Canvas* canvas;
	for (int i=0; i<CANVAS_INSTANCES; i++) {
		canvas = Canvas::getInstance(i);
		if (canvas) {
			canvas->draw();
		}
	}
}

} /* namespace GUI */
