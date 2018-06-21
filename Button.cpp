/*
 * Button.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#include "Button.h"

namespace GUI {

Button::Button(Canvas* parent): Label(parent) {//	Text text,
	setText((char*)GUI_BUTTON_DEFAULT_TEXT);
	setTextColor(GUI_BUTTON_TEXT_COLOR);
	setAdjust(GUI_BUTTON_DEFAULT_ADJUST);
	setWidth(GUI_BUTTON_DEFAULT_WIDTH);
	setHeight(GUI_BUTTON_DEFAULT_HEIGHT);
	setTop(GUI_BUTTON_DEFAULT_TOP);
	setLeft(GUI_BUTTON_DEFAULT_LEFT);
	setColor(GUI_BUTTON_COLOR);
	setColorPushed(GUI_BUTTON_COLOR_PUSHED);
	setColorSelected(GUI_BUTTON_COLOR_SELECTED);
	setBorderSize(GUI_BUTTON_BORDER_SIZE);
	setBorderColor(GUI_BUTTON_BORDER_COLOR);
	setBorderColorSelected(GUI_BUTTON_BORDER_COLOR_SELECTED);
	setMarginSize(GUI_BUTTON_MARGIN_SIZE);
	setPaddingSize(GUI_BUTTON_PADDING_SIZE);
	setEnabled(true);
//	setup();
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

//Button* Button::setup(
//	Text text,
//	int textColor,
//	bool adjust,
//	int width,
//	int height,
//	int top,
//	int left,
//	int color,
//	int colorPushed,
//	int colorSelected,
//	int borderSize,
//	int borderColor,
//	int borderColorSelected,
//	int marginSize,
//	int paddingSize
//){
//	Label::setup(
//		text,
//		textColor,
//		adjust,
//		width,
//		height,
//		top,
//		left,
//		color,
//		colorPushed,
//		colorSelected,
//		borderSize,
//		borderColor,
//		borderColorSelected,
//		marginSize,
//		paddingSize
//	);
//	setEnabled(true);
//	return this;
//}

} /* namespace GUI */
