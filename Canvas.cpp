/*
 * Counted.cpp
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#include "Canvas.h"

namespace GUI {

int Canvas::next = 0;
Canvas* Canvas::instances[GUI_CANVAS_INSTANCES_MAX] = {0};

Canvas* Canvas::setId(int id) {
	instances[id] = this;

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

// public:

Canvas::Canvas(Canvas* parent) {
	setId(next++);
	setParent(parent);
}

Canvas::~Canvas() {
	instances[getId()] = 0;
}

int Canvas::getId() {
	return id;
}

Canvas* Canvas::setup(int top, int left, int width, int height, int color) {
	setTop(top);
	setLeft(left);
	setWidth(width);
	setHeight(height);
	setColor(color);
	return this;
}

} /* namespace GUI */
