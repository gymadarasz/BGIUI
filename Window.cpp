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
	reset();
}

Window::~Window() {
	Painter::close();
}

void Window::run() {
	while (true) {
		canvas->draw();
		delay(1);
	}
}

Canvas* Window::getCanvas() {
	return canvas;
}

Window* Window::reset(int color, int colorPushed) {
	Canvas::clearInstances();
	(canvas = new Canvas())->setup(false, Painter::getmaxwidth(), Painter::getmaxheight(), 0, 0, color, colorPushed, 0);
	return this;
}

} /* namespace GUI */
