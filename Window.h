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

typedef void (*WindowLoop)(void);

class Window {
	Canvas* canvas;
	WindowLoop loop;
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
		int colorPushed = GUI_WINDOW_COLOR_PUSHED,
		int colorSelected = GUI_WINDOW_COLOR_SELECTED
	);
	virtual ~Window();
	virtual void run(WindowLoop loop = 0);
	virtual Canvas* getCanvas();
	virtual Window* reset(
		int color = GUI_WINDOW_COLOR,
		int colorPushed = GUI_WINDOW_COLOR_PUSHED,
		int colorSelected = GUI_WINDOW_COLOR_SELECTED
	);
	virtual void close();
};

} /* namespace GUI */

#endif /* WINDOW_H_ */
