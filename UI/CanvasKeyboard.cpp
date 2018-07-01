/*
 * Keyboard.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#include "CanvasKeyboard.h"

namespace gui {

CanvasKeyboard::CanvasKeyboard() {
	keypress.happened = false;
	keypress.key = -1;
}

CanvasKeyboard::~CanvasKeyboard() {}

bool CanvasKeyboard::check() {
	keypress.happened = false;
	if (kbhit()) {
		keypress.happened = true;
		while(!(keypress.key = getch()));
	}
	return keypress.happened;
}

CanvasEventKeypress CanvasKeyboard::getKeypress() {
	return keypress;
}

} /* namespace GUI */

