/*
 * Window.h
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <stdio.h>
#include "Painter.h"
#include "Canvas.h"

namespace GUI {

class Window {
	Canvas canvas;
public:
	Window(
	    int width = 0,
		int height = 0,
		const char* title = "Windows BGI",
		int left = 0,
		int top = 0,
		bool dbflag = false,
		bool closeflag = true,
		int color = GUI_WINDOW_COLOR,
		int colorPushed = GUI_WINDOW_COLOR_PUSHED
	);
	virtual ~Window();
	virtual void run();
};

} /* namespace GUI */

#endif /* WINDOW_H_ */
