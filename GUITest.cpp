/*
 * GUITest.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "GUITest.h"

namespace GUI {

void GUITest::testWindow() {
    // Is Window draws pixels?

	int color;
	Window window;
	color = getpixel(0, 0);
	equ(color, BLACK, "Screen device should be cleared after window initialized.");
	color = getpixel(10, 10);
	equ(color, BLACK, "Screen device should be black after the window initialization.");
	putpixel(10, 10, WHITE);
	color = getpixel(10, 10);
	equ(color, WHITE, "Screen device, should be able to show a pixel.");
}

void GUITest::testCanvasIncrement() {
    // Is Canvas id incrementing?
	Window window;
    window.reset();
    equ(window.getCanvas()->getId(), 0, "Window canvas ID should be 0.");
    Canvas canvas1;
    equ(canvas1.getId(), 1, "First canvas ID should be 1.");
    Canvas canvas2;
    equ(canvas2.getId(), 2, "Second canvas ID should be 2.");
    Canvas canvas3;
    equ(canvas3.getId(), 3, "Third canvas ID should be 3.");
}

void GUITest::testCanvasDraw() {
    // Canvas draws?
	int color;
	Window window;
	Canvas canvas1;
    Painter::clear();
    canvas1.setup(false, 100, 100, 20, 20);
    canvas1.draw();

    color = getpixel(20, 20);
    equ(color, GUI_CANVAS_BORDER_COLOR, "Canvas border should be visible on the screen. (top/left)");
    color = getpixel(20 + GUI_CANVAS_BORDER_SIZE, 20 + GUI_CANVAS_BORDER_SIZE);
    equ(color, GUI_CANVAS_COLOR, "Canvas inner should be visible on the screen. (top/left)");
    color = getpixel(40, 40);
    equ(color, GUI_CANVAS_COLOR, "Canvas border should be visible on the screen. (center somewhere)");
    color = getpixel(20+100, 20);
    equ(color, GUI_CANVAS_BORDER_COLOR, "Canvas border should be visible on the screen. (top/right)");
    color = getpixel(20+100 + GUI_CANVAS_BORDER_SIZE, 20 + GUI_CANVAS_BORDER_SIZE);
    equ(color, GUI_CANVAS_COLOR, "Canvas inner should be visible on the screen. (top/right)");
}

void GUITest::testCanvasBoxing(){

	Window window;
	int color;
	int i = 0;
	int precision = 7;

    window.reset();
    Canvas* testCanvas = new Canvas(window.getCanvas());
	testCanvas->setup(false, 300, 120, 20, 10);
	(new Canvas(testCanvas))->setup(true, 50, 50, -1, -1, RED, RED, 3, GREEN, GREEN, 3);
	(new Canvas(testCanvas))->setup(true, 80, 40, -1, -1, GREEN, GREEN, 5, GREEN, GREEN, 5);
	(new Canvas(testCanvas))->setup(true, 20, 20, -1, -1, YELLOW, YELLOW, 1, BLUE, BLUE, 1);
	(new Canvas(testCanvas))->setup(true, 20, 20, -1, -1, BLUE, BLUE, 0, BLACK, BLACK, 0);
	(new Canvas(testCanvas))->setup(true, 80, 40, -1, -1, GREEN, GREEN, 2, BLUE, BLUE, 2);
	(new Canvas(testCanvas))->setup(true, 50, 50, -1, -1, YELLOW, YELLOW, 4, GREEN, GREEN, 10);
	(new Canvas(testCanvas))->setup(true, 80, 40, -1, -1, BLUE, BLUE, 1, BLACK, BLACK, 0);
	(new Canvas(testCanvas))->setup(true, 50, 50, -1, -1, RED, RED, 2, YELLOW, YELLOW, 7);
	window.getCanvas()->draw();

	snapScr(5,10,320,160,7, false);
	int scrData[47250] = {
		7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,7,4,4,4,4,4,4,4,7,7,2,2,2,2,2,2,2,2,7,7
		,7,7,7,4,4,4,4,4,4,4,7,7,7,14,14,14,14,14,14,14,7,7
		,7,7,7,4,4,4,4,4,4,4,7,7,7,14,14,14,14,14,14,14,7,7
		,7,7,7,4,4,4,4,4,4,4,7,7,7,14,14,14,14,14,14,14,7,7
		,7,7,7,4,4,4,4,4,4,4,7,7,7,14,14,14,14,14,14,14,7,7
		,7,7,7,4,4,4,4,4,4,4,7,7,7,14,14,14,14,14,14,14,7,7
		,7,7,7,4,4,4,4,4,4,4,7,7,7,14,14,14,14,14,14,14,7,7
		,7,7,2,2,2,2,2,2,2,2,7,7,7,14,14,14,14,14,14,14,7,7
		,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,7,7,1,1,1,1,1,1,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,7,7,1,1,1,1,1,1,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,7,7,1,1,1,1,1,1,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,7,7,1,1,1,1,1,1,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,7,7,1,1,1,1,1,1,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,7,7,1,1,1,1,1,1,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,7,7,1,1,1,1,1,1,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,7,7,1,1,1,1,1,1,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,7,7,1,1,1,1,1,1,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,7,7,1,1,1,1,1,1,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,7,7,1,1,1,1,1,1,7,7,7,7,7
		,7,7,2,2,2,2,2,2,2,2,7,1,1,1,1,1,1,7,7,7,7,7
		,7,7,14,14,14,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,14,14,14,7,7,7,7,7,7,7,4,4,4,4,4,4,4,7,7,7
		,7,7,14,14,14,7,7,7,7,7,7,7,4,4,4,4,4,4,4,7,7,7
		,7,7,1,1,1,7,7,7,7,7,7,7,4,4,4,4,4,4,4,7,7,7
		,7,7,1,1,1,7,7,7,7,7,7,7,4,4,4,4,4,4,4,7,7,7
		,7,7,1,1,1,7,7,7,7,7,7,7,4,4,4,4,4,4,4,7,7,7
		,7,7,1,1,1,7,7,7,7,7,7,7,4,4,4,4,4,4,4,7,7,7
		,7,7,2,2,2,2,2,2,7,7,7,7,4,4,4,4,4,4,4,7,7,7
		,7,7,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,2,2,2,2,2,2,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7
		,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7
	}; // Snap screen end.
	chk(chkScr(scrData, 5, 10, 320, 160, 7), "Check screen snap area [5, 10 - 320, 160; precision:7]");

}

void GUITest::testCanvasAutoPosition() {
    // Canvas auto position
    chk(Canvas::getInstance(0), "We should have some canvases.. (check at place 0)");
    chk(Canvas::getInstance(1), "We should have some canvases.. (check at place 1)");
    chk(Canvas::getInstance(2), "We should have some canvases.. (check at place 2)");
    Canvas::clearInstances();
    chk(!Canvas::getInstance(0), "Canvases are cleared (check at 0)");
    chk(!Canvas::getInstance(1), "Canvases are cleared (check at 1)");
    chk(!Canvas::getInstance(2), "Canvases are cleared (check at 2)");
}

void GUITest::testCursor() {
    // Cursor?
    Cursor cursor;
    cursor.reset(100);
    equ(cursor.getWidth(), 100, "Cursor reset: width ok?");
    equ(cursor.getTop(), 0, "Cursor reset: top ok?");
    equ(cursor.getLeft(), 0, "Cursor reset: left ok?");
    equ(cursor.getLineHeight(), 0, "Cursor reset: lineHeihgt ok?");
    cursor.step(60, 60);
    equ(cursor.getTop(), 0, "Cursor step: top ok?");
    equ(cursor.getLeft(), 60, "Cursor step: left ok?");
    equ(cursor.getLineHeight(), 60, "Cursor step: lineHeihgt ok?");
    cursor.step(60, 60);
    equ(cursor.getTop(), 60, "Cursor step2: top ok?");
    equ(cursor.getLeft(), 0, "Cursor step2: left ok?");
    equ(cursor.getLineHeight(), 60, "Cursor step2: lineHeihgt ok?");
    cursor.step(60, 60);
    equ(cursor.getTop(), 60, "Cursor step3: top ok?");
    equ(cursor.getLeft(), 60, "Cursor step3: left ok?");
    equ(cursor.getLineHeight(), 60, "Cursor step3: lineHeihgt ok?");
    cursor.br();
    equ(cursor.getTop(), 120, "Cursor break: top ok?");
    equ(cursor.getLeft(), 0, "Cursor break: left ok?");
    equ(cursor.getLineHeight(), 0, "Cursor break: lineHeihgt ok?");
}

void GUITest::testLabelAndLineBreak() {
	Window window;
	(new Label(window.getCanvas()))->setup("Hello World!");
	(new Label(window.getCanvas()))->setup("This is a Label.");
	(new Label(window.getCanvas()))->setup("This label in new line.")->setLineBreak(true);
	window.getCanvas()->draw();

	snapScr(0,0,260,60,7, false);

	// Snap screen from area [0, 0 - 260, 60; precision:7]:
	int scrData[15600] = {
		7,7,7,7,7,7,7,7,7
		,7,7,72089737,7,7,74197925,7,8,7
		,7,7,74229035,7,7,76129612,7,8,7
		,7,7,67119872,7,7,7,7,8,7
		,7,7,0,7,7,7,7,8,7
		,7,7,0,7,7,7,7,8,7
		,7,7,0,7,7,7,7,8,7
		,7,7,7,7,7,0,7,8,7
		,7,7,69927020,7,7,7,7,8,7
		,7,7,7,7,7,67108907,7,8,7
		,7,7,7,7,7,7,7,8,7
		,7,7,76136524,7,7,7,7,8,7
		,7,7,0,7,7,7,7,8,7
		,7,7,0,7,7,7,7,8,7
		,7,7,69927020,7,7,67108907,7,8,7
		,7,7,7,7,7,7,7,8,7
		,7,7,7,7,7,7,7,8,7
		,7,7,0,7,7,7,7,8,7
		,7,7,0,7,7,7,7,8,7
		,7,7,77950144,7,7,7,7,8,7
		,7,7,79741065,7,7,7,7,8,7
		,7,7,72124672,7,7,7,7,8,7
		,7,7,7,7,7,0,7,8,7
		,7,7,0,7,7,77950144,7,8,7
		,7,7,0,7,7,7,7,8,7
		,7,7,7,7,7,7,7,8,7
		,7,7,0,7,7,7,7,8,7
		,7,7,7,7,7,7,7,8,7
		,7,7,7,7,7,7,7,8,7
		,7,7,0,7,7,7,7,7,7
		,7,7,0,7,7,7,7,7,7
		,7,7,0,7,7,7,7,7,7
		,7,7,0,7,7,7,7,7,7
		,7,7,0,7,7,7,7,7,7
		,7,7,7,7,7,7,7,7,7
		,7,7,7,7,7,7,7,7,7
		,7,7,7,7,7,7,7,7,7
		,7,7,7,7,7,7,7,7,7
	}; // Snap screen end.
	chk(chkScr(scrData, 0, 0, 260, 60, 7), "Check screen snap area [0, 0 - 260, 60; precision:7]");
}

void GUITest::run() {
	testWindow();
	testCanvasIncrement();
	testCanvasDraw();
	testCanvasBoxing();
	testCanvasAutoPosition();
	testCursor();
	testLabelAndLineBreak();
}

} /* namespace GUI */
