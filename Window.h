/*
 * Window.h
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <graphics.h>

namespace GUI {

class Window {
public:
	Window(
	    int width = 0,
		int height = 0,
		const char* title = "Windows BGI",
		int left = 0,
		int top = 0,
		bool dbflag = false,
		bool closeflag = true
	);
	virtual ~Window();
};

} /* namespace GUI */

#endif /* WINDOW_H_ */
