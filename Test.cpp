/*
 * GUITests.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "Test.h"

namespace GUI {

void Test::equ(int a, int b, const char* errmsg) {
	asserts++;
	if (a == b) {
		printf(".");
	} else {
		errors++;
		printf(errmsg, a, b);
	}
}

void Test::canvasTest() {

	Canvas canvas1;
	int id = canvas1.getId();
	equ(id, 1);
	Canvas canvas2;
	id = canvas2.getId();
	equ(id, 2);

	Canvas canvas;
	canvas.setup();
}

void Test::windowTest() {
	Window window;
	int color = getpixel(0, 0);
	equ(color, BLACK);
	color = getpixel(10, 10);
	equ(color, BLACK);
	putpixel(10, 10, WHITE);
	color = getpixel(10, 10);
	equ(color, WHITE);
}

Test::Test() {

	printf("Test start\n");
	asserts = 0;
	errors = 0;

	canvasTest();
	windowTest();

	printf("\nAsserts: %d\n", asserts);
	if (!errors) {
		printf("All test SUCCESS\n");
	} else {
		printf("Errors: %d\n", errors);
	}

	//getch();
}

} /* namespace GUI */
