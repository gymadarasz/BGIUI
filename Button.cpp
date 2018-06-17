/*
 * Button.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#include "Button.h"

namespace GUI {

Button::Button(Canvas* parent): Label(parent) {
	setup();
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

Button* Button::setup(
	const char* text,
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
	Label::setup(
		text,
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
	setEnabled(true);
	return this;
}

} /* namespace GUI */
