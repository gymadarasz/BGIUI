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
	setEnabled(false);
	setScreenTop(-1);
	setScreenLeft(-1);

	// clear event handlers
    setTickHandler(0);
    setClickHandler(0);
    setDblClickHandler(0);
    setMouseMoveHandler(0);
    setMouseDragHandler(0);
    setMouseOverHandler(0);
    setMouseLeaveHandler(0);
    setMouseDownHandler(0);
    setMouseUpHandler(0);

	return this;
}

int Canvas::tick() {
	int ret = tickChildren();

	onTick();
	ret++;

    if (!getEnabled()) {
        return -1;
    }

    int top = getTop();
    int left = getLeft();

    // click?
    if (Mouse::events.click.happend && isInside(Mouse::events.click.position)) {
        onClick(Mouse::events.click.position.left-left, Mouse::events.click.position.top-top);
        ret++;
    }

    // dblclick?
    if (Mouse::events.dblClick.happend && isInside(Mouse::events.dblClick.position)) {
        onDblClick(Mouse::events.dblClick.position.left-left, Mouse::events.dblClick.position.top-top);
        ret++;
    }

    // mouse move, over, leave?
    if (Mouse::events.mouseMove.happend) {
        if (isInside(Mouse::events.mouseMove.current) && isInside(Mouse::events.mouseMove.previous)) {
            onMouseMove(
                Mouse::events.mouseMove.current.left-left, Mouse::events.mouseMove.current.top-top,
                Mouse::events.mouseMove.previous.left-left, Mouse::events.mouseMove.previous.top-top
            );
            ret++;
        } else if (isInside(Mouse::events.mouseMove.current)) {
            onMouseOver(Mouse::events.mouseMove.current.left-left, Mouse::events.mouseMove.current.top-top);
            ret++;
        } else if (isInside(Mouse::events.mouseMove.previous)) {
            onMouseLeave(Mouse::events.mouseMove.previous.left-left, Mouse::events.mouseMove.previous.top-top);
            ret++;
        }
    }

    if (Mouse::events.mouseDrag.happend) {
        if (isInside(Mouse::events.mouseDrag.current) && isInside(Mouse::events.mouseDrag.previous)) {
            onMouseDrag(
                Mouse::events.mouseDrag.current.left-left, Mouse::events.mouseDrag.current.top-top,
                Mouse::events.mouseDrag.previous.left-left, Mouse::events.mouseDrag.previous.top-top
            );
            ret++;
        }
    }

    // mouse down?
    if (Mouse::events.mouseDown.happend && isInside(Mouse::events.mouseDown.position)) {
        onMouseDown(Mouse::events.mouseDown.position.left-left, Mouse::events.mouseDown.position.top-top);
        ret++;
    }

    // mouse up?
    if (Mouse::events.mouseUp.happend && isInside(Mouse::events.mouseUp.position)) {
        onMouseUp(Mouse::events.mouseUp.position.left-left, Mouse::events.mouseUp.position.top-top);
        ret++;
    }

	return ret;
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

int Canvas::selectNext() {
	int i = calcFirstSelected() + 1;
	unselectAll();
	for (; i < CANVAS_INSTANCES; i++) {
		Canvas* canvas = getInstance(i);
		if (canvas && canvas->getEnabled()) {
			canvas->onMouseOver(-1, -1);
			//canvas->setSelected(true);
			return i;
		}
	}
	return -1;
}

int Canvas::selectPrev() {
	int i = calcLastSelected() - 1;
	unselectAll();
	for (; i >= 0; i--) {
		Canvas* canvas = getInstance(i);
		if (canvas && canvas->getEnabled()) {
			canvas->onMouseOver(-1, -1);
			//canvas->setSelected(true);
			return i;
		}
	}
	return -1;
}

int Canvas::selectedsClick() {
	int ret = 0;
	for (int i = 0; i < CANVAS_INSTANCES; i++) {
		Canvas* canvas = getInstance(i);
		if (canvas && canvas->getEnabled()) {
			canvas->onMouseDown(-1, -1);
			canvas->onClick(-1, -1);
			canvas->onMouseUp(-1, -1);
			ret++;
		}
	}
	return ret;
}

int Canvas::clearAll() {
	int ret = 0;
	for (int i = 0; i < CANVAS_INSTANCES; i++) {
		Canvas* canvas = getInstance(i);
		if (canvas) {
			canvas->clear();
			ret++;
		}
	}
	return ret;
}

// (events getters)
CanvasEventHandler Canvas::getTickHandler() {
	return onTickHandler;
}

CanvasEventHandler Canvas::getClickHandler() {
	return onClickHandler;
}

CanvasEventHandler Canvas::getDblClickHandler() {
	return onDblClickHandler;
}

CanvasEventHandler Canvas::getMouseMoveHandler() {
	return onMouseMoveHandler;
}

CanvasEventHandler Canvas::getMouseDragHandler() {
	return onMouseDragHandler;
}

CanvasEventHandler Canvas::getMouseOverHandler() {
	return onMouseOverHandler;
}

CanvasEventHandler Canvas::getMouseLeaveHandler() {
	return onMouseLeaveHandler;
}

CanvasEventHandler Canvas::getMouseDownHandler() {
	return onMouseDownHandler;
}

CanvasEventHandler Canvas::getMouseUpHandler() {
	return onMouseUpHandler;
}


// (events setters)

Canvas* Canvas::setTickHandler(CanvasEventHandler canvasEventHandler) {
	this->onTickHandler = canvasEventHandler;
	return this;
}

Canvas* Canvas::setClickHandler(CanvasEventHandler canvasEventHandler) {
	this->onClickHandler = canvasEventHandler;
	return this;
}

Canvas* Canvas::setDblClickHandler(CanvasEventHandler canvasEventHandler) {
	this->onDblClickHandler = canvasEventHandler;
	return this;
}

Canvas* Canvas::setMouseMoveHandler(CanvasEventHandler canvasEventHandler) {
	this->onMouseMoveHandler = canvasEventHandler;
	return this;
}

Canvas* Canvas::setMouseDragHandler(CanvasEventHandler canvasEventHandler) {
	this->onMouseDragHandler = canvasEventHandler;
	return this;
}

Canvas* Canvas::setMouseOverHandler(CanvasEventHandler canvasEventHandler) {
	this->onMouseOverHandler = canvasEventHandler;
	return this;
}

Canvas* Canvas::setMouseLeaveHandler(CanvasEventHandler canvasEventHandler) {
	this->onMouseLeaveHandler = canvasEventHandler;
	return this;
}

Canvas* Canvas::setMouseDownHandler(CanvasEventHandler canvasEventHandler) {
	this->onMouseDownHandler = canvasEventHandler;
	return this;
}

Canvas* Canvas::setMouseUpHandler(CanvasEventHandler canvasEventHandler) {
	this->onMouseUpHandler = canvasEventHandler;
	return this;
}

// events

void Canvas::onTick() {
	CanvasEventHandler onTickHandler = getTickHandler();
    if (onTickHandler) {
        onTickHandler(this);
    }
}

void Canvas::onClick(int mouseLeft, int mouseTop) {
	CanvasEventHandler onClickHandler = getClickHandler();
	if (onClickHandler) {
		onClickHandler(this, mouseLeft, mouseTop);
	}
}

void Canvas::onDblClick(int mouseLeft, int mouseTop) {
	CanvasEventHandler onDblClickHandler = getDblClickHandler();
	if (onDblClickHandler) {
		onDblClickHandler(this, mouseLeft, mouseTop);
	}
}

void Canvas::onMouseMove(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent) {
	CanvasEventHandler onMouseMoveHandler = getMouseMoveHandler();
	if (onMouseMoveHandler) {
		onMouseMoveHandler(this, mouseLeftFrom, mouseTopFrom, mouseLeftCurrent, mouseTopCurrent);
	}
}

void Canvas::onMouseOver(int mouseLeft, int mouseTop) {
	if (getEnabled()) {
		unselectAll();
		setSelected(true);
	}

	CanvasEventHandler onMouseOverHandler = getMouseOverHandler();
	if (onMouseOverHandler) {
		onMouseOverHandler(this, mouseLeft, mouseTop);
	}
}

void Canvas::onMouseLeave(int mouseLeft, int mouseTop) {
	if (getEnabled()) {
		setSelected(false);
	}
	CanvasEventHandler onMouseLeaveHandler = getMouseLeaveHandler();
	if (onMouseLeaveHandler) {
		onMouseLeaveHandler(this, mouseLeft, mouseTop);
	}
}

void Canvas::onMouseDrag(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent) {
	CanvasEventHandler onMouseDragHandler = getMouseDragHandler();
	if (onMouseDragHandler) {
		onMouseDragHandler(this, mouseLeftFrom, mouseTopFrom, mouseLeftCurrent, mouseTopCurrent);
	}
}

void Canvas::onMouseDown(int mouseLeft, int mouseTop) {
	if (getEnabled()) {
		setPushed(true);
	}
	CanvasEventHandler onMouseDownHandler = getMouseDownHandler();
	if (onMouseDownHandler) {
		onMouseDownHandler(this, mouseLeft, mouseTop);
	}
}

void Canvas::onMouseUp(int mouseLeft, int mouseTop) {
	if (getEnabled()) {
		setPushed(false);
	}
	CanvasEventHandler onMouseUpHandler = getMouseUpHandler();
	if (onMouseUpHandler) {
		onMouseUpHandler(this, mouseLeft, mouseTop);
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
	if (this->selected != selected) {
		this->selected = selected;
		if (getBorderColorSelected() != getBorderColor()) {
			setChangedBorder(true);
		}
		// TODO: getColorSelected() => setChangedInner(true)
	}
	return this;
}

Canvas* Canvas::setPushed(bool pushed) {
	if (this->pushed != pushed) {
		this->pushed = pushed;
		if (getColorPushed() != getColor()) {
			setChangedInner(true);
		}
	}
	return this;
}

Canvas* Canvas::setChangedBorder(bool changedBorder) {
	this->changedBorder = changedBorder;
	return this;
}

Canvas* Canvas::setScreenTop(int screenTop) {
	this->screenTop = screenTop;
	return this;
}

Canvas* Canvas::setScreenLeft(int screenLeft) {
	this->screenLeft = screenLeft;
	return this;
}

Canvas* Canvas::getRootCanvas() {
	Canvas* parent = getParent();
	Canvas* root = parent ? parent->getRootCanvas() : this;
	return root;
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

int Canvas::getColorPushed() {
	return colorPushed;
}

int Canvas::getBorderSize() {
	return borderSize;
}

bool Canvas::getPushed() {
	return pushed;
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

bool Canvas::getChangedBorder() {
	return changedBorder;
}

bool Canvas::getChangedInner() {
	return changedInner;
}

bool Canvas::getLineBreak() {
	return lineBreak;
}

bool Canvas::getEnabled() {
	return enabled;
}

int Canvas::getScreenTop() {
	return screenTop;
}

int Canvas::getScreenLeft() {
	return screenLeft;
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

int Canvas::calcFirstSelected() {
	for (int i = 0; i < CANVAS_INSTANCES; i++) {
		Canvas* canvas = getInstance(i);
		if (canvas && canvas->getSelected()) {
			return i;
		}
	}
	return -1;
}

int Canvas::calcLastSelected() {
	for (int i = CANVAS_INSTANCES - 1; i >= 0; i--) {
		Canvas* canvas = getInstance(i);
		if (canvas && canvas->getSelected()) {
			return i;
		}
	}
	return CANVAS_INSTANCES;
}

int Canvas::unselectAll() {
	int ret = 0;
	for (int i = 0; i < CANVAS_INSTANCES; i++) {
		Canvas* canvas = getInstance(i);
		if (canvas) {
			canvas->setSelected(false);
			ret++;
		}
	}
	return ret;
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

bool Canvas::isInside(EventPoint eventPoint) {
    int top = getScreenTop();
    int left = getScreenLeft();
    int fullwidth = calcWidthFull();
    int fullheight = calcHeightFull();
    int right = left + fullwidth;
    int bottom = top + fullheight;
    return eventPoint.left >= left && eventPoint.left <= right && eventPoint.top >= top && eventPoint.top <= bottom;
}

int Canvas::tickChildren() {
	int ret = 0;
	for (int i = 0; i < CANVAS_INSTANCES; i++) {
		Canvas* child = getInstance(i);
		Canvas* parent = child ? child->getParent() : 0;
		if (child && parent && parent->getId() == getId()) {
			ret += child->tick();
		}
	}
	return ret;
}

// protected:

Canvas* Canvas::clear() {
	Canvas* root = getRootCanvas();
	int top = getScreenTop() - getBorderSize();
	int left = getScreenLeft() - getBorderSize();
	int width = calcWidthFull();
	int height = calcWidthFull();
	int color = root->getColor();
	Painter::fillrect(top, left, width, height, color, color);
	setChangedBorder(true);
	setChangedInner(true);
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

Canvas* Canvas::setEnabled(bool enabled) {
	this->enabled = enabled;
	return this;
}

Canvas* Canvas::setChangedInner(bool changedInner) {
	this->changedInner = changedInner;
	return this;
}

bool Canvas::drawInner(int offsetTop, int offsetLeft) {
	if (getChangedInner()) {
		int screenTop = calcTopRelativeToParent() + getBorderSize() + offsetTop;
		int screenLeft = calcLeftRelativeToParent() + getBorderSize() + offsetLeft;
		Painter::fillrect(
			screenTop,
			screenLeft,
			getWidth(),
			getHeight(),
			calcColorCurrent()
		);
		setScreenTop(screenTop);
		setScreenLeft(screenLeft);
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
