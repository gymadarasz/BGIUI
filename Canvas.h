/*
 * Canvas.h
 *
 *  Created on: Jun 21, 2018
 *      Author: Gyula
 */

#ifndef CANVAS_H_
#define CANVAS_H_

#include <stdlib.h>
#include "defs.h"
#include "Painter.h"

namespace gui {

typedef int Color;

typedef struct {
	int horizontal = MARGIN_SIZE_HORIZONTAL;
	int vertical = MARGIN_SIZE_VERTICAL;
} Margin;

typedef struct {
	int size = BORDER_SIZE;
	Color color = BORDER_COLOR;
} Border;

typedef struct {
	int horizontal = PADDING_SIZE_HORIZONTAL;
	int vertical = PADDING_SIZE_VERTICAL;
} Padding;

typedef struct {
	char label[TEXT_BUFFER_SIZE] = "";
	int size = TEXT_SIZE;
//	int align = TEXT_ALIGN_CENTER;
	Color color = TEXT_COLOR;
} Text;

typedef struct {
	int toParentCursor = true;
	bool toTextSize = true;
} Adjust;

typedef struct {
//	int offsetTop = 0;
//	int offsetLeft = 0;
	int top = 0;
	int left = 0;
	int width = 0;
	int height = 0;
	Color color = BOX_COLOR;
	bool breakLine = false;
} Box;

typedef struct {
	int top = 0;
	int left = 0;
//	int adjust = CURSOR_ADJUST_FIX_WIDTH;
	int lnHeight = 0;
} Cursor;

class Canvas {
protected:
	static Canvas* canvases[CANVASES];
	Canvas* parent;
	int id;

	bool paintBorder;
	bool paintInner;

	bool disabled;
	bool selected;
	bool pushed;

	Text text;
	Box box;
	Adjust adjust;
	Border border;
	Margin margin;
	Padding padding;
	Cursor cursor;

	virtual void cursorReset();
	virtual bool cursorCheckSpace(int width, int height);
	virtual void cursorBreakLine(int lnHeight);
	virtual void cursorStep(int width, int height);
	virtual void paint(int offsetTop = 0, int offsetLeft = 0);
	virtual bool select();
	virtual void selectNext();
	virtual void selectPrev();

public:

	Canvas(Canvas* parent = 0);
	virtual ~Canvas();
	virtual void setSize(int width, int height);
	virtual void setSize(int width);
	virtual void setColor(int color);
	virtual void setText(const char* str);
	virtual void setText(char* str);
	virtual void setTextColor(int color);
	virtual void setTextSize(int size);
	virtual void setBreakLine(bool br = true);
	virtual void setPosition(int top, int left);
	virtual void enable();
	virtual void disable();
	virtual void setMargin(int horizontal, int vertical);
	virtual void setPadding(int horizontal, int vertical);
	virtual void setBorder(int size, int color);
	virtual void setBorderSize(int size);
	virtual void setBorderColor(int color);
	virtual void setToCursor(bool toParentCursor = true);
};

} /* namespace gui */

#endif /* CANVAS_H_ */
