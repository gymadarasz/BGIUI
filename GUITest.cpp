/*
 * GUITest.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "GUITest.h"

namespace GUI {

void GUITest::run() {

    // Is Window draws pixels?
	Window window;
	int color = getpixel(0, 0);
	equ(color, BLACK);
	color = getpixel(10, 10);
	equ(color, BLACK);
	putpixel(10, 10, WHITE);
	color = getpixel(10, 10);
	equ(color, WHITE);

    // Is Canvas id incrementing?
    Canvas canvas1;
    equ(canvas1.getId(), 0);
    Canvas canvas2;
    equ(canvas2.getId(), 1);
    Canvas canvas3;
    equ(canvas3.getId(), 2);

    // Canvas draws?
    canvas1.setup(20, 20, 100, 100);
    canvas1.draw();
    color = getpixel(20-GUI_STYLE_CANVAS_BORDER_SIZE, 20-GUI_STYLE_CANVAS_BORDER_SIZE);
    equ(color, GUI_STYLE_CANVAS_BORDER_COLOR);
    color = getpixel(20, 20);
    equ(color, GUI_STYLE_CANVAS_COLOR);
    color = getpixel(40, 40);
    equ(color, GUI_STYLE_CANVAS_COLOR);
    color = getpixel(20+100+GUI_STYLE_CANVAS_BORDER_SIZE, 20+GUI_STYLE_CANVAS_BORDER_SIZE);
    equ(color, GUI_STYLE_CANVAS_BORDER_COLOR);
    color = getpixel(20+100, 20);
    equ(color, GUI_STYLE_CANVAS_COLOR);



}

} /* namespace GUI */
