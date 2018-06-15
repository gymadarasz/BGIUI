/*
 * main.cpp
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#include <stdio.h>

#include "Tester.h"
#include "GUITest.h"

using namespace GUI;

int main() {
	Tester tester;
	return tester.run(new GUITest);
}


