/*
 * Counted.cpp
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#include "Canvas.h"

namespace GUI {

int Canvas::next = 0;
Canvas* Canvas::instances[GUI_CANVAS_INSTANCES] = {0};


void Canvas::setInstance(int id, Canvas* canvas) {
	Canvas::instances[id] = canvas;
}

Canvas* Canvas::setId(int id) {
	setInstance(id, this);
	this->id = id;
	return this;
}

Canvas* Canvas::setParent(Canvas* parent) {
	this->parent = parent;
	return this;
}

Canvas* Canvas::setTop(int top) {
	this->top = top;
	return this;
}

Canvas* Canvas::setLeft(int left) {
	this->left = left;
	return this;
}

Canvas* Canvas::setWidth(int width) {
	this->width = width;
	return this;
}

Canvas* Canvas::setHeight(int height) {
	this->height = height;
	return this;
}

Canvas* Canvas::setColor(int color) {
	this->color = color;
	return this;
}

Canvas* Canvas::setColorPushed(int colorPushed) {
	this->colorPushed = colorPushed;
	return this;
}

Canvas* Canvas::setBorderSize(int borderSize) {
	this->borderSize = borderSize;
	return this;
}

Canvas* Canvas::setBorderColor(int borderColor) {
	this->borderColor = borderColor;
	return this;
}


Canvas* Canvas::setBorderColorSelected(int borderColorSelected) {
	this->borderColorSelected = borderColorSelected;
	return this;
}

Canvas* Canvas::setSelected(bool selected) {
	this->selected = selected;
	return this;
}

Canvas* Canvas::setPushed(bool pushed) {
	this->pushed = pushed;
	return this;
}

Canvas* Canvas::setChangedBorder(bool changedBorder) {
	this->changedBorder = changedBorder;
	return this;
}

Canvas* Canvas::setChangedInner(bool changedInner) {
	this->changedInner = changedInner;
	return this;
}


Canvas* Canvas::getParent() {
	return parent;
}

int Canvas::getTop() {
	return top;
}

int Canvas::getLeft() {
	return left;
}

int Canvas::getWidth() {
	return width;
}

int Canvas::getHeight() {
	return height;
}

int Canvas::getColor() {
	return color;
}

int Canvas::getColorPushed() {
	return colorPushed;
}

int Canvas::getBorderSize() {
	return borderSize;
}

int Canvas::getBorderColor() {
	return borderColor;
}

int Canvas::getBorderColorSelected() {
	return borderColorSelected;
}

bool Canvas::getSelected() {
	return selected;
}

bool Canvas::getPushed() {
	return pushed;
}

bool Canvas::getChangedBorder() {
	return changedBorder;
}

bool Canvas::getChangedInner() {
	return changedInner;
}



int Canvas::calcTopAbsolute() {
	int top = getTop();
	return parent ? parent->calcTopAbsolute() + top : top;
}

int Canvas::calcLeftAbsolute() {
	int left = getLeft();
	return parent ? parent->calcLeftAbsolute() + left : left;
}

int Canvas::calcWidthFull() {
	return getWidth() + getBorderSize()*2;
}

int Canvas::calcHeightFull() {
	return getHeight() + getBorderSize()*2;
}

int Canvas::calcColorCurrent() {
	return getPushed() ? getColorPushed() : getColor();
}

int Canvas::calcBorderColorCurrent() {
	return getSelected() ? getBorderColorSelected() : getBorderColor();
}

int Canvas::calcTopBorderAbsolute() {
	return calcTopAbsolute() - getBorderSize();
}

int Canvas::calcLeftBorderAbsolute() {
	return calcLeftAbsolute() - getBorderSize();
}


void Canvas::drawBorder() {
	if (getChangedBorder()) {
		Painter::rect(
			calcTopBorderAbsolute(),
			calcLeftBorderAbsolute(),
			calcWidthFull(),
			calcHeightFull(),
			calcBorderColorCurrent()
		);
	}
}

void Canvas::drawInner() {
	if (getChangedInner()) {
		Painter::fillrect(
			calcTopAbsolute(),
			calcLeftAbsolute(),
			getWidth(),
			getHeight(),
			calcColorCurrent()
		);
	}
}

// public:

Canvas::Canvas(Canvas* parent) {
	setId(next++);
	setParent(parent);
}

Canvas::~Canvas() {
	instances[getId()] = 0;
}

Canvas* Canvas::getInstance(int id) {
	return instances[id];
}

int Canvas::getId() {
	return id;
}

Canvas* Canvas::setup(
	int width,
	int height,
	int top,
	int left,
	int color,
	int colorPushed,
	int borderSize,
	int borderColor,
	int borderColorSelected
) {
	setTop(top);
	setLeft(left);
	setWidth(width);
	setHeight(height);
	setColor(color);
	setColorPushed(colorPushed);
	setBorderSize(borderSize);
	setBorderColor(borderColor);
	setBorderColorSelected(borderColorSelected);
	setSelected(false);
	setPushed(false);
	setChangedBorder(true);
	setChangedInner(true);
	return this;
}

void Canvas::draw() {
	drawBorder();
	drawInner();
}

} /* namespace GUI */
