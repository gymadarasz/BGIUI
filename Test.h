/*
 * GUITests.h
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#ifndef TEST_H_
#define TEST_H_

#include <stdio.h>

#include "Canvas.h"
#include "Window.h"

namespace GUI {

class Test {
	int asserts;
	int errors;
	void equ(int a, int b, const char* errmsg = "\nERROR: Test assert equals integer error: %d != %d\n");
	void canvasTest();
	void windowTest();
public:
	Test();
};

} /* namespace GUI */

#endif /* TEST_H_ */
