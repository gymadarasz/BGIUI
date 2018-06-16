/*
 * Counted.cpp
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */
#include <stdio.h>
#include "Canvas.h"

namespace GUI {

int Canvas::next = 0;
Canvas* Canvas::instances[CANVAS_INSTANCES] = {0};


// public:

Canvas::Canvas(Canvas* parent) {
	setId(next++);
	setParent(parent);
	setInstance(getId(), this);
	setup(false, 0, 0);
}

Canvas::~Canvas() {
	instances[getId()] = 0;
}

Canvas* Canvas::getInstance(int id) {
	return instances[id];
}

int Canvas::clearInstances() {
	int ret = 0;
	for (int i=0; i<CANVAS_INSTANCES; i++) {
		if(instances[i]) {
			//delete instances[i];
			instances[i] = 0;
			ret++;
		}
	}
	next = 0;
	return ret;
}

int Canvas::getId() {
	return id;
}

Canvas* Canvas::setup(
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
	int marginSize
) {
	setAdjust(adjust);
	setTop(top);
	setLeft(left);
	setWidth(width);
	setHeight(height);
	setColor(color);
	setColorPushed(colorPushed);
	setBorderSize(borderSize);
	setBorderColor(borderColor);
	setBorderColorSelected(borderColorSelected);
	setMarginSize(marginSize);
	setSelected(false);
	setPushed(false);
	setChangedBorder(true);
	setChangedInner(true);
	setLineBreak(false);
	return this;
}

int Canvas::draw(int offsetTop, int offsetLeft) {
	int ret = 0;
	ret += drawBorder(offsetTop, offsetLeft);
	ret += drawInner(offsetTop, offsetLeft);
	ret += drawChildren();
	return ret;
}

Canvas* Canvas::setLineBreak(bool lineBreak) {
	this->lineBreak = lineBreak;
	return this;
}

void Canvas::debugInstances() {
	printf("\nCanvas instances:");
	for (int i=0; i<CANVAS_INSTANCES; i++) {
		printf("\ncanvas[index:%d]\n", i);
		Canvas* current = getInstance(i);
		if (current) {
			printf("id:%d (top:%d, left:%d)\n", current->getId(), current->getTop(), current->getLeft());
			Canvas* parent = current->getParent();
			if (parent) {
				printf("parent-id:%d (top:%d, left:%d)\n", parent->getId(), parent->getTop(), parent->getLeft());
			} else {
				printf("parent:-none-\n");
			}
		} else {
			printf("-empty-\n");
		}
	}
}

// private:

bool Canvas::setInstance(int id, Canvas* canvas) {
	if (Canvas::instances[id] != canvas) {
		Canvas::instances[id] = canvas;
		return true;
	}
	return false;
}

Canvas* Canvas::setAdjust(bool adjust) {
	this->adjust = adjust;
	return this;
}

Canvas* Canvas::setId(int id) {
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

Canvas* Canvas::setMarginSize(int marginSize) {
	this->marginSize = marginSize;
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


Canvas* Canvas::getParent() {
	return parent;
}

int Canvas::getTop() {
	return top;
}

int Canvas::getColor() {
	return color;
}

int Canvas::getBorderSize() {
	return borderSize;
}

int Canvas::getColorPushed() {
	return colorPushed;
}

int Canvas::getBorderColor() {
	return borderColor;
}

int Canvas::getBorderColorSelected() {
	return borderColorSelected;
}

int Canvas::getMarginSize() {
	return marginSize;
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

bool Canvas::getLineBreak() {
	return lineBreak;
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

bool Canvas::drawBorder(int offsetTop, int offsetLeft) {
	if (getChangedBorder()) {
		Painter::rect(
			calcTopRelativeToParent() + offsetTop,
			calcLeftRelativeToParent() + offsetLeft,
			calcWidthFull(),
			calcHeightFull(),
			calcBorderColorCurrent()
		);
		setChangedBorder(false);
		return true;
	}
	return false;
}


int Canvas::drawChildren() {
	int ret = 0;

	// reset cursor
	cursor.reset(getWidth());

	// for each children
	for (int i = getId()+1; i<CANVAS_INSTANCES; i++) {
		Canvas* child = getInstance(i);
		Canvas* parent = child ? child->getParent() : 0;
		if (child && parent && parent->getId() == getId()) {

			int offsetTop = 0;
			int offsetLeft = 0;

			if (child->getAdjust()) {

				int childMarginSize = child->getMarginSize();
				int childCalcWidhtFull = child->calcWidthFull();
				int childCalcHeightFull = child->calcHeightFull();
				bool childLineBreak = child->getLineBreak();

				if (childLineBreak) {
					cursor.br();
				}

				offsetTop = childMarginSize + cursor.getTop();
				offsetLeft = childMarginSize + cursor.getLeft();
				if(cursor.step(childCalcWidhtFull + childMarginSize*2, childCalcHeightFull + childMarginSize*2)) {
					offsetTop = childMarginSize + cursor.getTop();
					offsetLeft = childMarginSize + cursor.getLeft();
					if(cursor.step(childCalcWidhtFull + childMarginSize*2, childCalcHeightFull + childMarginSize*2)) {
						// TODO: child element width greater then child's parent (this) element width. do we extends parent (this) size? (may if its adjust?)? - if so then resize the cursor too!!
					}
				}
			}

			// draw it
			child->draw(offsetTop, offsetLeft);
			ret++;
		}
	}
	return ret;
}

// protected:

Canvas* Canvas::setWidth(int width) {
	this->width = width;
	return this;
}

Canvas* Canvas::setHeight(int height) {
	this->height = height;
	return this;
}

Canvas* Canvas::setChangedInner(bool changedInner) {
	this->changedInner = changedInner;
	return this;
}

bool Canvas::drawInner(int offsetTop, int offsetLeft) {
	if (getChangedInner()) {
		Painter::fillrect(
			calcTopRelativeToParent() + getBorderSize() + offsetTop,
			calcLeftRelativeToParent() + getBorderSize() + offsetLeft,
			getWidth(),
			getHeight(),
			calcColorCurrent()
		);
		setChangedInner(false);
		return true;
	}
	return false;
}

bool Canvas::getAdjust() {
	return adjust;
}

int Canvas::getWidth() {
	return width;
}

int Canvas::getHeight() {
	return height;
}

int Canvas::getLeft() {
	return left;
}


int Canvas::calcTopRelativeToParent() {
	int top = getTop();
	return parent ? parent->calcTopRelativeToParent() + top : top;
}

int Canvas::calcLeftRelativeToParent() {
	int left = getLeft();
	return parent ? parent->calcLeftRelativeToParent() + left : left;
}

} /* namespace GUI */
