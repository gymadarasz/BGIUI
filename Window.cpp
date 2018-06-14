/*
 * Window.cpp
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#include "Window.h"

namespace GUI {

Window::Window(int width, int height, const char* title, int left, int top, bool dbflag, bool closeflag) {

	int found = false;

#ifdef _WIN32
	initwindow(width, height, title, left, top, dbflag, closeflag);
	found = true;
#endif

#ifdef linux
	initGraphics(width, height);
	found = true;
#endif

	if (!found) {
		int g=DETECT,d;
		initgraph(&g,&d,(char*)"../../bgi");
	}

	cleardevice();
}

Window::~Window() {
	closegraph();
}

} /* namespace GUI */
