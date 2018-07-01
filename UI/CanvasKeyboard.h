/*
 * Keyboard.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#ifndef GUI_CANVASKEYBOARD_H_
#define GUI_CANVASKEYBOARD_H_

#include "../guidefs.h"

namespace gui {

#define KEY_ENTER 13 // hacky enter
#define KEY_SPACE 32 // hacky space

typedef struct {
	bool happened;
	int key;
} CanvasEventKeypress;

class CanvasKeyboard {
	CanvasEventKeypress keypress;
public:
	CanvasKeyboard();
	virtual ~CanvasKeyboard();
	virtual bool check();
	virtual CanvasEventKeypress getKeypress();
};

} /* namespace gui */

#endif /* GUI_CANVASKEYBOARD_H_ */
