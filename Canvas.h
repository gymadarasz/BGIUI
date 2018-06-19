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
	bool noDraw;
//	int calculatedWidth;
//	int calculatedHeight;
	bool initializedScreenTop;
	bool initializedScreenLeft;

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
	virtual Canvas* setId(int id);
	virtual Canvas* setParent(Canvas* parent = 0);
	virtual Canvas* setSelected(bool selected);
	virtual Canvas* setScreenTop(int screenTop);
	virtual Canvas* setScreenLeft(int screenLeft);
//	virtual Canvas* setCalculatedWidth(int calculatedWidth);
//	virtual Canvas* setCalculatedHeight(int calculatedHeight);
	virtual Canvas* setNoDraw(bool noDraw);

	virtual Canvas* setChildrenChanged(bool changed);
	virtual Canvas* setInitializedScreenTop(bool initializedScreenTop);
	virtual Canvas* setInitializedScreenLeft(bool initializedScreenLeft);

	virtual Canvas* getRootCanvas();

	virtual int getTop();
	virtual int getLeft();
	virtual int getBorderColor();
	virtual int getBorderColorSelected();
	virtual int getMarginSize();
	virtual bool getSelected();
	virtual bool getChangedBorder();
	virtual bool getChangedInner();
	virtual bool getLineBreak();
	virtual int getScreenTop();
	virtual int getScreenLeft();
//	virtual int getCalculatedWidth();
//	virtual int getCalculatedHaight();
	virtual bool getInitializedScreenTop();
	virtual bool getInitializedScreenLeft();

	virtual int calcWidthWithChildren();
	virtual int calcHeightWithChildren();

	static int calcFirstSelected();
	static int calcLastSelected();
	static int unselectAll();

	virtual bool drawBorder(int offsetTop, int offsetLeft);
	virtual int drawChildren(int offsetTop, int offsetLeft);
	virtual bool isInside(EventPoint eventPoint);
	virtual int tickChildren();
protected:

	virtual bool drawInner(int offsetTop, int offsetLeft);

	// setters

	// getters
	virtual Canvas* getParent();
	virtual bool getAdjust();
	virtual int getColor();
	virtual int getColorPushed();
	virtual int getBorderSize();
	virtual bool getEnabled();
	virtual bool getNoDraw();



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
	virtual Canvas* clear();
	virtual Canvas* setLineBreak(bool lineBreak);
	static int selectNext();
	static int selectPrev();
	static int selectedsClick();

	static int clearAll(Canvas* parent = 0);

	// events getters
	virtual CanvasEventHandler getTickHandler();
	virtual CanvasEventHandler getClickHandler();
	virtual CanvasEventHandler getDblClickHandler();
	virtual CanvasEventHandler getMouseMoveHandler();
	virtual CanvasEventHandler getMouseDragHandler();
	virtual CanvasEventHandler getMouseOverHandler();
	virtual CanvasEventHandler getMouseLeaveHandler();
	virtual CanvasEventHandler getMouseDownHandler();
	virtual CanvasEventHandler getMouseUpHandler();

	// events setters
	virtual Canvas* setTickHandler(CanvasEventHandler onTickHandler);
	virtual Canvas* setClickHandler(CanvasEventHandler onClickHandler);
	virtual Canvas* setDblClickHandler(CanvasEventHandler onDblClickHandler);
	virtual Canvas* setMouseMoveHandler(CanvasEventHandler onMouseMoveHandler);
	virtual Canvas* setMouseDragHandler(CanvasEventHandler onMouseDragHandler);
	virtual Canvas* setMouseOverHandler(CanvasEventHandler onMouseOverHandler);
	virtual Canvas* setMouseLeaveHandler(CanvasEventHandler onMouseLeaveHandler);
	virtual Canvas* setMouseDownHandler(CanvasEventHandler onMouseDownHandler);
	virtual Canvas* setMouseUpHandler(CanvasEventHandler onMouseUpHandler);

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

	// setters
	virtual Canvas* setAdjust(bool adjust);
	virtual Canvas* setEnabled(bool enabled);
	virtual Canvas* setWidth(int width);
	virtual Canvas* setHeight(int height);
	virtual Canvas* setTop(int top);
	virtual Canvas* setLeft(int left);
	virtual Canvas* setMarginSize(int marginSize);
	virtual Canvas* setBorderSize(int borderSize);
	virtual Canvas* setPushed(bool pushed);
	virtual Canvas* setChangedInner(bool changedInner);
	virtual Canvas* setChangedBorder(bool changedBorder);
	virtual Canvas* setColor(int color);
	virtual Canvas* setColorPushed(int colorPushed);
	virtual Canvas* setBorderColor(int borderColor);
	virtual Canvas* setBorderColorSelected(int borderColorSelected);

	// getters
	virtual int getWidth();
	virtual int getHeight();
	virtual bool getPushed();

	virtual int calcTopRelativeToParent();
	virtual int calcLeftRelativeToParent();
	virtual int calcWidthFull();
	virtual int calcHeightFull();
	virtual int calcColorCurrent();
	virtual int calcBorderColorCurrent();

	// debug
	static void debugInstances();
};

} /* namespace GUI */

#endif /* CANVAS_H_ */
