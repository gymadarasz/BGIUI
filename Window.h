/*
 * Window.h
 *
 *  Created on: Jun 21, 2018
 *      Author: Gyula
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include "Canvas.h"

namespace gui {

class Window: public Canvas {
public:
	//Window(Canvas* parent = 0, int width = 800, int height = 600, char* title = (char*)"GUI Window", int left = 0, int top = 0, bool dbflag = false, bool closeflag = true);
};

} /* namespace gui */

#endif /* WINDOW_H_ */
