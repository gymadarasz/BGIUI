/*
 * Switch.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#include "Switch.h"

namespace GUI {

Switch::Switch(Canvas* parent): Button(parent) {
	setup();
}

Switch::~Switch() {
	// TODO Auto-generated destructor stub
}

Switch* Switch::setup(
	char* textOff,
	char* textOn,
	int textColor,
	bool adjust,
	int width,
	int height,
	int top,
	int left,
	int color,
	int colorPushed,
	int borderSize,
	int borderColor,
	int borderColorSelected,
	int marginSize,
	int paddingSize
){
	Button::setup(
		textOff,
		textColor,
		adjust,
		width,
		height,
		top,
		left,
		color,
		colorPushed,
		borderSize,
		borderColor,
		borderColorSelected,
		marginSize,
		paddingSize
	);
	setTextOff(textOff);
	setTextOn(textOn);
	return this;
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

// private


Switch* Switch::setTextOff(char* textOff) {
	this->textOff = textOff;
	return this;
}

Switch* Switch::setTextOn(char* textOn) {
	this->textOn = textOn;
	return this;
}

char* Switch::getTextOff() {
	return textOff;
}

char* Switch::getTextOn() {
	return textOn;
}


} /* namespace GUI */
