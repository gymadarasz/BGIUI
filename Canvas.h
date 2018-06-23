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
#include "Mouse.h"

namespace gui {

typedef int Color;

typedef struct {
	int horizontal = MARGIN_SIZE_HORIZONTAL;
	int vertical = MARGIN_SIZE_VERTICAL;
} Margin;

typedef struct {
	int size = BORDER_SIZE;
	Color color = BORDER_COLOR;
	Color colorSelected = BORDER_COLOR_SELECTED;
	Color colorDisabled = BORDER_COLOR_DISABLED;
	Color colorPushed = BORDER_COLOR_PUSHED;
} Border;

typedef struct {
	int horizontal = PADDING_SIZE_HORIZONTAL;
	int vertical = PADDING_SIZE_VERTICAL;
} Padding;

typedef struct {
	char label[TEXT_BUFFER_SIZE] = "";
	int size = TEXT_SIZE;
	Color color = TEXT_COLOR;
	Color colorSelected = TEXT_COLOR_SELECTED;
	Color colorDisabled = TEXT_COLOR_DISABLED;
	Color colorPushed = TEXT_COLOR_PUSHED;
} Text;

typedef struct {
	int toParentCursor = true;
	bool toTextSize = true;
} Adjust;

typedef struct {
	int top = 0;
	int left = 0;
	int width = 0;
	int height = 0;
	Color color = BOX_COLOR;
	Color colorSelected = BOX_COLOR_SELECTED;
	Color colorDisabled = BOX_COLOR_DISABLED;
	Color colorPushed = BOX_COLOR_PUSHED;
	bool breakLine = false;
} Box;

typedef struct {
	int top = 0;
	int left = 0;
	int lnHeight = 0;
} Cursor;

class Canvas;

typedef int (*CanvasEventHandler)(Canvas*, ...);

class Canvas {
protected:
	static Canvas* canvases[CANVASES];
	Canvas* parent;
	int id;

	bool paintBorder;
	bool paintInner;
	int calculatedTop;
	int calculatedLeft;
	int calculatedWidth;
	int calculatedHeight;
	int calculatedTextTop;
	int calculatedTextLeft;
	int calculatedBorderColor;
	int calculatedBoxColor;
	int calculatedTextColor;

	bool disabled;
	bool selected;
	bool pushed;
	bool hidden;

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
	virtual void calc(int offsetTop = 0, int offsetLeft = 0);
	virtual Color getClearColor();
	virtual bool select(bool sel = true);
	virtual bool push(bool sel = true);
	virtual void selectNext();
	virtual void selectPrev();

	virtual bool isInside(EventPoint eventPoint);

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
	virtual void show();
	virtual void hide();
	virtual void destroy();

	//-- events

	virtual void draw();
	virtual void tick();

	CanvasEventHandler onTickHandler;
	CanvasEventHandler onClickHandler;
	CanvasEventHandler onDblClickHandler;
	CanvasEventHandler onMouseMoveHandler;
	CanvasEventHandler onMouseDragHandler;
	CanvasEventHandler onMouseOverHandler;
	CanvasEventHandler onMouseLeaveHandler;
	CanvasEventHandler onMouseDownHandler;
	CanvasEventHandler onMouseUpHandler;

	// events
	virtual void onTick();
	virtual void onClick(int mouseLeft, int mouseTop);
	virtual void onDblClick(int mouseLeft, int mouseTop);
	virtual void onMouseMove(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent);
	virtual void onMouseOver(int mouseLeft, int mouseTop);
	virtual void onMouseLeave(int mouseLeft, int mouseTop);
	virtual void onMouseDrag(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent);
	virtual void onMouseDown(int mouseLeft, int mouseTop);
	virtual void onMouseUp(int mouseLeft, int mouseTop);
};

} /* namespace gui */

#endif /* CANVAS_H_ */
