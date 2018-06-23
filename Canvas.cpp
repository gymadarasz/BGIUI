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

void Canvas::paint(int offsetTop, int offsetLeft) {

	if (paintBorder || paintInner) {

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


		// paint border
		if (paintBorder) {
			Painter::rect(innerTop, innerLeft, innerWidth, innerHeight, border.color, border.size);
			paintBorder = false;
		}

		// paint inner box
		if (paintInner) {

//			// show margins
//			Painter::rect(innerTop - border.size - margin.vertical, innerLeft - border.size - margin.horizontal,
//					innerWidth + (border.size + margin.vertical)*2, innerHeight + (border.size + margin.vertical)*2, DARKGRAY);

			Painter::fillrect(innerTop, innerLeft, innerWidth, innerHeight, box.color);

			// paint text (+ padding size)
			int textTop = innerTop + padding.vertical;
			int textLeft = innerLeft + padding.horizontal;

			Painter::text(textTop, textLeft, text.label, text.color, box.color, text.size);

			// paint children
			cursorReset();
			for (int i = 0; i < CANVASES; i++) {
				if (canvases[i] && canvases[i]->parent && canvases[i]->parent->id == id) {
					canvases[i]->paintBorder = true;
					canvases[i]->paintInner = true;
					canvases[i]->paint(offsetTop + innerTop, offsetLeft + innerLeft);
//					// paint cursor
//					Painter::rect(
//							offsetTop + innerTop,
//							offsetLeft + innerLeft,
//							cursor.left,
//							cursor.top + cursor.lnHeight,
//							YELLOW);
//					delay(1000);
				}
			}

			paintInner = false;
		}
	}

}

bool Canvas::select() {
	if (!disabled) {
		for (int i=0; i<CANVASES; i++) {
			if (canvases[i] && canvases[i]->selected) {
				canvases[i]->selected = false;
				canvases[i]->paintBorder = true;
			}
		}
		selected = true;
		paintBorder = true;
	}
	return selected;
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
	}
}

void Canvas::disable() {
	if (!disabled) {
		disabled = true;
		paintInner = true;
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

} /* namespace gui */

