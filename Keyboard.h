/*
 * Keyboard.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <graphics.h>

namespace gui {

#define KEY_SPACE 32 // hacky space

typedef struct {
	bool happened;
	int key;
} EventKeypress;

class Keyboard {
public:
	static EventKeypress keypress;
	static void check();
};

} /* namespace GUI */

#endif /* KEYBOARD_H_ */