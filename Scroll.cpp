/*
 * Scroll.cpp
 *
 *  Created on: Jun 24, 2018
 *      Author: Gyula
 */

#include "Scroll.h"

namespace gui {

// ----------- ScrollHandler ---------

// public

ScrollHandler::ScrollHandler(Canvas* parent, int width, int height): Canvas(parent, width, height) {

}

ScrollHandler::~ScrollHandler() {}

void ScrollHandler::onKeyPress(int key) {
	Canvas::onKeyPress(key);

	Scroll* scroll = (Scroll*)parent;

	switch (key) {

	case KEY_UP:
		scroll->setValue(scroll->getValue()+1);
		break;

	case KEY_DOWN:
		scroll->setValue(scroll->getValue()-1);
		break;

	case KEY_HOME:
		scroll->setValue(scroll->getMinValue());
		break;

	case KEY_END:
		scroll->setValue(scroll->getMaxValue());
		break;
	}
}


// --------- Scroll ------------

int Scroll::repositionScrollHandlerCanvas() {
	int newHandlerPosition = -1;
	if (handler) {
		int areaWidth = box.width;
		int handlerWidth = handler->getFullWidth();
		int scrollSize = areaWidth - handlerWidth;
		int maxminDiff = abs(maxValue - minValue);
		if (maxminDiff > 0) {
			newHandlerPosition = (scrollSize * value) / maxminDiff;
			handler->setPosition(0, newHandlerPosition, false);
		}
		//draw();
	}
	return newHandlerPosition;
}


// public

Scroll::Scroll(Canvas* parent, int width, int height): Canvas(parent, width, height) {
	handler = 0;
	value = 0;
	minValue = 0;
	maxValue = 0;
	onScrollHandler = 0;
	handler = new ScrollHandler(this);
	handler->setText("<->");
	setValue(0);
	setInterval(0, 100);
	if (!width && handler) {
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
	if (value < this->minValue) {
		value = this->minValue;
	}
	if (value > this->maxValue) {
		value = this->maxValue;
	}
	if (this->value != value) {
		handler->clear();
		int oldValue = this->value;
		this->value = value;

		repositionScrollHandlerCanvas();

		cursorReset();
		handler->calc();
		handler->draw();
		onScroll(oldValue, this->value);
	}
}

int Scroll::getValue() {
	return value;
}

void Scroll::onClick(int mouseLeft, int mouseTop) {
	Canvas::onClick(mouseLeft, mouseTop);

	if (handler) {
		int areaWidth = box.width;
		int handlerWidth = handler->getFullWidth();
		int scrollSize = areaWidth - handlerWidth;
		int minmaxDiff = abs(maxValue - minValue);
		int clickLeft = mouseLeft - (handlerWidth / 2);
		int newValue = (clickLeft * minmaxDiff) / scrollSize;
		setValue(newValue);
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
