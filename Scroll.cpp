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
	int borderSize,
	int borderColor,
	int borderColorSelected,
	int marginSize,
	int areaColor,
	int areaColorPushed
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
    setScrollHandler(0);
	setValue(value);
	setMinValue(minValue);
	setMaxValue(maxValue);

	initializeChildren(minusText, plusText, areaColor, areaColorPushed);

	//setEnabled(true);
	return this;
}

Scroll* Scroll::setValue(int value) {
	if (this->value != value) {
		int previousValue = this->value;
		this->value = value;
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
	return this;
}

Scroll* Scroll::setMaxValue(int maxValue) {
	this->maxValue = maxValue;
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

Button* Scroll::getMinusButton() {
	return minusButton;
}

Canvas* Scroll::getScrollAreaCanvas() {
	return scrollAreaCanvas;
}

Canvas* Scroll::getScrollHandlerCanvas() {
	return scrollHandlerCanvas;
}

Button* Scroll::getPlusButton() {
	return plusButton;
}

bool Scroll::getInitializedChildren() {
	return initializedChildren;
}

bool Scroll::getInitializedValue() {
	return initializedValue;
}

// return true if it's the first initialization
bool Scroll::initializeChildren(char* minusText, char* plusText, int areaColor, int areaColorPushed) {
	bool ret = false;
	if (!getInitializedChildren()) {
		setScrollAreaCanvas(new ScrollAreaCanvas(this));
		setMinusButton(new ScrollMinusButton(this));
		setPlusButton(new ScrollPlusButton(this));
		setScrollHandlerCanvas(new ScrollHandlerCanvas(getScrollAreaCanvas()));
		setInitializedChildren(true);
		ret = true;
	}

	Button* plusButton = getPlusButton();
	Button* minusButton = getMinusButton();

	plusButton->setText(plusText);
	minusButton->setText(minusText);

	int plusButtonHeight = plusButton->getHeight();
	int minusButtonHeight = minusButton->getHeight();
	int plusButtonWidth = plusButton->getWidth();
	int minusButtonWidth = minusButton->getWidth();
	int scrollButtonsMaxHeight = plusButtonHeight > minusButtonHeight ? plusButtonHeight : minusButtonHeight;
	int scrollButtonsMaxWidth = plusButtonWidth > minusButtonWidth ? plusButtonWidth : minusButtonWidth;
	int scrollButtonsSizeMax = scrollButtonsMaxHeight > scrollButtonsMaxWidth ? scrollButtonsMaxHeight : scrollButtonsMaxWidth;

	getMinusButton()
		->setAdjust(false)
		->setEnabled(true)
		->setBorderSize(0)
		->setMarginSize(0)
		->setWidth(scrollButtonsSizeMax)
		->setHeight(scrollButtonsSizeMax)
		->setTop(0)
		->setLeft(0)
		->setChangedBorder(true);
	getScrollAreaCanvas()
		->setAdjust(false)
		->setEnabled(true)
		->setBorderSize(0)
		->setMarginSize(0)
		->setHeight(scrollButtonsSizeMax)
		->setTop(0)
		->setLeft(scrollButtonsSizeMax)
		->setColor(areaColor)
		->setColorPushed(areaColorPushed)
		->setChangedBorder(true);
	if (getWidth() == 0) {
		getScrollAreaCanvas()->setWidth(scrollButtonsMaxWidth * 3);
	}
	getScrollHandlerCanvas()
		->setAdjust(false)
		->setEnabled(true)
		->setBorderSize(0)
		->setMarginSize(0)
		->setWidth(scrollButtonsSizeMax)
		->setHeight(scrollButtonsSizeMax)
		->setTop(0)
		->setLeft(0)
		->setChangedBorder(true);
	getPlusButton()
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
	draw();

//	// TODO: !@# Problem: scroll canvas width + height isfailing => calculated Width + Haight added after draw() but needs to test
//	setWidth(
//		getMinusButton()->calcWidthFull() +
//		getScrollAreaCanvas()->calcWidthFull() +
//		getPlusButton()->calcWidthFull()
//	);
	return ret;
}


} /* namespace GUI */
