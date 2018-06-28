/*
 * Keyboard.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#ifndef GUI_UIKEYBOARD_H_
#define GUI_UIKEYBOARD_H_

#include "../defs.h"

namespace gui {

#define KEY_ENTER 13 // hacky enter
#define KEY_SPACE 32 // hacky space

typedef struct {
	bool happened;
	int key;
} EventKeypress;

class UIKeyboard {
	EventKeypress keypress;
public:
	UIKeyboard();
	virtual ~UIKeyboard();
	virtual bool check();
	virtual EventKeypress getKeypress();
};

} /* namespace gui */

#endif /* GUI_UIKEYBOARD_H_ */
