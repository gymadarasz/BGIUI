/*
 * CanvasExample.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "Example01Canvas.h"

Example01Canvas::Example01Canvas() {
	Window window;
	(new Canvas(window.getCanvas()))->setup(100, 100, 10, 10, RED);
	window.run();
}

Example01Canvas::~Example01Canvas() {
	// TODO Auto-generated destructor stub
}

