/*
 * Label.cpp
 *
 *  Created on: Jun 16, 2018
 *      Author: Gyula
 */

#include "Label.h"

namespace GUI {

Label::Label(Canvas* parent): Canvas(parent) {
	text = GUI_LABEL_DEFAULT_TEXT;
	textColor = GUI_LABEL_TEXT_COLOR;
	paddingSize = GUI_LABEL_PADDING_SIZE;
	setup();
}

Label::~Label() {
	// TODO Auto-generated destructor stub
}

Label* Label::setup(
	char* text,
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
	Canvas::setup(
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
		marginSize
	);
	setText(text);
	setTextColor(textColor);
	setPaddingSize(paddingSize);
	return this;
}

Label* Label::setText(char* text) {
	// TODO: check if text already same as new text
	this->text = text;
	if (getAdjust()) {
		clear();
		int padding = getPaddingSize();
		setWidth(Painter::getTextWidth(text) + padding);
		setHeight(Painter::getTextHeight(text) + padding);
	}
	setChangedInner(true);
	return this;
}

// private

Label* Label::setTextColor(int textColor) {
	this->textColor = textColor;
	return this;
}

Label* Label::setPaddingSize(int paddingSize) {
	this->paddingSize = paddingSize;
	return this;
}

char* Label::getText() {
	return text;
}

int Label::getTextColor() {
	return textColor;
}

int Label::getPaddingSize() {
	return paddingSize;
}

bool Label::drawInner(int offsetTop, int offsetLeft) {
	if (Canvas::drawInner(offsetTop, offsetLeft)) {
		if (!getNoDraw()) {
			char* text = getText();
			int color = getPushed() ? getColorPushed() : getColor();
			int textColor = getTextColor();
			int borderSize = getBorderSize();
			int paddingSize = getPaddingSize();
			int topRelative = calcTopRelativeToParent();
			int leftRelative = calcLeftRelativeToParent();
			int textTop = topRelative + borderSize + paddingSize/2 + offsetTop;
			int textLeft = leftRelative + borderSize + paddingSize/2 + offsetLeft;
			Painter::text(textTop, textLeft, text, textColor, color);
		}
		return true;
	}
	return false;
}

} /* namespace GUI */
