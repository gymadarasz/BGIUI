/*
 * CanvasExample.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "Example01Canvas.h"

Example01Canvas::Example01Canvas() {
	Window window;

	// add a canvas into window
	Canvas* testCanvas = new Canvas(window.getCanvas());
	testCanvas->setup(false, 180, 120, 20, 10, BLACK);

	// add some new canvas into the new canvas
	(new Canvas(testCanvas))->setup(true, 50, 50, -1, -1, RED);
	(new Canvas(testCanvas))->setup(true, 80, 40, -1, -1, GREEN);
	(new Canvas(testCanvas))->setup(true, 120, 20, -1, -1, BLUE);

//	Canvas::debugInstances();
	window.run();
}

Example01Canvas::~Example01Canvas() {
	// TODO Auto-generated destructor stub
}

