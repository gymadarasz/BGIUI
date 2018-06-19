/*
 * Example04Scroll.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#include "Example04Scroll.h"

#include <stdio.h>
#include <stdlib.h>
#include "../Scroll.h"

// TODO: cleanup examples and use static local function calls and class variables!

Scroll* scrl1ForExample04 = 0;
Label* lbl1ForExample04 = 0;
char str[100];

int exampleScrollHandler(Canvas* scrl, ...) {
	va_list args;
	va_start(args, scrl);
	int value = va_arg(args, int);
	va_end(args);

	sprintf(str, "Value: %d", value);

	lbl1ForExample04->setText((char*)str);
	return 0;
}

Example04Scroll::Example04Scroll() {
	Window window;

	scrl1ForExample04 = new Scroll(window.getCanvas());
	scrl1ForExample04->setup(22, 0, 100)->setScrollHandler(exampleScrollHandler);


	lbl1ForExample04 = new Label(window.getCanvas());
	lbl1ForExample04->setup((char*)"<- Scroll it!");

	window.run();

}

Example04Scroll::~Example04Scroll() {
	// TODO Auto-generated destructor stub
}

