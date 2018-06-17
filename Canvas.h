/*
 * Counted.h
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#ifndef CANVAS_H_
#define CANVAS_H_

#include <conio.h>
#include "style.h"
#include "Painter.h"
#include "Mouse.h"
#include "Cursor.h"

#define CANVAS_INSTANCES 10 // TODO: increase if needs more

namespace GUI {

class Canvas;

typedef (*CanvasEventHandler)(Canvas*, ...);

class Canvas {
	static int next;
	static Canvas* instances[CANVAS_INSTANCES];
	int id;
	Canvas* parent;
	bool adjust;
	int top;
	int left;
	int width;
	int height;
	int color;
	int colorPushed;
	int borderSize;
	int borderColor;
	int borderColorSelected;
	bool selected;
	bool pushed;
	bool changedBorder;
	bool changedInner;
	Cursor cursor;
	bool lineBreak;
	int marginSize;
	bool enabled;
	int screenTop;
	int screenLeft;

	// events
	CanvasEventHandler onTickHandler;
	CanvasEventHandler onClickHandler;
	CanvasEventHandler onDblClickHandler;
	CanvasEventHandler onMouseMoveHandler;
	CanvasEventHandler onMouseDragHandler;
	CanvasEventHandler onMouseOverHandler;
	CanvasEventHandler onMouseLeaveHandler;
	CanvasEventHandler onMouseDownHandler;
	CanvasEventHandler onMouseUpHandler;

	static bool setInstance(int id, Canvas* canvas);
	virtual Canvas* setAdjust(bool adjust);
	virtual Canvas* setId(int id);
	virtual Canvas* setParent(Canvas* parent = 0);
	virtual Canvas* setTop(int top);
	virtual Canvas* setLeft(int left);
	virtual Canvas* setColor(int color);
	virtual Canvas* setColorPushed(int colorPushed);
	virtual Canvas* setBorderSize(int borderSize);
	virtual Canvas* setBorderColor(int borderColor);
	virtual Canvas* setBorderColorSelected(int borderColorSelected);
	virtual Canvas* setMarginSize(int marginSize);
	virtual Canvas* setSelected(bool selected);
	virtual Canvas* setPushed(bool pushed);
	virtual Canvas* setChangedBorder(bool changedBorder);
	virtual Canvas* setScreenTop(int screenTop);
	virtual Canvas* setScreenLeft(int screenLeft);

	virtual Canvas* getRootCanvas();

	virtual Canvas* getParent();
	virtual int getTop();
	virtual int getLeft();
	virtual int getBorderColor();
	virtual int getBorderColorSelected();
	virtual int getMarginSize();
	virtual bool getSelected();
	virtual bool getChangedBorder();
	virtual bool getChangedInner();
	virtual bool getLineBreak();
	virtual bool getEnabled();
	virtual int getScreenTop();
	virtual int getScreenLeft();

	virtual int calcWidthFull();
	virtual int calcHeightFull();
	virtual int calcColorCurrent();
	virtual int calcBorderColorCurrent();
	static int calcFirstSelected();
	static int calcLastSelected();
	static int unselectAll();

	virtual bool drawBorder(int offsetTop, int offsetLeft);
	virtual int drawChildren();
	virtual bool isInside(EventPoint eventPoint);
	virtual int tickChildren();
protected:
	virtual Canvas* clear();

	virtual Canvas* setWidth(int width);
	virtual Canvas* setHeight(int height);
	virtual Canvas* setEnabled(bool enabled);
	virtual Canvas* setChangedInner(bool changedInner);

	virtual bool drawInner(int offsetTop, int offsetLeft);
	virtual bool getAdjust();
	virtual int getWidth();
	virtual int getHeight();
	virtual int getColor();
	virtual int getColorPushed();
	virtual int getBorderSize();
	virtual bool getPushed();

	virtual int calcTopRelativeToParent();
	virtual int calcLeftRelativeToParent();

	// events
	void onTick();
	void onClick(int mouseLeft, int moiseTop);
	void onDblClick(int mouseLeft, int moiseTop);
	void onMouseMove(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent);
	void onMouseOver(int mouseLeft, int moiseTop);
	void onMouseLeave(int mouseLeft, int moiseTop);
	void onMouseDrag(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent);
	void onMouseDown(int mouseLeft, int moiseTop);
	void onMouseUp(int mouseLeft, int moiseTop);

public:
	Canvas(Canvas* parent = 0);
	virtual ~Canvas();
	static Canvas* getInstance(int id);
	static int clearInstances();
	virtual int getId();
	virtual Canvas* setup(
		bool adjust = GUI_CANVAS_DEFAULT_ADJUST,
		int width = GUI_CANVAS_DEFAULT_WIDTH,
		int height = GUI_CANVAS_DEFAULT_HEIGHT,
		int top = GUI_CANVAS_DEFAULT_TOP,
		int left = GUI_CANVAS_DEFAULT_LEFT,
		int color = GUI_CANVAS_COLOR,
		int colorPushed = GUI_CANVAS_COLOR_PUSHED,
		int borderSize = GUI_CANVAS_BORDER_SIZE,
		int borderColor = GUI_CANVAS_BORDER_COLOR,
		int borderColorSelected = GUI_CANVAS_BORDER_COLOR_SELECTED,
		int marginSize = GUI_CANVAS_MARGIN_SIZE
	);
	virtual int tick();
	virtual int draw(int offsetTop = 0, int offsetLeft = 0);
	virtual Canvas* setLineBreak(bool lineBreak);
	static int selectNext();
	static int selectPrev();
	static int selectedsClick();

	static int clearAll();

	// events getters
	CanvasEventHandler getTickHandler();
	CanvasEventHandler getClickHandler();
	CanvasEventHandler getDblClickHandler();
	CanvasEventHandler getMouseMoveHandler();
	CanvasEventHandler getMouseDragHandler();
	CanvasEventHandler getMouseOverHandler();
	CanvasEventHandler getMouseLeaveHandler();
	CanvasEventHandler getMouseDownHandler();
	CanvasEventHandler getMouseUpHandler();

	// events setters
    Canvas* setTickHandler(CanvasEventHandler canvasEventHandler);
    Canvas* setClickHandler(CanvasEventHandler canvasEventHandler);
    Canvas* setDblClickHandler(CanvasEventHandler canvasEventHandler);
    Canvas* setMouseMoveHandler(CanvasEventHandler canvasEventHandler);
    Canvas* setMouseDragHandler(CanvasEventHandler canvasEventHandler);
    Canvas* setMouseOverHandler(CanvasEventHandler canvasEventHandler);
    Canvas* setMouseLeaveHandler(CanvasEventHandler canvasEventHandler);
    Canvas* setMouseDownHandler(CanvasEventHandler canvasEventHandler);
    Canvas* setMouseUpHandler(CanvasEventHandler canvasEventHandler);

	static void debugInstances();
};

} /* namespace GUI */

#endif /* CANVAS_H_ */
