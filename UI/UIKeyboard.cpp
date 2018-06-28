/*
 * Keyboard.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#include "../UI/UIKeyboard.h"

namespace gui {

UIKeyboard::UIKeyboard() {
	keypress.happened = false;
	keypress.key = -1;
}

UIKeyboard::~UIKeyboard() {}

bool UIKeyboard::check() {
	keypress.happened = false;
	if (kbhit()) {
		keypress.happened = true;
		while(!(keypress.key = getch()));
	}
	return keypress.happened;
}

EventKeypress UIKeyboard::getKeypress() {
	return keypress;
}

} /* namespace GUI */

