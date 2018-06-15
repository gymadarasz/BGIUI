/*
 * Painter.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "Painter.h"

namespace GUI {

	int Painter::init(int width, int height, const char* title, int left, int top, bool dbflag, bool closeflag) {

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

		return found;
	}

	int Painter::close() {
		closegraph();
		return 0;
	}

} /* namespace GUI */
