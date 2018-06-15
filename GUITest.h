/*
 * GUITests.h
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#ifndef GUITEST_H_
#define GUITEST_H_

#include <stdio.h>
#include "Counted.h"
#include "Window.h"

namespace GUI {

class GUITest {
	int asserts;
	int errors;
	void equ(int a, int b, const char* errmsg = "\nERROR: Test assert equals integer error: %d != %d\n");
	void countedTest();
	void windowTest();
public:
	GUITest();
};

} /* namespace GUI */

#endif /* GUITEST_H_ */
