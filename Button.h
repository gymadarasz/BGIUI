/*
 * Button.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "Label.h"

namespace GUI {

class Button: public Label {
public:
	Button(Canvas* parent = 0);
	virtual ~Button();
	virtual Button* setup(
		const char* text = GUI_BUTTON_DEFAULT_TEXT,
		int textColor = GUI_BUTTON_TEXT_COLOR,
		bool adjust = GUI_BUTTON_DEFAULT_ADJUST,
		int width = GUI_BUTTON_DEFAULT_WIDTH,
		int height = GUI_BUTTON_DEFAULT_HEIGHT,
		int top = GUI_BUTTON_DEFAULT_TOP,
		int left = GUI_BUTTON_DEFAULT_LEFT,
		int color = GUI_BUTTON_COLOR,
		int colorPushed = GUI_BUTTON_COLOR_PUSHED,
		int borderSize = GUI_BUTTON_BORDER_SIZE,
		int borderColor = GUI_BUTTON_BORDER_COLOR,
		int borderColorSelected = GUI_BUTTON_BORDER_COLOR_SELECTED,
		int marginSize = GUI_BUTTON_MARGIN_SIZE,
		int paddingSize = GUI_BUTTON_PADDING_SIZE
	);
};

} /* namespace GUI */

#endif /* BUTTON_H_ */
