/*
 * Scroll.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#include "Scroll.h"

namespace GUI {

Scroll::Scroll(Canvas* parent): Canvas(parent) {
	minusButton = 0;
	scrollAreaCanvas = 0;
	scrollHandlerCanvas = 0;
	plusButton = 0;
	setInitializedChildren(false);
	setInitializedValue(false);
	setup();
}

Scroll::~Scroll() {
	// TODO Auto-generated destructor stub
}

Scroll* Scroll::setup(
	int value,
	int minValue,
	int maxValue,
	char* minusText,
	char* plusText,
	bool adjust,
	int width,
	int height,
	int top,
	int left,
	int color,
	int colorPushed,
	int colorSelected,
	int borderSize,
	int borderColor,
	int borderColorSelected,
	int marginSize,
	int areaColor,
	int areaColorPushed,
	int handlerColor,
	int handlerColorPushed
){
	Canvas::setup(
		adjust,
		width,
		height,
		top,
		left,
		color,
		colorPushed,
		colorSelected,
		borderSize,
		borderColor,
		borderColorSelected,
		marginSize
	);
    setScrollHandler(0);
	initializeChildren(minusText, plusText, areaColor, areaColorPushed, handlerColor, handlerColorPushed);
	setValue(value);
	setMinValue(minValue);
	setMaxValue(maxValue);


	//setEnabled(true);
	return this;
}

Scroll* Scroll::setValue(int value) {
	if (this->value != value) {
		int previousValue = this->value;
		this->value = value;
		repositionScrollHandlerCanvas();

		if (!getInitializedValue()) {
			setInitializedValue(true);
		} else {
			onScroll(value, previousValue);
		}
	}
	return this;
}

Scroll* Scroll::setMinValue(int minValue) {
	this->minValue = minValue;
	repositionScrollHandlerCanvas();
	return this;
}

Scroll* Scroll::setMaxValue(int maxValue) {
	this->maxValue = maxValue;
	repositionScrollHandlerCanvas();
	return this;
}

int Scroll::getValue() {
	return value;
}

int Scroll::getMinValue() {
	return minValue;
}

int Scroll::getMaxValue() {
	return maxValue;
}


ScrollMinusButton* Scroll::getMinusButton() {
	return minusButton;
}

ScrollAreaCanvas* Scroll::getScrollAreaCanvas() {
	return scrollAreaCanvas;
}

ScrollHandlerCanvas* Scroll::getScrollHandlerCanvas() {
	return scrollHandlerCanvas;
}

ScrollPlusButton* Scroll::getPlusButton() {
	return plusButton;
}


CanvasEventHandler Scroll::getScrollHandler() {
	return onScrollHandler;
}

Canvas* Scroll::setScrollHandler(CanvasEventHandler onScrollHandler) {
	this->onScrollHandler = onScrollHandler;
	return this;
}

void Scroll::onScroll(int value, int previousValue) {
	CanvasEventHandler onScrollHandler = getScrollHandler();
	if (onScrollHandler) {
		onScrollHandler(this, value, previousValue);
	}
}

// private:

Scroll* Scroll::setMinusButton(ScrollMinusButton* minusButton) {
	this->minusButton = minusButton;
	return this;
}

Scroll* Scroll::setScrollAreaCanvas(ScrollAreaCanvas* scrollAreaCanvas) {
	this->scrollAreaCanvas = scrollAreaCanvas;
	return this;
}

Scroll* Scroll::setScrollHandlerCanvas(ScrollHandlerCanvas* scrollHandlerCanvas) {
	this->scrollHandlerCanvas = scrollHandlerCanvas;
	return this;
}

Scroll* Scroll::setPlusButton(ScrollPlusButton* plusButton) {
	this->plusButton = plusButton;
	return this;
}

Scroll* Scroll::setInitializedChildren(bool initializedChildren) {
	this->initializedChildren = initializedChildren;
	return this;
}

Scroll* Scroll::setInitializedValue(bool initializedValue) {
	this->initializedValue = initializedValue;
	return this;
}

bool Scroll::getInitializedChildren() {
	return initializedChildren;
}

bool Scroll::getInitializedValue() {
	return initializedValue;
}

// return true if it's the first initialization
bool Scroll::initializeChildren(char* minusText, char* plusText, int areaColor, int areaColorPushed, int handlerColor, int handlerColorPushed) {
	bool ret = false;
	if (!getInitializedChildren()) {
		setScrollAreaCanvas(new ScrollAreaCanvas(this));
		setMinusButton(new ScrollMinusButton(this));
		setPlusButton(new ScrollPlusButton(this));
		setScrollHandlerCanvas(new ScrollHandlerCanvas(getScrollAreaCanvas()));
		setInitializedChildren(true);
		ret = true;
	}

	ScrollPlusButton* plusButton = getPlusButton();
	ScrollMinusButton* minusButton = getMinusButton();
	ScrollAreaCanvas* areaCanvas = getScrollAreaCanvas();
	ScrollHandlerCanvas* handlerCanvas = getScrollHandlerCanvas();

	plusButton->setText(plusText);
	minusButton->setText(minusText);

	int plusButtonHeight = plusButton->getHeight();
	int minusButtonHeight = minusButton->getHeight();
	int plusButtonWidth = plusButton->getWidth();
	int minusButtonWidth = minusButton->getWidth();
	int width = getWidth();
	int height = getHeight();
	int scrollButtonsMaxHeight = height ? height : (plusButtonHeight > minusButtonHeight ? plusButtonHeight : minusButtonHeight);
	int scrollButtonsMaxWidth = plusButtonWidth > minusButtonWidth ? plusButtonWidth : minusButtonWidth;
	int scrollButtonsSizeMax = scrollButtonsMaxHeight > scrollButtonsMaxWidth ? scrollButtonsMaxHeight : scrollButtonsMaxWidth;
	int newAreaCanvasWidth = width ? width - scrollButtonsSizeMax * 2  : scrollButtonsMaxWidth * 3;

	minusButton
		->setAdjust(false)
		->setEnabled(true)
		->setBorderSize(0)
		->setMarginSize(0)
		->setWidth(scrollButtonsSizeMax)
		->setHeight(scrollButtonsSizeMax)
		->setTop(0)
		->setLeft(0)
		->setChangedBorder(true);
	areaCanvas
		->setAdjust(false)
		->setEnabled(true)
		->setBorderSize(0)
		->setMarginSize(0)
		->setWidth(newAreaCanvasWidth)
		->setHeight(scrollButtonsSizeMax)
		->setTop(0)
		->setLeft(scrollButtonsSizeMax)
		->setColor(areaColor)
		->setColorPushed(areaColorPushed)
		->setChangedBorder(true);
	handlerCanvas
		->setAdjust(false)
		->setEnabled(true)
		->setBorderSize(0)
		->setMarginSize(0)
		->setWidth(scrollButtonsSizeMax)
		->setHeight(scrollButtonsSizeMax)
		->setTop(0)
		->setLeft(0)
		->setColor(handlerColor)
		->setColorPushed(handlerColorPushed)
		->setChangedBorder(true);
	plusButton
		->setAdjust(false)
		->setEnabled(true)
		->setBorderSize(0)
		->setMarginSize(0)
		->setWidth(scrollButtonsSizeMax)
		->setHeight(scrollButtonsSizeMax)
		->setTop(0)
		->setLeft(scrollButtonsSizeMax + getScrollAreaCanvas()->calcWidthFull())
		->setChangedBorder(true);

	setWidth(
		getMinusButton()->calcWidthFull() +
		getScrollAreaCanvas()->calcWidthFull() +
		getPlusButton()->calcWidthFull()
	);
	setHeight(scrollButtonsSizeMax);
	//draw();

//	// TODO: !@# Problem: scroll canvas width + height isfailing => calculated Width + Haight added after draw() but needs to test
//	setWidth(
//		getMinusButton()->calcWidthFull() +
//		getScrollAreaCanvas()->calcWidthFull() +
//		getPlusButton()->calcWidthFull()
//	);
	return ret;
}

int Scroll::repositionScrollHandlerCanvas() {
	int newHandlerPosition = -1;
	ScrollAreaCanvas* scrollAreaCanvas = getScrollAreaCanvas();
	ScrollHandlerCanvas* scrollHandlerCanvas = getScrollHandlerCanvas();
	if (scrollAreaCanvas && scrollHandlerCanvas) {
		int value = getValue();
		int minValue = getMinValue();
		int maxValue = getMaxValue();
		int areaWidth = scrollAreaCanvas->getWidth();
		int handlerWidth = scrollHandlerCanvas->getWidth();
		int scrollSize = areaWidth - handlerWidth;
		int maxminDiff = abs(maxValue - minValue);
		if (maxminDiff > 0) {
			newHandlerPosition = (scrollSize * value) / maxminDiff;
			scrollHandlerCanvas->setLeft(newHandlerPosition);
			clear();
		}
	}
	return newHandlerPosition;
}


} /* namespace GUI */
