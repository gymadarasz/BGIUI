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

//bool Canvas::cursorCheckSpace(int parentInnerWidth, int nextChildOuterWidth) {
//	if (cursor.left + nextChildOuterWidth > parentInnerWidth) {
//		return true;
//	}
//	return false;
//}

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
	calculatedInnerColor = box.color;
	calculatedTextColor = text.color;
	if (selected) {
		calculatedBorderColor = border.colorSelected;
		calculatedInnerColor = box.colorSelected;
		calculatedTextColor = text.colorSelected;
	}
	if (pushed) {
		calculatedBorderColor = border.colorPushed;
		calculatedInnerColor = box.colorPushed;
		calculatedTextColor = text.colorPushed;
	}
	if (disabled) {
		calculatedBorderColor = border.colorDisabled;
		calculatedInnerColor = box.colorDisabled;
		calculatedTextColor = text.colorDisabled;
	}
	if (hidden) {
		// TODO: clear only first time, next use NOCOLOR!
		calculatedBorderColor = calculatedInnerColor = calculatedTextColor = getClearColor();
	}


	int innerWidth = box.width;
	int innerHeight = box.height;

	if (box.adjustSize == ADJUST_SIZE_TO_TEXT) {
		innerWidth += Painter::getTextWidth(text.label, text.size) + padding.horizontal*2;
		innerHeight += Painter::getTextHeight(text.label, text.size) + padding.vertical*2;
	}

	int innerTop = box.top + margin.vertical + border.size;
	int innerLeft = box.left + margin.horizontal + border.size;

	if (parent) {
		if(box.adjustSize == ADJUST_SIZE_TO_PARENT_WIDTH) {
			innerWidth = parent->calculatedInnerWidth - (margin.horizontal + border.size)*2;
//			innerLeft = 0;
//			if (box.adjustSize == ADJUST_SIZE_TO_PARENT_HEIGHT) {
//				innerHeight = parent->calculatedInnerHeight - (margin.horizontal - border.size)*2;
//				innerTop = 0;
//			}
		}
	}

	int outerWidth = innerWidth + (margin.horizontal + border.size)*2;
	int outerHeight = innerHeight + (margin.vertical + border.size)*2;


	if (parent && box.adjustSize == ADJUST_POSITION_TO_PARENT_CURSOR) {

//		if (box.breakLine) {
//			parent->cursorBreakLine(outerHeight);
//		}

		// have to break line OR not enough space in parent?
		if (box.breakLine || parent->cursor.left + outerWidth > parent->calculatedInnerWidth) {
			parent->cursorBreakLine(outerHeight);
		}

		innerTop += parent->cursor.top;
		innerLeft += parent->cursor.left;
		parent->cursorStep(outerWidth, outerHeight);

		// extending parent height to cursor size
		parent->calculatedInnerHeight = parent->calculatedInnerHeight >= parent->cursor.top + parent->cursor.lnHeight ?
				parent->calculatedInnerHeight :
				parent->cursor.top + parent->cursor.lnHeight;

	}

	// apply the given extra offset argumanets
	innerTop += offsetTop;
	innerLeft += offsetLeft;


	calculatedInnerTop = innerTop;
	calculatedInnerLeft = innerLeft;
	calculatedInnerWidth = innerWidth;
	calculatedInnerHeight = innerHeight;

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
		Painter::fillrect(calculatedInnerTop, calculatedInnerLeft, calculatedInnerWidth, calculatedInnerHeight, calculatedInnerColor);
		Painter::text(calculatedTextTop, calculatedTextLeft, text.label, calculatedTextColor, calculatedInnerColor, text.size);
		paintInner = false;
	}

	if (paintBorder) {
		Painter::rect(calculatedInnerTop, calculatedInnerLeft, calculatedInnerWidth, calculatedInnerHeight, calculatedBorderColor, border.size);
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
	if (!disabled && !hidden) {
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

int Canvas::getSelectedId() {
	for (int i=0; i<CANVASES; i++) {
		if (canvases[i] && canvases[i]->selected) {
			return i;
		}
	}
	return -1;
}

void Canvas::selectNext() {
	int sid = getSelectedId();
	int i = sid + 1 < CANVASES ? sid + 1 : 0;
	for (; i < CANVASES; i++) {
		if (canvases[i] && canvases[i]->select()) {
			break;
		}
	}
}

void Canvas::selectPrev() {
	int sid = getSelectedId();
	int i = sid - 1 >= 0 ? sid - 1 : CANVASES - 1;
	for (; i >= 0; i--) {
		if (canvases[i] && canvases[i]->select()) {
			break;
		}
	}
}

void Canvas::clickSelected() {
	for (int i = 0; i<CANVASES; i++) {
		if (canvases[i] && canvases[i]->selected) {
			canvases[i]->onMouseDown(0, 0);
			canvases[i]->onClick(0, 0);
			canvases[i]->onMouseUp(0, 0);
			break;
		}
	}
}

bool Canvas::isInside(EventPoint eventPoint) {
    int top = calculatedInnerTop;
    int left = calculatedInnerLeft;
    int fullwidth = calculatedInnerWidth;
    int fullheight = calculatedInnerHeight;
    int right = left + fullwidth;
    int bottom = top + fullheight;
    return eventPoint.left >= left && eventPoint.left <= right && eventPoint.top >= top && eventPoint.top <= bottom;
}

bool Canvas::isChanged() {
	if (paintBorder || paintInner) {
		return true;
	}
	for (int i=0; i<CANVASES; i++) {
		if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id && canvases[i]->isChanged()) {
			return true;
		}
	}
	return false;
}


// public:

Canvas::Canvas(Canvas* parent) {
	this->parent = parent;
	parent ? parent->disabled = true : 0;

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

	calculatedInnerTop = 0;
	calculatedInnerLeft = 0;
	calculatedInnerWidth = 0;
	calculatedInnerHeight = 0;
	calculatedTextTop = 0;
	calculatedTextLeft = 0;
	calculatedBorderColor = NOCOLOR;
	calculatedInnerColor = NOCOLOR;
	calculatedTextColor = NOCOLOR;
}

void Canvas::setSize(int width, int height) {
	if (box.width != width || box.height != height) {
		box.width = width;
		box.height = height;
//		adjust.toTextSize = false;
		paintBorder = true;
		paintInner = true;
	}
}

void Canvas::setSize(int width) {
	if (box.width != width) {
		box.width = width;
//		adjust.toTextSize = false;
		paintBorder = true;
		paintInner = true;
	}
}

void Canvas::setColor(int color) {
	if (box.color != color) {
		calculatedInnerColor = box.color = color;
		paintInner = true;
	}
}

void Canvas::setText(const char* str) {
	setText((char*)str);
}

void Canvas::setText(char* str) {
	int i = 0;
	while(str[i]) {
		if (text.label[i] != str[i]) {
			paintInner = true;
		}
		text.label[i] = str[i];
		i++;
	}
	text.label[i] = 0;
}

void Canvas::setTextColor(int color) {
	if (text.color != color) {
		text.color = color;
		paintInner = true;
	}
}

void Canvas::setTextSize(int size) {
	if (text.size != size) {
		text.size = size;
		paintBorder = true;
		paintInner = true;
	}
}

void Canvas::setBreakLine(bool br) {
	if (box.breakLine != br) {
		box.breakLine = br;
		paintBorder = true;
		paintInner = true;
	}
}

void Canvas::setPosition(int top, int left) {
	if (box.top != top || box.left != left) {
		box.top = top;
		box.left = left;
//		adjust.toParentCursor = false;
		paintBorder = true;
		paintInner = true;
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
		paintBorder = true;
		paintInner = true;

	}
}

void Canvas::setMarginVertical(int vertical) {
	if (margin.vertical != vertical) {
		margin.vertical = vertical;
		paintBorder = true;
		paintInner = true;
	}
}

void Canvas::setPadding(int horizontal, int vertical) {
	if (padding.horizontal != horizontal || padding.vertical != vertical) {
		padding.horizontal = horizontal;
		padding.vertical = vertical;
		paintBorder = true;
		paintInner = true;

	}
}

void Canvas::setPaddingVertical(int vertical) {
	if (padding.vertical != vertical) {
		padding.vertical = vertical;
		paintBorder = true;
		paintInner = true;
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

//void Canvas::setToCursor(bool toParentCursor) {
//	if (adjust.toParentCursor != toParentCursor) {
//		adjust.toParentCursor = toParentCursor;
//		paintInner = true;
//	}
//}
//
//void Canvas::setToInnerCursor(bool toInnerCursor) {
//	if (adjust.toInnerCursor != toInnerCursor) {
//		adjust.toInnerCursor = toInnerCursor;
//		paintInner = true;
//	}
//}

void Canvas::setAdjustSize(int adjustSize) {
	if (box.adjustSize != adjustSize) {
		box.adjustSize = adjustSize;
		paintBorder = true;
		paintInner = true;
	}
}

void Canvas::setAdjustPosition(int adjustPosition) {
	if (box.adjustPosition != adjustPosition) {
		box.adjustPosition = adjustPosition;
		paintBorder = true;
		paintInner = true;
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

    int top = calculatedInnerTop;
    int left = calculatedInnerLeft;

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

