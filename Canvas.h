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

#define ADJUST_SIZE_NONE 0
#define ADJUST_SIZE_TO_TEXT 1
//#define ADJUST_SIZE_TO_PARENT 2
#define ADJUST_SIZE_TO_PARENT_WIDTH 3
#define ADJUST_POSITION_NONE 0
#define ADJUST_POSITION_TO_PARENT_CURSOR 1

//typedef struct {
//	int position = ADJUST_TO_CURSOR;
////	int toInnerCursor = true;
//	int size = ADJUST_TO_TEXT
//} Adjust;

typedef struct {
	int top = 0;
	int left = 0;
	int adjustPosition = ADJUST_POSITION_TO_PARENT_CURSOR;
	int width = 0;
	int height = 0;
	int adjustSize = ADJUST_SIZE_TO_TEXT;
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
	int calculatedInnerTop;
	int calculatedInnerLeft;
	int calculatedInnerWidth;
	int calculatedInnerHeight;
	int calculatedTextTop;
	int calculatedTextLeft;
	int calculatedBorderColor;
	int calculatedInnerColor;
	int calculatedTextColor;

	bool disabled;
	bool selected;
	bool pushed;
	bool hidden;

	Text text;
	Box box;
	//Adjust adjust;
	Border border;
	Margin margin;
	Padding padding;
	Cursor cursor;

	void cursorReset();
//	bool cursorCheckSpace(int width, int height, int widthMax);
	void cursorBreakLine(int lnHeight);
	void cursorStep(int width, int height);

	void calc(int offsetTop = 0, int offsetLeft = 0);

	Color getClearColor();
	bool select(bool sel = true);
	bool push(bool sel = true);

	int getSelectedId();
	void selectNext();
	void selectPrev();
	void clickSelected();

	bool isInside(EventPoint eventPoint);
	bool isChanged();

public:

	Canvas(Canvas* parent = 0);
	void setSize(int width, int height);
	void setSize(int width);
	void setColor(int color);
	void setText(const char* str);
	void setText(char* str);
	void setTextColor(int color);
	void setTextSize(int size);
	void setBreakLine(bool br = true);
	void setPosition(int top, int left);
	void enable();
	void disable();
	void setMargin(int horizontal, int vertical);
	void setMarginVertical(int vertical);
	void setPadding(int horizontal, int vertical);
	void setPaddingVertical(int vertical);
	void setBorder(int size = 0, int color = NOCOLOR);
	void setBorderSize(int size);
	void setBorderColor(int color);
//	void setToCursor(bool toParentCursor = true);
//	void setToInnerCursor(bool toInnerCuros = true);
	void setAdjustSize(int adjustSize);
	void setAdjustPosition(int adjustPosition);
	void show();
	void hide();
	void destroy();

	//-- events

	void draw();
	void tick();

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
	void onTick();
	void onClick(int mouseLeft, int mouseTop);
	void onDblClick(int mouseLeft, int mouseTop);
	void onMouseMove(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent);
	void onMouseOver(int mouseLeft, int mouseTop);
	void onMouseLeave(int mouseLeft, int mouseTop);
	void onMouseDrag(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent);
	void onMouseDown(int mouseLeft, int mouseTop);
	void onMouseUp(int mouseLeft, int mouseTop);
};

} /* namespace gui */

#endif /* CANVAS_H_ */
