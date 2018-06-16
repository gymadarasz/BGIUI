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
#include "Cursor.h"

#define CANVAS_INSTANCES 10 // TODO: increase if needs more

namespace GUI {

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

	static void setInstance(int id, Canvas* canvas);
	virtual Canvas* setAdjust(bool adjust);
	virtual Canvas* setId(int id);
	virtual Canvas* setParent(Canvas* parent = 0);
	virtual Canvas* setTop(int top);
	virtual Canvas* setLeft(int left);
	virtual Canvas* setWidth(int width);
	virtual Canvas* setHeight(int height);
	virtual Canvas* setColor(int color);
	virtual Canvas* setColorPushed(int colorPushed);
	virtual Canvas* setBorderSize(int borderSize);
	virtual Canvas* setBorderColor(int borderColor);
	virtual Canvas* setBorderColorSelected(int borderColorSelected);
	virtual Canvas* setMarginSize(int marginSize);
	virtual Canvas* setSelected(bool selected);
	virtual Canvas* setPushed(bool pushed);
	virtual Canvas* setChangedBorder(bool changedBorder);
	virtual Canvas* setChangedInner(bool changedInner);
	virtual Canvas* setLineBreak(bool lineBreak);

	virtual Canvas* getParent();
	virtual bool getAdjust();
	virtual int getTop();
	virtual int getLeft();
	virtual int getWidth();
	virtual int getHeight();
	virtual int getColor();
	virtual int getColorPushed();
	virtual int getBorderSize();
	virtual int getBorderColor();
	virtual int getBorderColorSelected();
	virtual int getMarginSize();
	virtual bool getSelected();
	virtual bool getPushed();
	virtual bool getChangedBorder();
	virtual bool getChangedInner();
	virtual bool getLineBreak();

	virtual int calcTopRelativeToParent();
	virtual int calcLeftRelativeToParent();
	virtual int calcWidthFull();
	virtual int calcHeightFull();
	virtual int calcColorCurrent();
	virtual int calcBorderColorCurrent();

	virtual void drawBorder(int offsetTop, int offsetLeft);
	virtual void drawInner(int offsetTop, int offsetLeft);
	virtual void drawChildren();
public:
	Canvas(Canvas* parent = 0);
	virtual ~Canvas();
	static Canvas* getInstance(int id);
	static void clearInstances();
	virtual int getId();
	virtual Canvas* setup(
		bool adjust = true,
		int width = 0,
		int height = 0,
		int top = 0,
		int left = 0,
		int color = GUI_CANVAS_COLOR,
		int colorPushed = GUI_CANVAS_COLOR_PUSHED,
		int borderSize = GUI_CANVAS_BORDER_SIZE,
		int borderColor = GUI_CANVAS_BORDER_COLOR,
		int borderColorSelected = GUI_CANVAS_BORDER_COLOR_SELECTED,
		int marginSize = GUI_CANVAS_MARGIN_SIZE
	);
	virtual void draw(int offsetTop = 0, int offsetLeft = 0);
	static void debugInstances();
};

} /* namespace GUI */

#endif /* CANVAS_H_ */
