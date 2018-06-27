/*
 * Keyboard.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#include "../UI/Keyboard.h"

namespace gui {

EventKeypress Keyboard::keypress = {false, -1};

bool Keyboard::check() {
	keypress.happened = false;
	if (kbhit()) {
		keypress.happened = true;
		while(!(keypress.key = getch()));
	}
	return keypress.happened;
}

EventKeypress Keyboard::getKeypress() {
	return keypress;
}

} /* namespace GUI */

