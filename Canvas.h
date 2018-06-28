/*
 * Canvas.h
 *
 *  Created on: Jun 21, 2018
 *      Author: Gyula
 */

#ifndef CANVAS_H_
#define CANVAS_H_


#include "defs.h"
#include "UI/UIKeyboard.h"
#include "UI/UIMouse.h"
#include "UI/UIPainter.h"

namespace gui {

typedef void (*CanvasLoop)(void);

typedef int Color;

typedef struct {
	int horizontal;
	int vertical;
} Margin;

typedef struct {
	int size;
	Color color;
	Color colorSelected;
	Color colorDisabled;
	Color colorPushed;
} Border;

typedef struct {
	int horizontal;
	int vertical;
} Padding;

typedef struct {
	char label[TEXT_BUFFER_SIZE];
	int size;
	Color color;
	Color colorSelected;
	Color colorDisabled;
	Color colorPushed;
} Text;


typedef struct {
	int top;
	int left;
	int width;
	int height;
	Color color;
	Color colorSelected;
	Color colorDisabled;
	Color colorPushed;
	bool breakLine;

	bool fitToText;
	bool positioned;
} Box;

typedef struct {
	int top;
	int left;
	int lnHeight;
} Cursor;

class Canvas;

typedef int (*CanvasEventHandler)(Canvas*, ...);

class Canvas: public UIPainter {
	static int _canvasDeleted;
protected:
	static Canvas* canvases[CANVASES];
	Canvas* parent;
	int id;

	// user input interfaces
	UIKeyboard* kbrd;
	UIMouse* mse;

	Color latestBorderColor;
	Color latestInnerColor;
	Color latestTextColor;

	int realTop;
	int realLeft;
	int fullWidth;
	int fullHeight;

	bool disabled;
	bool selected;
	bool pushed;
	bool hidden;
	bool inactive;
	bool switchable;

	Text text;
	Box box;
	Border border;
	Margin margin;
	Padding padding;
	Cursor cursor;

	bool running;

	// initializers
	void initMargin();
	void initBorder();
	void initPadding();
	void initText();
	void initBox();
	void initCursor();

	//-- events

	virtual void cursorReset();
	virtual void cursorBreakLine(int lnHeight);
	virtual void cursorStep(int width, int height);

	virtual Color getClearColor();
	virtual bool select(bool sel = true);
	virtual bool push(bool sel = true);

	virtual int getSelectedId();
	virtual void selectNext();
	virtual void selectPrev();
	virtual void clickSelected();

	virtual bool isInside(EventPoint eventPoint);

public:

	CanvasEventHandler onTickHandler;
	CanvasEventHandler onClickHandler;
	CanvasEventHandler onDblClickHandler;
	CanvasEventHandler onMouseMoveHandler;
	CanvasEventHandler onMouseDragHandler;
	CanvasEventHandler onMouseOverHandler;
	CanvasEventHandler onMouseLeaveHandler;
	CanvasEventHandler onMouseDownHandler;
	CanvasEventHandler onMouseUpHandler;
	CanvasEventHandler onKeyPressHandler;

	Canvas(Canvas* parent = 0, int width = 0, int height = 0,
			UIKeyboard* kbrd = 0, UIMouse* mse = 0);
	virtual ~Canvas();
	virtual void setSize(int width, int height);
	virtual void setWidth(int width);
	virtual void setHeight(int height);
	virtual void setColor(int color, int colorSelected = GUI_UNDEFINED, int colorDisabled = GUI_UNDEFINED, int colorPushed = GUI_UNDEFINED);
	virtual void setColorSelected(int colorSelected);
	virtual void setColorDisabled(int colorDisabled);
	virtual void setColorPushed(int colorPushed);
	virtual void setTextf(const char* fmt, ...);
	virtual void setText(const char* str, int size = GUI_UNDEFINED);
	virtual void setText(char* str, int size = GUI_UNDEFINED);
	virtual void setTextColor(int color, int colorSelected = GUI_UNDEFINED, int colorDisabled = GUI_UNDEFINED, int colorPushed = GUI_UNDEFINED);
	virtual void setTextColorSelected(int colorSelected);
	virtual void setTextColorDisabled(int colorDisabled);
	virtual void setTextColorPushed(int colorPushed);
	virtual void setTextSize(int size);
	virtual void setBreakLine(bool br = true);
	virtual void setPosition(int top, int left, bool positioned = true);
	virtual void setMargin(int horizontal, int vertical);
	virtual void setMarginVertical(int vertical);
	virtual void setPadding(int horizontal, int vertical);
	virtual void setPaddingVertical(int vertical);
	virtual void setBorder(int size = 0, int color = GUI_NONE);
	virtual void setBorderSize(int size);
	virtual void setBorderColor(int color, int colorSelected = GUI_UNDEFINED, int colorDisabled = GUI_UNDEFINED, int colorPushed = GUI_UNDEFINED);
	virtual void setBorderColorSelected(int colorSelected);
	virtual void setBorderColorDisabled(int colorDisabled);
	virtual void setBorderColorPushed(int colorPushed);
	virtual void setSwitch(bool switchable = true);

	virtual Canvas* getParent();
	virtual int getFullWidth();
	virtual bool isPushed();
	virtual bool isRunning();

	virtual void enable();
	virtual void disable();
	virtual void show();
	virtual void hide();
	virtual void activate();
	virtual void inactivate();


	virtual void calc();
	virtual void draw(Color clearColor = GUI_UNDEFINED);
	virtual void clear();
	virtual void redraw();
	virtual void deleteChildren();

	virtual void run(CanvasLoop loop = 0);
	virtual void tick();

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
	virtual void onKeyPress(int key);
};

} /* namespace gui */

#endif /* CANVAS_H_ */
