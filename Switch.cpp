/*
 * Switch.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#include "Switch.h"

namespace GUI {

Switch::Switch(Canvas* parent): Button(parent) {
//	setup();
//	strcpy(textOn, "On");
//	strcpy(textOff, "Off");
	setTextOff((char*)GUI_SWITCH_DEFAULT_TEXT_OFF);
	setTextOn((char*)GUI_SWITCH_DEFAULT_TEXT_ON);
	setTextColor(GUI_SWITCH_TEXT_COLOR);
	setAdjust(GUI_SWITCH_DEFAULT_ADJUST);
	setWidth(GUI_SWITCH_DEFAULT_WIDTH);
	setHeight(GUI_SWITCH_DEFAULT_HEIGHT);
	setTop(GUI_SWITCH_DEFAULT_TOP);
	setLeft(GUI_SWITCH_DEFAULT_LEFT);
	setColor(GUI_SWITCH_COLOR);
	setColorPushed(GUI_SWITCH_COLOR_PUSHED);
	setColorSelected(GUI_SWITCH_COLOR_SELECTED);
	setBorderSize(GUI_SWITCH_BORDER_SIZE);
	setBorderColor(GUI_SWITCH_BORDER_COLOR);
	setBorderColorSelected(GUI_SWITCH_BORDER_COLOR_SELECTED);
	setMarginSize(GUI_SWITCH_MARGIN_SIZE);
	setPaddingSize(GUI_SWITCH_PADDING_SIZE);
}

Switch::~Switch() {
	// TODO Auto-generated destructor stub
}

//Switch* Switch::setup(
//	char* textOff,
//	char* textOn,
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
//	Button::setup(
//		textOff,
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
//	setTextOff(textOff);
//	setTextOn(textOn);
//	return this;
//}


Switch* Switch::setTextOff(char* textOff) {
	strcpy(this->textOff, textOff);
	return this;
}

Switch* Switch::setTextOn(char* textOn) {
	strcpy(this->textOn, textOn);
	return this;
}

char* Switch::getTextOff() {
	return textOff;
}

char* Switch::getTextOn() {
	return textOn;
}

void Switch::onMouseDown(int mouseLeft, int mouseTop) {
	if (getEnabled()) {
		setPushed(!getPushed());
		if (getPushed()) {
			setText(textOn);
		} else {
			setText(textOff);
		}
	}
	CanvasEventHandler onMouseDownHandler = getMouseDownHandler();
	if (onMouseDownHandler) {
		onMouseDownHandler(this, mouseLeft, mouseTop);
	}
}

void Switch::onMouseUp(int mouseLeft, int mouseTop) {
	CanvasEventHandler onMouseUpHandler = getMouseUpHandler();
	if (onMouseUpHandler) {
		onMouseUpHandler(this, mouseLeft, mouseTop);
	}
}


} /* namespace GUI */
