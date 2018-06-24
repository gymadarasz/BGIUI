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

#define STRCPY(TO, FROM, V) { \
	int V = 0; \
	while (FROM[V]) {\
		TO[V] = FROM[V];\
		V++;\
	} \
	TO[V] = 0; \
}

//void Canvas::calc(int offsetTop, int offsetLeft) {
//	current.border.color = border.color;
//	current.border.size = border.size;
//	current.box.color = box.color;
//	current.box.height = box.height;
//	current.box.left = box.left;
//	current.box.top = box.top;
//	current.box.width = box.width;
//	current.margin.horizontal = margin.horizontal;
//	current.margin.vertical = margin.vertical;
//	current.padding.horizontal = padding.horizontal;
//	current.padding.vertical = padding.vertical;
//	current.text.color = text.color;
//	STRCPY(current.text.label, text.label, i);
//	current.text.size = text.size;
//}

//void Canvas::calc(int offsetTop, int offsetLeft) {
//
//	calculatedBorderColor = border.color;
//	calculatedInnerColor = box.color;
//	calculatedTextColor = text.color;
//	if (selected) {
//		calculatedBorderColor = border.colorSelected;
//		calculatedInnerColor = box.colorSelected;
//		calculatedTextColor = text.colorSelected;
//	}
//	if (pushed) {
//		calculatedBorderColor = border.colorPushed;
//		calculatedInnerColor = box.colorPushed;
//		calculatedTextColor = text.colorPushed;
//	}
//	if (disabled) {
//		calculatedBorderColor = border.colorDisabled;
//		calculatedInnerColor = box.colorDisabled;
//		calculatedTextColor = text.colorDisabled;
//	}
//	if (hidden) {
//		// TODO: clear only first time, next use NOCOLOR!
//		calculatedBorderColor = calculatedInnerColor = calculatedTextColor = getClearColor();
//	}
//
//
//	int innerWidth = box.width;
//	int innerHeight = box.height;
//
//	if (box.adjustSize == ADJUST_SIZE_TO_TEXT) {
//		innerWidth += Painter::getTextWidth(text.label, text.size) + padding.horizontal*2;
//		innerHeight += Painter::getTextHeight(text.label, text.size) + padding.vertical*2;
//	}
//
//	int innerTop = box.top + margin.vertical + border.size;
//	int innerLeft = box.left + margin.horizontal + border.size;
//
//	if (parent) {
//		if(box.adjustSize == ADJUST_SIZE_TO_PARENT_WIDTH) {
//			innerWidth = parent->calculatedInnerWidth - (margin.horizontal + border.size)*2;
//			innerLeft = margin.horizontal + border.size;
////			if (box.adjustSize == ADJUST_SIZE_TO_PARENT_HEIGHT) {
////				innerHeight = parent->calculatedInnerHeight - (margin.horizontal - border.size)*2;
////				innerTop = 0;
////			}
//		}
//	}
//
//	int outerWidth = innerWidth + (margin.horizontal + border.size)*2;
//	int outerHeight = innerHeight + (margin.vertical + border.size)*2;
//
//
//	if (parent && box.adjustPosition == ADJUST_POSITION_TO_PARENT_CURSOR) {
//
////		if (box.breakLine) {
////			parent->cursorBreakLine(outerHeight);
////		}
//
//		// have to break line OR not enough space in parent?
//		if (box.breakLine || parent->cursor.left + outerWidth > parent->calculatedInnerWidth) {
//
//			// extending parent width to cursor size
////			if (parent->calculatedInnerWidth < parent->cursor.left) {
////				parent->calculatedInnerWidth = parent->cursor.left;
//////				parent->setSize(outerWidth);
//////				cursor.left += outerWidth;
//////				//parent->recalc = true;
////			}
//			parent->cursorBreakLine(outerHeight);
//
//
//		}
//
//		innerTop += parent->cursor.top;
//		innerLeft += parent->cursor.left;
//		parent->cursorStep(outerWidth, outerHeight);
//		// extending parent width to cursor size
//					if (parent->calculatedInnerWidth < parent->cursor.left) {
//						parent->calculatedInnerWidth = parent->cursor.left;
//		//				parent->setSize(outerWidth);
//		//				cursor.left += outerWidth;
//		//				//parent->recalc = true;
//					}
//
//		// extending parent height to cursor size
//		parent->calculatedInnerHeight =
//				parent->calculatedInnerHeight >= parent->cursor.top + parent->cursor.lnHeight ?
//				parent->calculatedInnerHeight :
//				parent->cursor.top + parent->cursor.lnHeight;
//
//	}
//
//	// apply the given extra offset argumanets
//	innerTop += offsetTop;
//	innerLeft += offsetLeft;
//
//
//
//	calculatedInnerTop = innerTop;
//	calculatedInnerLeft = innerLeft;
//	calculatedInnerWidth = innerWidth;
//	calculatedInnerHeight = innerHeight;
//	calculatedTextTop = innerTop + padding.vertical;
//	calculatedTextLeft = innerLeft + padding.horizontal;
//
//
//	// paint children
//	cursorReset();
////	recalc = true;
////	while(recalc) {
////		cursor.top = 0;
////		cursor.lnHeight = 0;
////		recalc = false;
//		for (int i = 0; i < CANVASES; i++) {
//			if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
//				canvases[i]->calc(offsetTop + innerTop, offsetLeft + innerLeft);
//
////				if (recalc) {
////					break;
////				}
//			}
//		}
////	}
//
//
//}


//void Canvas::clear() {
//	Color bgColor = getClearColor();
//	Painter::fillrect(current.box.top, current.box.left, current.box.width, current.box.height, bgColor);
//	Painter::text(current.box.top + current.padding.vertical, current.box.left + current.padding.horizontal, current.text.label, bgColor, bgColor, current.text.size);
//	Painter::rect(current.box.top, current.box.left, current.box.width, current.box.height, bgColor, current.border.size);
//}
//
//void Canvas::draw() {
//
////	if (paintInner) {
//		Painter::fillrect(current.box.top, current.box.left, current.box.width, current.box.height, current.box.color);
//		Painter::text(current.box.top + current.padding.vertical, current.box.left + current.padding.horizontal, current.text.label, current.text.color, current.box.color, current.text.size);
////		paintInner = false;
////	}
//
////	if (paintBorder) {
//		Painter::rect(current.box.top, current.box.left, current.box.width, current.box.height, current.border.color, current.border.size);
////		paintBorder = false;
////	}
//
//}

Color Canvas::getClearColor() {
	Canvas* behind = parent ? parent : this;
	Color color = behind->box.color;
	if (behind->selected) color = behind->box.colorSelected;
	if (behind->pushed) color = behind->box.colorPushed;
	if (behind->disabled) color = behind->box.colorDisabled;
	return color;
}
//
//
//Color Canvas::getClearColor() {
//	return parent ? parent->getClearColor() : box.color;
//}

bool Canvas::select(bool sel) {
	if (!inactive && !disabled && !hidden) {
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->selected) {
				if (canvases[i]->selected) {
					canvases[i]->draw();
				}
				canvases[i]->selected = false;
//				canvases[i]->paintBorder = true;
			}
		}

		selected = sel;
		draw();

//		paintBorder = true;
		//draw();
	}
	return selected;
}

bool Canvas::push(bool psh) {
	if (!inactive && !disabled && !hidden) {
		pushed = psh;
//		paintInner = true;
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
			//draw();
			break;
		}
	}
}

void Canvas::selectPrev() {
	int sid = getSelectedId();
	int i = sid - 1 >= 0 ? sid - 1 : CANVASES - 1;
	for (; i >= 0; i--) {
		if (canvases[i] && canvases[i]->select()) {
			//draw();
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

//bool Canvas::isChanged() {
//	if (paintBorder || paintInner) {
//		return true;
//	}
//	for (int i=0; i<CANVASES; i++) {
//		if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id && canvases[i]->isChanged()) {
//			return true;
//		}
//	}
//	return false;
//}


// public:

Canvas::Canvas(Canvas* parent) {
	this->parent = parent;

	for (id=0; id<CANVASES; id++) {
		if (!canvases[id]) {
			canvases[id] = this;
			break;
		}
	}

//	paintBorder = true;
//	paintInner = true;

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

//	calculatedInnerTop = 0;
//	calculatedInnerLeft = 0;
//	calculatedInnerWidth = 0;
//	calculatedInnerHeight = 0;
//	calculatedTextTop = 0;
//	calculatedTextLeft = 0;
//	calculatedBorderColor = GUI_NONE;
//	calculatedInnerColor = GUI_NONE;
//	calculatedTextColor = GUI_NONE;
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
		//clear();
		box.width = width;
		box.height = height;
		//calc();
		//draw();
//		adjust.toTextSize = false;
//		paintBorder = true;
//		paintInner = true;
	}
}

void Canvas::setSize(int width) {
	if (box.width != width) {
		//clear();
		box.width = width;
		//calc();
		//draw();
//		adjust.toTextSize = false;
//		paintBorder = true;
//		paintInner = true;
	}
}

void Canvas::setColor(int color, int colorSelected, int colorDisabled, int colorPushed) {
	if (box.color != color) {
		box.color = color;
//		paintInner = true;
		//draw();
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
//		paintInner = true;
		//draw();
	}
}

void Canvas::setColorDisabled(int colorDisabled) {
	if (box.colorDisabled != colorDisabled) {
		box.colorDisabled = colorDisabled;
//		paintInner = true;
		//draw();
	}
}

void Canvas::setColorPushed(int colorPushed) {
	if (box.colorPushed != colorPushed) {
		box.colorPushed = colorPushed;
//		paintInner = true;
		//draw();
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
//			paintBorder = true;
//			paintInner = true;
		}
		text.label[i] = str[i];
		i++;
	}
	text.label[i] = 0;

	if (redraw) {
		//clear();
		//calc();
		//draw();
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
		//draw();
//		paintInner = true;
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
		//draw();
//		paintInner = true;
	}
}

void Canvas::setTextColorDisabled(int colorDisabled) {
	if (text.colorDisabled != colorDisabled) {
		text.colorDisabled = colorDisabled;
		//draw();
//		paintInner = true;
	}
}

void Canvas::setTextColorPushed(int colorPushed) {
	if (text.colorPushed != colorPushed) {
		text.colorPushed = colorPushed;
		//draw();
//		paintInner = true;
	}
}

void Canvas::setTextSize(int size) {
	if (text.size != size) {
		//clear();
		text.size = size;
		//calc();
		//draw();
//		paintBorder = true;
//		paintInner = true;
	}
}

void Canvas::setBreakLine(bool br) {
	if (box.breakLine != br) {
		//clear();
		box.breakLine = br;
		//calc();
		//draw();
//		paintBorder = true;
//		paintInner = true;
	}
}

void Canvas::setPosition(int top, int left) {
	if (box.top != top || box.left != left) {
		//clear();
		box.top = top;
		box.left = left;
		box.positioned = true;
		//calc();
		//draw();
//		adjust.toParentCursor = false;
//		paintBorder = true;
//		paintInner = true;
	}
}

void Canvas::enable() {
	if (disabled) {
		disabled = false;
//		paintInner = true;
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
				canvases[i]->enable();
			}
		}
		//draw();
	}
}

void Canvas::disable() {
	if (!disabled) {
		disabled = true;
//		paintInner = true;
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
				canvases[i]->disable();
			}
		}
		//draw();
	}
}

void Canvas::setMargin(int horizontal, int vertical) {
	if (margin.horizontal != horizontal || margin.vertical != vertical) {
		//clear();
		margin.horizontal = horizontal;
		margin.vertical = vertical;
		//calc();
		//draw();
//		paintBorder = true;
//		paintInner = true;

	}
}

void Canvas::setMarginVertical(int vertical) {
	if (margin.vertical != vertical) {
		//clear();
		margin.vertical = vertical;
		//calc();
		//draw();
//		paintBorder = true;
//		paintInner = true;
	}
}

void Canvas::setPadding(int horizontal, int vertical) {
	if (padding.horizontal != horizontal || padding.vertical != vertical) {
		//clear();
		padding.horizontal = horizontal;
		padding.vertical = vertical;
//		paintBorder = true;
//		paintInner = true;
		//calc();
		//draw();

	}
}

void Canvas::setPaddingVertical(int vertical) {
	if (padding.vertical != vertical) {
		//clear();
		padding.vertical = vertical;
//		paintBorder = true;
//		paintInner = true;
		//calc();
		//draw();
	}
}

void Canvas::setBorder(int size, int color) {
	if (border.size != size) {
		//clear();
		border.size = size;
		//calc();
		//draw();
	}
	if (border.color != color) {
		border.color = color;
//		paintBorder = true;
		//draw();
	}
}

void Canvas::setBorderSize(int size) {
	if (border.size != size) {
		//clear();
		border.size = size;
//		paintBorder = true;
		//calc();
		//draw();
	}
}

void Canvas::setBorderColor(int color, int colorSelected, int colorDisabled, int colorPushed) {
	if (border.color != color) {
		border.color = color;
//		paintBorder = true;
		//draw();
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
//		paintInner = true;
		//draw();
	}
}

void Canvas::setBorderColorDisabled(int colorDisabled) {
	if (border.colorDisabled != colorDisabled) {
		border.colorDisabled = colorDisabled;
//		paintInner = true;
		//draw();
	}
}

void Canvas::setBorderColorPushed(int colorPushed) {
	if (border.colorPushed != colorPushed) {
		border.colorPushed = colorPushed;
//		paintInner = true;
		//draw();
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
//
//void Canvas::setAdjustSize(int adjustSize) {
//	if (box.adjustSize != adjustSize) {
//		//clear();
//		box.adjustSize = adjustSize;
////		paintBorder = true;
////		paintInner = true;
//		//calc();
//		//draw();
//	}
//}
//
//void Canvas::setAdjustPosition(int adjustPosition) {
//	if (box.adjustPosition != adjustPosition) {
//		//clear();
//		box.adjustPosition = adjustPosition;
////		paintBorder = true;
////		paintInner = true;
//		//calc();
//		//draw();
//	}
//}

void Canvas::show() {
	if (hidden) {
		hidden = false;
//		paintBorder = true;
//		paintInner = true;
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
				canvases[i]->show();
			}
		}
		//calc();
		//draw();
	}
}

void Canvas::hide() {
	if (!hidden) {
		//clear();
		hidden = true;
//		paintBorder = true;
//		paintInner = true;
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
				canvases[i]->hide();
			}
		}
		//calc();
		//draw();
	}
}

void Canvas::destroy() {
	//clear();
	int i = id;
//	delete canvases[i];
	for (; i<CANVASES; i++) {
		canvases[i] = canvases[i+1];
		canvases[i]->id--;
	}
//	paintInner = true;
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

