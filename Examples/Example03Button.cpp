/*
 * Example02Button.cpp
 *
 *  Created on: Jun 16, 2018
 *      Author: Gyula
 */

#include "Example03Button.h"

int exampleButtonClicked(Canvas* btn, ...) {
	((Button*)btn)->setText("Thanks!");
	Canvas::clearAll();
	return 0;
}

Example03Button::Example03Button() {
	Window window;

	(new Button(window.getCanvas()))->setup("Push me..")->setClickHandler(exampleButtonClicked);
	(new Label(window.getCanvas()))->setup("Test..");

	window.run();

}

Example03Button::~Example03Button() {
	// TODO Auto-generated destructor stub
}

