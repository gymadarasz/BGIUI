/*
 * Scroll.cpp
 *
 *  Created on: Jun 24, 2018
 *      Author: Gyula
 */

#include "Scroll.h"

namespace gui {

int Scroll::repositionScrollHandlerCanvas() {
	int newHandlerPosition = -1;
	int areaWidth = box.width;
	int handlerWidth = handler->getFullWidth();
	int scrollSize = areaWidth - handlerWidth;
	int maxminDiff = abs(maxValue - minValue);
	if (maxminDiff > 0) {
		newHandlerPosition = (scrollSize * value) / maxminDiff;
		handler->setPosition(0, newHandlerPosition, false);
	}
	//draw();
	return newHandlerPosition;
}


// public

Scroll::Scroll(Canvas* parent, int width, int height): Canvas(parent, width, height) {
	handler = new Canvas(this);
	handler->setText("<->");
	setInterval(0, 100);
	setValue(0);
	if (!width) {
		setWidth(handler->getFullWidth() * 3);

	}
}

Scroll::~Scroll() {}

void Scroll::setInterval(int minValue, int maxValue) {
	this->minValue = minValue;
	this->maxValue = maxValue;
	if (value < this->minValue) {
		value = this->minValue;
	}
	if (value > this->maxValue) {
		value = this->maxValue;
	}
	repositionScrollHandlerCanvas();
}

void Scroll::setValue(int value) {
	this->value = value;
	if (value < this->minValue) {
		value = this->minValue;
	}
	if (value > this->maxValue) {
		value = this->maxValue;
	}
	repositionScrollHandlerCanvas();
}

int Scroll::getValue() {
	return value;
}

void Scroll::onClick(int mouseLeft, int mouseTop) {
	Canvas::onClick(mouseLeft, mouseTop);

	int areaWidth = box.width;
	int handlerWidth = handler->getFullWidth();
	int scrollSize = areaWidth - handlerWidth;
	int minmaxDiff = abs(maxValue - minValue);
	int clickLeft = mouseLeft - (handlerWidth / 2);
	int newValue = (clickLeft * minmaxDiff) / scrollSize;
	if (newValue < minValue) {
		newValue = minValue;
	}
	if (newValue > maxValue) {
		newValue = maxValue;
	}
	if (value != newValue) {
		int oldValue = value;
		handler->clear();
		setValue(newValue);
		cursorReset();
		handler->calc();
		handler->draw();
		onScroll(oldValue, newValue);
	}

}

void Scroll::onMouseDrag(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent) {
	Canvas::onMouseDrag(mouseLeftFrom, mouseTopFrom, mouseLeftCurrent, mouseTopCurrent);
	onClick(mouseLeftCurrent, mouseTopCurrent);
}

void Scroll::onScroll(int oldValue, int newValue) {
	if (onScrollHandler) {
		onScrollHandler(this, oldValue, newValue);
	}
}

} /* namespace gui */
