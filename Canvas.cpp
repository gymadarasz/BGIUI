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

Color Canvas::getClearColor() {
	Canvas* behind = parent ? parent : this;
	Color color = behind->box.color;
	if (behind->selected) color = behind->box.colorSelected;
	if (behind->pushed) color = behind->box.colorPushed;
	if (behind->disabled) color = behind->box.colorDisabled;
	return color;
}

bool Canvas::select(bool sel) {
	if (!inactive && !disabled && !hidden) {
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->selected) {
				if (canvases[i]->selected) {
					canvases[i]->draw();
				}
				canvases[i]->selected = false;
			}
		}

		selected = sel;
		draw();
	}
	return selected;
}

bool Canvas::push(bool psh) {
	if (!inactive && !disabled && !hidden) {
		pushed = psh;
		draw();
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
    int top = realTop;
    int left = realLeft;
    int fullwidth = fullWidth;
    int fullheight = fullHeight;
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

	disabled = false;
	selected = false;
	pushed = false;
	hidden = false;
	inactive = false;

	onTickHandler = 0;
	onClickHandler = 0;
	onDblClickHandler = 0;
	onMouseMoveHandler = 0;
	onMouseDragHandler = 0;
	onMouseOverHandler = 0;
	onMouseLeaveHandler = 0;
	onMouseDownHandler = 0;
	onMouseUpHandler = 0;

	realTop = box.top;
	realLeft = box.left;
	fullWidth = box.width + (border.size + margin.horizontal)*2;
	fullHeight = box.height + (border.size + padding.vertical)*2;

	if (parent) {
		parent->inactive = true;
		if (parent->box.width < fullWidth) {
			parent->box.width = fullWidth;
		}
	}

	latestBorderColor = NOCOLOR;
	latestInnerColor = NOCOLOR;
	latestTextColor = NOCOLOR;
}

Canvas::~Canvas() {}

void Canvas::setSize(int width, int height) {
	if (box.width != width || box.height != height) {
		box.width = width;
		box.height = height;
	}
}

void Canvas::setSize(int width) {
	if (box.width != width) {
		box.width = width;
	}
}

void Canvas::setColor(int color, int colorSelected, int colorDisabled, int colorPushed) {
	if (box.color != color) {
		box.color = color;
	}
	if (colorSelected != GUI_UNDEFINED) {
		setColorSelected(colorSelected);
	}
	if (colorDisabled != GUI_UNDEFINED) {
		setColorDisabled(colorSelected);
	}
	if (colorPushed != GUI_UNDEFINED) {
		setColorPushed(colorSelected);
	}
}

void Canvas::setColorSelected(int colorSelected) {
	if (box.colorSelected != colorSelected) {
		box.colorSelected = colorSelected;
	}
}

void Canvas::setColorDisabled(int colorDisabled) {
	if (box.colorDisabled != colorDisabled) {
		box.colorDisabled = colorDisabled;
	}
}

void Canvas::setColorPushed(int colorPushed) {
	if (box.colorPushed != colorPushed) {
		box.colorPushed = colorPushed;
	}
}


void Canvas::setText(const char* str, int size) {
	setText((char*)str, size);
}

void Canvas::setText(char* str, int size) {
	bool redraw = false;
	int i = 0;
	while(str[i]) {
		if (text.label[i] != str[i]) {
			redraw = true;
		}
		text.label[i] = str[i];
		i++;
	}
	text.label[i] = 0;

	if (redraw) {
		if (box.fitToText || box.width < Painter::getTextWidth(text.label, text.size) + padding.horizontal*2) {
			box.width = Painter::getTextWidth(text.label, text.size) + padding.horizontal*2;
			fullWidth = box.width + (border.size + margin.horizontal)*2;
			if (parent && parent->box.width < fullWidth) {
				parent->box.width = fullWidth;
			}
		}
		if (box.fitToText || box.height < Painter::getTextHeight(text.label, text.size) + padding.vertical*2) {
			box.height = Painter::getTextHeight(text.label, text.size) + padding.vertical*2;
			fullHeight = box.height + (border.size + padding.vertical)*2;
		}
	}

	if (size != GUI_UNDEFINED) {
		setTextSize(size);
	}
}

void Canvas::setTextColor(int color, int colorSelected, int colorDisabled, int colorPushed) {
	if (text.color != color) {
		text.color = color;
	}
	if (colorSelected != GUI_UNDEFINED) {
		setTextColorSelected(colorSelected);
	}
	if (colorDisabled != GUI_UNDEFINED) {
		setTextColorDisabled(colorSelected);
	}
	if (colorPushed != GUI_UNDEFINED) {
		setTextColorPushed(colorSelected);
	}
}

void Canvas::setTextColorSelected(int colorSelected) {
	if (text.colorSelected != colorSelected) {
		text.colorSelected = colorSelected;
	}
}

void Canvas::setTextColorDisabled(int colorDisabled) {
	if (text.colorDisabled != colorDisabled) {
		text.colorDisabled = colorDisabled;
	}
}

void Canvas::setTextColorPushed(int colorPushed) {
	if (text.colorPushed != colorPushed) {
		text.colorPushed = colorPushed;
	}
}

void Canvas::setTextSize(int size) {
	if (text.size != size) {
		text.size = size;
	}
}

void Canvas::setBreakLine(bool br) {
	if (box.breakLine != br) {
		box.breakLine = br;
	}
}

void Canvas::setPosition(int top, int left) {
	if (box.top != top || box.left != left) {
		box.top = top;
		box.left = left;
		box.positioned = true;
	}
}


void Canvas::setMargin(int horizontal, int vertical) {
	if (margin.horizontal != horizontal || margin.vertical != vertical) {
		margin.horizontal = horizontal;
		margin.vertical = vertical;
	}
}

void Canvas::setMarginVertical(int vertical) {
	if (margin.vertical != vertical) {
		margin.vertical = vertical;
	}
}

void Canvas::setPadding(int horizontal, int vertical) {
	if (padding.horizontal != horizontal || padding.vertical != vertical) {
		padding.horizontal = horizontal;
		padding.vertical = vertical;
	}
}

void Canvas::setPaddingVertical(int vertical) {
	if (padding.vertical != vertical) {
		padding.vertical = vertical;
	}
}

void Canvas::setBorder(int size, int color) {
	if (border.size != size) {
		border.size = size;
	}
	if (border.color != color) {
		border.color = color;
	}
}

void Canvas::setBorderSize(int size) {
	if (border.size != size) {
		border.size = size;
	}
}

void Canvas::setBorderColor(int color, int colorSelected, int colorDisabled, int colorPushed) {
	if (border.color != color) {
		border.color = color;
	}
	if (colorSelected != GUI_UNDEFINED) {
		setBorderColorSelected(colorSelected);
	}
	if (colorDisabled != GUI_UNDEFINED) {
		setBorderColorDisabled(colorSelected);
	}
	if (colorPushed != GUI_UNDEFINED) {
		setBorderColorPushed(colorSelected);
	}
}

void Canvas::setBorderColorSelected(int colorSelected) {
	if (border.colorSelected != colorSelected) {
		border.colorSelected = colorSelected;
	}
}

void Canvas::setBorderColorDisabled(int colorDisabled) {
	if (border.colorDisabled != colorDisabled) {
		border.colorDisabled = colorDisabled;
	}
}

void Canvas::setBorderColorPushed(int colorPushed) {
	if (border.colorPushed != colorPushed) {
		border.colorPushed = colorPushed;
	}
}

void Canvas::enable() {
	if (disabled) {
		disabled = false;
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
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
				canvases[i]->disable();
			}
		}
	}
}

void Canvas::show() {
	if (hidden) {
		hidden = false;
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
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
				canvases[i]->hide();
			}
		}
	}
}

void Canvas::destroy() {
	int i = id;
	for (; i<CANVASES; i++) {
		canvases[i] = canvases[i+1];
		canvases[i]->id--;
	}
}

void Canvas::calc() {

	// calculate size
	fullWidth = box.width + (border.size + margin.horizontal)*2;
	fullHeight = box.height + (border.size + margin.vertical)*2;

	// calculate real (on screen) position
	int parentCursorRealTop = 0;
	int parentCursorRealLeft = 0;
	if (!box.positioned && parent) {
		parentCursorRealTop = parent->realTop;
		parentCursorRealLeft = parent->realLeft;

		if (box.breakLine || parent->cursor.left + fullWidth > parent->box.width) {
			parent->cursorBreakLine(fullHeight);
		}

		parentCursorRealTop += parent->cursor.top;
		parentCursorRealLeft += parent->cursor.left;

		parent->cursorStep(fullWidth, fullHeight);
	}
	realTop = parentCursorRealTop + box.top + margin.vertical + border.size;
	realLeft = parentCursorRealLeft + box.left + margin.horizontal + border.size;

	// calc children
	cursorReset();
	for (int i=0; i<CANVASES; i++) {
		if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
			canvases[i]->calc();
		}
	}


	// height fit to cursor (maybe children push down the size?)
	if (cursor.top + cursor.lnHeight > box.height) {
		box.height = cursor.top + cursor.lnHeight;
		fullHeight = box.height + (border.size + margin.vertical)*2;
	}


}

void Canvas::draw() {

	int borderColor = border.color;
	int innerColor = box.color;
	int textColor = text.color;

	if (selected) {
		borderColor = border.colorSelected;
		innerColor = box.colorSelected;
		textColor = text.colorSelected;
	}

	if (pushed) {
		borderColor = border.colorPushed;
		innerColor = box.colorPushed;
		textColor = text.colorPushed;
	}

	if (disabled) {
		borderColor = border.colorDisabled;
		innerColor = box.colorDisabled;
		textColor = text.colorDisabled;
	}

	if (latestBorderColor != borderColor) {
		// draw border
		Painter::rect(
				realTop + margin.vertical + border.size,
				realLeft + margin.horizontal + border.size,
				box.width,
				box.height,
				borderColor,
				border.size);
		latestBorderColor = borderColor;
	}

	bool redrawText = false;
	if (latestInnerColor != innerColor) {
		// draw inner box
		Painter::fillrect(
				realTop + margin.vertical + border.size,
				realLeft + margin.horizontal + border.size,
				box.width,
				box.height,
				innerColor);
		redrawText = true;
		latestInnerColor = innerColor;
	}

	if (latestTextColor != textColor || redrawText) {
		// draw text
		Painter::text(
				realTop + margin.vertical + border.size + padding.vertical,
				realLeft + margin.horizontal + border.size + padding.horizontal,
				text.label,
				textColor,
				innerColor,
				text.size);
		latestTextColor = textColor;
	}

	// draw children
	for (int i=0; i<CANVASES; i++) {
		if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
			canvases[i]->draw();
		}
	}

}

//--events

void Canvas::tick() {

	onTick();

    if (disabled || hidden) {
        return ;
    }

    int top = realTop;
    int left = realLeft;

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

