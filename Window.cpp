/*
 * Window.cpp
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#include "Window.h"

namespace GUI {

Window::Window(int width, int height, char* title, int left, int top, bool dbflag, bool closeflag, int color, int colorPushed, int colorSelected) {
	exit = false;
	Painter::init(width, height, title, left, top, dbflag, closeflag);
	reset(color, colorPushed, colorSelected);
}

Window::~Window() {
	Painter::close();
}

void Window::run(WindowLoop loop) {
	Mouse::reset();
	exit = false;
	while (!exit) {

		canvas.draw();
		delay(1);

		Keyboard::check();
		Mouse::check();

		if (Keyboard::keypress.happened) {
			switch (Keyboard::keypress.key) {
			case KEY_LEFT:
				Canvas::selectPrev();
				break;
			case KEY_RIGHT:
				Canvas::selectNext();
				break;
			case KEY_SPACE:
				Canvas::selectedsClick();
				break;
			}
		}
		canvas.tick();
		if (loop) loop();
	}
}

Canvas* Window::getCanvas() {
	return &canvas;
}

Window* Window::reset(int color, int colorPushed, int colorSelected) {

	//canvas.setup(false, Painter::getmaxwidth(), Painter::getmaxheight(), 0, 0, color, colorPushed, colorSelected, 0);
	canvas.setAdjust(true);
	canvas.setWidth(Painter::getmaxwidth());
	canvas.setHeight(Painter::getmaxheight());
	canvas.setTop(0);
	canvas.setLeft(0);
	canvas.setColor(color);
	canvas.setColorPushed(colorPushed);
	canvas.setColorSelected(colorSelected);
	canvas.setBorderSize(0);
	return this;
}

void Window::close() {
	exit = true;
}

} /* namespace GUI */

