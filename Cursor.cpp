/*
 * Cursor.cpp
 *
 *  Created on: Jun 16, 2018
 *      Author: Gyula
 */

#include "Cursor.h"

namespace GUI {

void Cursor::reset(int width, int top, int left) {
	setWidth(width);
	setTop(top);
	setLeft(left);
	setLineHeight(0);
}

bool Cursor::step(int width, int height) {
	bool br = false;
	int top = getTop();
	int left = getLeft();
	int lineHeight = getLineHeight();
	left += width;
	if(left > getWidth()) {
		left = 0;
		top += lineHeight;
		lineHeight = height;
		br = true;
	} else {
		lineHeight = lineHeight > height ? lineHeight : height;
	}
	setTop(top);
	setLeft(left);
	setLineHeight(lineHeight);
	return br;
}

// private

Cursor* Cursor::setWidth(int width) {
	this->width = width;
	return this;
}

Cursor* Cursor::setTop(int top) {
	this->top = top;
	return this;
}

Cursor* Cursor::setLeft(int left) {
	this->left = left;
	return this;
}

Cursor* Cursor::setLineHeight(int lineHeight) {
	this->lineHeight = lineHeight;
	return this;
}

void Cursor::br() {
	int top = getTop();
	int left = getLeft();
	int lineHeight = getLineHeight();
	top = top + lineHeight;
	left = 0;
	lineHeight = 0;
	setTop(top);
	setLeft(left);
	setLineHeight(lineHeight);
}

int Cursor::getWidth() {
	return width;
}

int Cursor::getTop() {
	return top;
}

int Cursor::getLeft() {
	return left;
}

int Cursor::getLineHeight() {
	return lineHeight;
}


} /* namespace GUI */
