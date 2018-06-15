/*
 * main.cpp
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#include <stdio.h>

#include "Tester.h"
#include "GUITest.h"
#include "Examples/Example01Canvas.h"

using namespace GUI;

int main() {
	Tester tester;
	if (tester.run(new GUITest)) {
		return 1;
	}
	Example01Canvas example01;

	return 0;
}


