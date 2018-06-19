/*
 * main.cpp
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#include <stdio.h>

#include "Test/Tester.h"
#include "GUITest.h"


//#include "Examples/Example01Canvas.h"
//#include "Examples/Example02Label.h"
//#include "Examples/Example03Button.h"
//#include "Examples/Example04Scroll.h"


int main() {

	// run test
	test::Tester tester;
	GUITest guiTest;
	return tester.run(&guiTest);
	// end tests

//	Example01Canvas example01;
//	Example02Label example02;
//	Example03Button example03;
//	Example04Scroll exmaple04;



//	window.run();

	return 0;
}


