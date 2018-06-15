/*
 * GUITest.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "GUITest.h"

namespace GUI {

void GUITest::run() {

    //printf("\nIs Canvas id incrementing?\n");

    Canvas canvas1;
    equ(canvas1.getId(), 0);
    Canvas canvas2;
    equ(canvas2.getId(), 1);
    Canvas canvas3;
    equ(canvas3.getId(), 2);

    //printf("\nIs Window draws pixels?\n");

	Window window;
	int color = getpixel(0, 0);
	equ(color, BLACK);
	color = getpixel(10, 10);
	equ(color, BLACK);
	putpixel(10, 10, WHITE);
	color = getpixel(10, 10);
	equ(color, WHITE);

}

} /* namespace GUI */
