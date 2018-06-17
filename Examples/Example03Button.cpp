/*
 * Example02Button.cpp
 *
 *  Created on: Jun 16, 2018
 *      Author: Gyula
 */

#include "Example03Button.h"


Canvas* root = 0;
Label* lbl1 = 0;

int exampleButtonClicked(Canvas* btn, ...) {
	((Button*)btn)->setText("Thanks!");
	Canvas::clearAll(root);
	return 0;
}

int exampleSwitchClicked(Canvas* swch, ...) {
	if (((Switch*)swch)->getPushed()) {
		lbl1->setText("Thanks, it switched on now");
	} else {
		lbl1->setText("Switched off? why? ..can you..?");
	}
	Canvas::clearAll(root);
	return 0;
}

Example03Button::Example03Button() {
	Window window;

	root = window.getCanvas();

	(new Button(root))->setup("Push me..")->setClickHandler(exampleButtonClicked);
	(new Switch(root))->setClickHandler(exampleSwitchClicked);
	(lbl1 = new Label(root))->setup("<- Switch on!");

	window.run();

}

Example03Button::~Example03Button() {
	// TODO Auto-generated destructor stub
}

