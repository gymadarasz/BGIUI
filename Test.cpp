/*
 * GUITests.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "Test.h"

namespace GUI {

Test::Test() {
    runs = 0;
    failed = 0;
    success = 0;
}

Test::~Test() {

}

void Test::run() {
    printf("Nothing to test here..\n");
}


void Test::equ(int a, int b, const char* errmsg) {
    runs++;
    if (a == b) {
        printf(".");
        success++;
    } else {
        printf(errmsg, a, b);
        failed++;
    }
}

void Test::equ(const char* a, const char* b, const char* errmsg) {
    int res = strcmp(a, b);
    runs++;
    if (!res) {
        printf(".");
        success++;
    } else {
        printf(errmsg, res, a, b);
        failed++;
    }
}

void Test::stat() {
    printf("\nRuns: %d, Success: %d, Failed: %d\n", runs, success, failed);
    if (runs == success) {
        printf("All test SUCCESS.\n:)\n");
    } else {
        printf("FAILED tests found. :(\n");
    }
}
//
//void Test::canvasTest() {
//
//	Canvas canvas1;
//	int id = canvas1.getId();
//	equ(id, 0);
//	Canvas canvas2;
//	id = canvas2.getId();
//	equ(id, 1);
//
//	Canvas canvas;
//	canvas.setup(10, 10, 20, 20);
//	//canvas.draw();
//}
//
//void Test::windowTest() {
//	Window window;
//	int color = getpixel(0, 0);
//	equ(color, BLACK);
//	color = getpixel(10, 10);
//	equ(color, BLACK);
//	putpixel(10, 10, WHITE);
//	color = getpixel(10, 10);
//	equ(color, WHITE);
//}
//
//Test::Test() {
//
//	printf("Test start\n");
//	asserts = 0;
//	errors = 0;
//
//	canvasTest();
//	windowTest();
//
//	printf("\nAsserts: %d\n", asserts);
//	if (!errors) {
//		printf("All test SUCCESS\n");
//	} else {
//		printf("Errors: %d\n", errors);
//	}
//
//	getch();
//
//}

} /* namespace GUI */
