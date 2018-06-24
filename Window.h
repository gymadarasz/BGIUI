/*
 * Window.h
 *
 *  Created on: Jun 21, 2018
 *      Author: Gyula
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include "Painter.h"
#include "Canvas.h"

namespace gui {

typedef void (*WindowLoop)(void);

class Window: public Canvas {
public:
	bool halt;
	Window(Canvas* parent = 0, int width = 800, int height = 600, char* title = (char*)"GUI Window", int left = 0, int top = 0, bool dbflag = false, bool closeflag = true);
	void run(WindowLoop loop = 0);
};

} /* namespace gui */

#endif /* WINDOW_H_ */
