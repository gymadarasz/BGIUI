/*
 * GUITests.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "GUITest.h"

namespace GUI {

int GUITest::equ(int a, int b, const char* errmsg) {
	if (a == b) {
		printf(".");
	} else {
		printf(errmsg, a, b);
		return -1;
	}
	return 0;
}

GUITest::GUITest() {

	Counted counted1;
	int id = counted1.getId();
	equ(id, 1);
	Counted counted2;
	id = counted2.getId();
	equ(id, 2);

	//getch();
}

} /* namespace GUI */
