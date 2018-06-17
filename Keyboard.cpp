/*
 * Keyboard.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#include "Keyboard.h"

namespace GUI {

EventKeypress Keyboard::keypress = {false, -1};

void Keyboard::check() {
	keypress.happened = false;
	if (kbhit()) {
		keypress.happened = true;
		while(!(keypress.key = getch()));
	}
}

} /* namespace GUI */
