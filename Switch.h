/*
 * Switch.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include "Button.h"

namespace GUI {

class Switch: public Button {
	char* textOff;
	char* textOn;
	Switch* setTextOff(char* textOff);
	Switch* setTextOn(char* textOn);
	char* getTextOff();
	char* getTextOn();
public:
	Switch(Canvas* parent = 0);
	virtual ~Switch();
	virtual Switch* setup(
		char* textOff = GUI_SWITCH_DEFAULT_TEXT_OFF,
		char* textOn = GUI_SWITCH_DEFAULT_TEXT_ON,
		int textColor = GUI_SWITCH_TEXT_COLOR,
		bool adjust = GUI_SWITCH_DEFAULT_ADJUST,
		int width = GUI_SWITCH_DEFAULT_WIDTH,
		int height = GUI_SWITCH_DEFAULT_HEIGHT,
		int top = GUI_SWITCH_DEFAULT_TOP,
		int left = GUI_SWITCH_DEFAULT_LEFT,
		int color = GUI_SWITCH_COLOR,
		int colorPushed = GUI_SWITCH_COLOR_PUSHED,
		int colorSelected = GUI_SWITCH_COLOR_SELECTED,
		int borderSize = GUI_SWITCH_BORDER_SIZE,
		int borderColor = GUI_SWITCH_BORDER_COLOR,
		int borderColorSelected = GUI_SWITCH_BORDER_COLOR_SELECTED,
		int marginSize = GUI_SWITCH_MARGIN_SIZE,
		int paddingSize = GUI_SWITCH_PADDING_SIZE
	);
	virtual void onMouseDown(int mouseLeft, int mouseTop);
	virtual void onMouseUp(int mouseLeft, int mouseTop);
};

} /* namespace GUI */

#endif /* SWITCH_H_ */
