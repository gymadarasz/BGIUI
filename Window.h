/*
 * Window.h
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <stdio.h>
#include "Canvas.h"
#include "Painter.h"
#include "Keyboard.h"
#include "Mouse.h"

namespace GUI {

class Window {
	Canvas* canvas;
	bool exit;
	// TODO: virtual Canvas* setCanvas();
public:
	Window(
	    int width = 0,
		int height = 0,
		char* title = (char*)"Window GUI",
		int left = 0,
		int top = 0,
		bool dbflag = false,
		bool closeflag = true,
		int color = GUI_WINDOW_COLOR,
		int colorPushed = GUI_WINDOW_COLOR_PUSHED
	);
	virtual ~Window();
	virtual void run();
	virtual Canvas* getCanvas();
	virtual Window* reset(
		int color = GUI_WINDOW_COLOR,
		int colorPushed = GUI_WINDOW_COLOR_PUSHED
	);
	virtual void close();
};

} /* namespace GUI */

#endif /* WINDOW_H_ */
