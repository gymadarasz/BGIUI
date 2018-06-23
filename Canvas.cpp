/*
 * Canvas.cpp
 *
 *  Created on: Jun 21, 2018
 *      Author: Gyula
 */

#include "Canvas.h"

namespace gui {

Canvas* Canvas::canvases[CANVASES] = {0};

void Canvas::cursorReset() {
	cursor.top = 0;
	cursor.left = 0;
	cursor.lnHeight = 0;
}

bool Canvas::cursorCheckSpace(int width, int height) {
	if (cursor.left + width > box.width) {
		return false;
	}
	return true;
}

void Canvas::cursorBreakLine(int lnHeight) {
	cursor.left = 0;
	cursor.top += cursor.lnHeight;
	cursor.lnHeight = lnHeight;
}

void Canvas::cursorStep(int width, int height) {
	cursor.left += width;

	if (height > cursor.lnHeight) {
		cursor.lnHeight = height;
	}


}

void Canvas::calc(int offsetTop, int offsetLeft) {

	calculatedBorderColor = border.color;
	calculatedBoxColor = box.color;
	calculatedTextColor = text.color;
	if (selected) {
		calculatedBorderColor = border.colorSelected;
		calculatedBoxColor = box.colorSelected;
		calculatedTextColor = text.colorSelected;
	}
	if (pushed) {
		calculatedBorderColor = border.colorPushed;
		calculatedBoxColor = box.colorPushed;
		calculatedTextColor = text.colorPushed;
	}
	if (disabled) {
		calculatedBorderColor = border.colorDisabled;
		calculatedBoxColor = box.colorDisabled;
		calculatedTextColor = text.colorDisabled;
	}
	if (hidden) {
		// TODO: clear only first time, next use NOCOLOR!
		calculatedBorderColor = calculatedBoxColor = calculatedTextColor = getClearColor();
	}


	int innerWidth = box.width;
	int innerHeight = box.height;

	if (adjust.toTextSize) {
		innerWidth += Painter::getTextWidth(text.label, text.size) + padding.horizontal*2;
		innerHeight += Painter::getTextHeight(text.label, text.size) + padding.vertical*2;
	}

	int innerTop = box.top + margin.vertical + border.size;
	int innerLeft = box.left + margin.horizontal + border.size;
	int outerWidth = innerWidth + (margin.horizontal + border.size)*2;
	int outerHeight = innerHeight + (margin.vertical + border.size)*2;

	if (box.breakLine) {
		parent->cursorBreakLine(outerHeight);
	}

	if (adjust.toParentCursor && parent) {

		if (!parent->cursorCheckSpace(outerWidth, outerHeight)) {
			parent->cursorBreakLine(outerHeight);
		}
		innerTop += parent->cursor.top;
		innerLeft += parent->cursor.left;
		parent->cursorStep(outerWidth, outerHeight);
	}

	// apply the given extra offset argumanets
	innerTop += offsetTop;
	innerLeft += offsetLeft;


	calculatedTop = innerTop;
	calculatedLeft = innerLeft;
	calculatedWidth = innerWidth;
	calculatedHeight = innerHeight;

	// paint text (+ padding size)
	calculatedTextTop = innerTop + padding.vertical;
	calculatedTextLeft = innerLeft + padding.horizontal;

	// paint children
	cursorReset();
	for (int i = 0; i < CANVASES; i++) {
		if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
			canvases[i]->calc(offsetTop + innerTop, offsetLeft + innerLeft);
		}
	}

}

void Canvas::draw() {

	if (paintInner) {
		Painter::fillrect(calculatedTop, calculatedLeft, calculatedWidth, calculatedHeight, calculatedBoxColor);
		Painter::text(calculatedTextTop, calculatedTextLeft, text.label, calculatedTextColor, calculatedBoxColor, text.size);
		paintInner = false;
	}

	if (paintBorder) {
		Painter::rect(calculatedTop, calculatedLeft, calculatedWidth, calculatedHeight, calculatedBorderColor, border.size);
		paintBorder = false;
	}

}

Color Canvas::getClearColor() {
	Canvas* behind = parent ? parent : this;
	Color color = behind->box.color;
	if (behind->selected) color = behind->box.colorSelected;
	if (behind->pushed) color = behind->box.colorPushed;
	if (behind->disabled) color = behind->box.colorDisabled;
	return color;
}


bool Canvas::select(bool sel) {
	if (!disabled || !hidden) {
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->selected) {
				canvases[i]->selected = false;
				canvases[i]->paintBorder = true;
			}
		}
		selected = sel;
		paintBorder = true;
	}
	return selected;
}

bool Canvas::push(bool psh) {
	if (!disabled || !hidden) {
		pushed = psh;
		paintInner = true;
	}
	return pushed;
}

void Canvas::selectNext() {
	for (int i = id; i<CANVASES; i++) {
		if (canvases[i] && canvases[i]->select()) {
			break;
		}
	}
}

void Canvas::selectPrev() {
	for (int i = CANVASES+1; i >= 0; i++) {
		if (canvases[i] && canvases[i]->select()) {
			break;
		}
	}
}

bool Canvas::isInside(EventPoint eventPoint) {
    int top = calculatedTop;
    int left = calculatedLeft;
    int fullwidth = calculatedWidth;
    int fullheight = calculatedHeight;
    int right = left + fullwidth;
    int bottom = top + fullheight;
    return eventPoint.left >= left && eventPoint.left <= right && eventPoint.top >= top && eventPoint.top <= bottom;
}


// public:

Canvas::Canvas(Canvas* parent) {
	this->parent = parent;
	for (id=0; id<CANVASES; id++) {
		if (!canvases[id]) {
			canvases[id] = this;
			break;
		}
	}

	paintBorder = true;
	paintInner = true;
	disabled = false;
	selected = false;
	pushed = false;
	hidden = false;

	onTickHandler = 0;
	onClickHandler = 0;
	onDblClickHandler = 0;
	onMouseMoveHandler = 0;
	onMouseDragHandler = 0;
	onMouseOverHandler = 0;
	onMouseLeaveHandler = 0;
	onMouseDownHandler = 0;
	onMouseUpHandler = 0;

	calculatedTop = 0;
	calculatedLeft = 0;
	calculatedWidth = 0;
	calculatedHeight = 0;
	calculatedTextTop = 0;
	calculatedTextLeft = 0;
	calculatedBorderColor = NOCOLOR;
	calculatedBoxColor = NOCOLOR;
	calculatedTextColor = NOCOLOR;
}

Canvas::~Canvas() {}


void Canvas::setSize(int width, int height) {
	if (box.width != width || box.height != height) {
		box.width = width;
		box.height = height;
		adjust.toTextSize = false;
		parent->paintBorder = true;
		parent->paintInner = true;
	}
}

void Canvas::setSize(int width) {
	if (box.width != width) {
		box.width = width;
		adjust.toTextSize = false;
		parent->paintBorder = true;
		parent->paintInner = true;
	}
}

void Canvas::setColor(int color) {
	if (box.color != color) {
		box.color = color;
		parent->paintInner = true;
	}
}

void Canvas::setText(const char* str) {
	setText((char*)str);
}

void Canvas::setText(char* str) {
	int i = 0;
	while(str[i]) {
		if (text.label[i] != str[i]) {
			parent->paintInner = true;
		}
		text.label[i] = str[i];
		i++;
	}
	text.label[i] = 0;
}

void Canvas::setTextColor(int color) {
	if (text.color != color) {
		text.color = color;
		parent->paintInner = true;
	}
}

void Canvas::setTextSize(int size) {
	if (text.size != size) {
		text.size = size;
		parent->paintBorder = true;
		parent->paintInner = true;
	}
}

void Canvas::setBreakLine(bool br) {
	if (box.breakLine != br) {
		box.breakLine = br;
		parent->paintBorder = true;
		parent->paintInner = true;
	}
}

void Canvas::setPosition(int top, int left) {
	if (box.top != top || box.left != left) {
		box.top = top;
		box.left = left;
		adjust.toParentCursor = false;
		parent->paintBorder = true;
		parent->paintInner = true;
	}
}

void Canvas::enable() {
	if (disabled) {
		disabled = false;
		paintInner = true;
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
				canvases[i]->enable();
			}
		}
	}
}

void Canvas::disable() {
	if (!disabled) {
		disabled = true;
		paintInner = true;
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
				canvases[i]->disable();
			}
		}
	}
}

void Canvas::setMargin(int horizontal, int vertical) {
	if (margin.horizontal != horizontal || margin.vertical != vertical) {
		margin.horizontal = horizontal;
		margin.vertical = vertical;
		parent->paintBorder = true;
		parent->paintInner = true;

	}
}

void Canvas::setPadding(int horizontal, int vertical) {
	if (padding.horizontal != horizontal || padding.vertical != vertical) {
		padding.horizontal = horizontal;
		padding.vertical = vertical;
		parent->paintBorder = true;
		parent->paintInner = true;

	}
}

void Canvas::setBorder(int size, int color) {
	if (border.size != size || border.color != color) {
		border.size = size;
		border.color = color;
		paintBorder = true;
	}
}

void Canvas::setBorderSize(int size) {
	if (border.size != size) {
		border.size = size;
		paintBorder = true;
	}
}

void Canvas::setBorderColor(int color) {
	if (border.color != color) {
		border.color = color;
		paintBorder = true;
	}
}

void Canvas::setToCursor(bool toParentCursor) {
	if (adjust.toParentCursor != toParentCursor) {
		adjust.toParentCursor = toParentCursor;
		parent->paintInner = true;
	}
}

void Canvas::show() {
	if (hidden) {
		hidden = false;
		paintBorder = true;
		paintInner = true;
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
				canvases[i]->show();
			}
		}
	}
}

void Canvas::hide() {
	if (!hidden) {
		hidden = true;
		paintBorder = true;
		paintInner = true;
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
				canvases[i]->hide();
			}
		}
	}
}

void Canvas::destroy() {
	canvases[id] = 0;
	paintInner = true;
}

//--events

void Canvas::tick() {

	onTick();

    if (disabled || hidden) {
        return ;
    }

    int top = calculatedTop;
    int left = calculatedLeft;

    // mouse down?
    if (Mouse::events.mouseDown.happend && isInside(Mouse::events.mouseDown.position)) {
        onMouseDown(Mouse::events.mouseDown.position.left-left, Mouse::events.mouseDown.position.top-top);
    }

    // click?
    if (Mouse::events.click.happend && isInside(Mouse::events.click.position)) {
        onClick(Mouse::events.click.position.left-left, Mouse::events.click.position.top-top);
    }

    // dblclick?
    if (Mouse::events.dblClick.happend && isInside(Mouse::events.dblClick.position)) {
        onDblClick(Mouse::events.dblClick.position.left-left, Mouse::events.dblClick.position.top-top);
    }

    // mouse move, over, leave?
    if (Mouse::events.mouseMove.happend) {
        if (isInside(Mouse::events.mouseMove.current) && isInside(Mouse::events.mouseMove.previous)) {
            onMouseMove(
                Mouse::events.mouseMove.current.left-left, Mouse::events.mouseMove.current.top-top,
                Mouse::events.mouseMove.previous.left-left, Mouse::events.mouseMove.previous.top-top
            );
        } else if (isInside(Mouse::events.mouseMove.current)) {
            onMouseOver(Mouse::events.mouseMove.current.left-left, Mouse::events.mouseMove.current.top-top);
        } else if (isInside(Mouse::events.mouseMove.previous)) {
            onMouseLeave(Mouse::events.mouseMove.previous.left-left, Mouse::events.mouseMove.previous.top-top);
        }
    }

    if (Mouse::events.mouseDrag.happend) {
        if (isInside(Mouse::events.mouseDrag.current) && isInside(Mouse::events.mouseDrag.previous)) {
            onMouseDrag(
                Mouse::events.mouseDrag.current.left-left, Mouse::events.mouseDrag.current.top-top,
                Mouse::events.mouseDrag.previous.left-left, Mouse::events.mouseDrag.previous.top-top
            );
        }
    }

    // mouse up?
    if (Mouse::events.mouseUp.happend && isInside(Mouse::events.mouseUp.position)) {
        onMouseUp(Mouse::events.mouseUp.position.left-left, Mouse::events.mouseUp.position.top-top);
    }
}


void Canvas::onTick() {
    if (onTickHandler) {
        onTickHandler(this);
    }
}

void Canvas::onClick(int mouseLeft, int mouseTop) {
	if (onClickHandler) {
		onClickHandler(this, mouseLeft, mouseTop);
	}
}

void Canvas::onDblClick(int mouseLeft, int mouseTop) {
	if (onDblClickHandler) {
		onDblClickHandler(this, mouseLeft, mouseTop);
	}
}

void Canvas::onMouseMove(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent) {
	if (onMouseMoveHandler) {
		onMouseMoveHandler(this, mouseLeftFrom, mouseTopFrom, mouseLeftCurrent, mouseTopCurrent);
	}
}

void Canvas::onMouseOver(int mouseLeft, int mouseTop) {
	select();

	if (onMouseOverHandler) {
		onMouseOverHandler(this, mouseLeft, mouseTop);
	}
}

void Canvas::onMouseLeave(int mouseLeft, int mouseTop) {
	select(false);

	if (onMouseLeaveHandler) {
		onMouseLeaveHandler(this, mouseLeft, mouseTop);
	}
}

void Canvas::onMouseDrag(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent) {
	if (onMouseDragHandler) {
		onMouseDragHandler(this, mouseLeftFrom, mouseTopFrom, mouseLeftCurrent, mouseTopCurrent);
	}
}

void Canvas::onMouseDown(int mouseLeft, int mouseTop) {
	push();

	if (onMouseDownHandler) {
		onMouseDownHandler(this, mouseLeft, mouseTop);
	}
}

void Canvas::onMouseUp(int mouseLeft, int mouseTop) {
	push(false);

	if (onMouseUpHandler) {
		onMouseUpHandler(this, mouseLeft, mouseTop);
	}
}


} /* namespace gui */

