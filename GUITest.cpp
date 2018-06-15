/*
 * GUITests.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "GUITest.h"

namespace GUI {

void GUITest::equ(int a, int b, const char* errmsg) {
	asserts++;
	if (a == b) {
		printf(".");
	} else {
		errors++;
		printf(errmsg, a, b);
	}
}

void GUITest::countedTest() {
	Counted counted1;
	int id = counted1.getId();
	equ(id, 1);
	Counted counted2;
	id = counted2.getId();
	equ(id, 2);
}

void GUITest::windowTest() {
	Window window;
	int color = getpixel(0, 0);
	equ(color, BLACK);
	color = getpixel(10, 10);
	equ(color, BLACK);
	putpixel(10, 10, WHITE);
	color = getpixel(10, 10);
	equ(color, WHITE);
}

GUITest::GUITest() {

	printf("Test start\n");
	asserts = 0;
	errors = 0;

	countedTest();
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
