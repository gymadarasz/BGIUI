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

#define GUI_CANVAS_INSTANCES 100

namespace GUI {

class Canvas {
	static int next;
	static Canvas* instances[GUI_CANVAS_INSTANCES];
	int id;
	Canvas* parent;
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

	static void setInstance(int id, Canvas* canvas);
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
	virtual Canvas* setSelected(bool selected);
	virtual Canvas* setPushed(bool pushed);
	virtual Canvas* setChangedBorder(bool changedBorder);
	virtual Canvas* setChangedInner(bool changedInner);

	virtual Canvas* getParent();
	virtual int getTop();
	virtual int getLeft();
	virtual int getWidth();
	virtual int getHeight();
	virtual int getColor();
	virtual int getColorPushed();
	virtual int getBorderSize();
	virtual int getBorderColor();
	virtual int getBorderColorSelected();
	virtual bool getSelected();
	virtual bool getPushed();
	virtual bool getChangedBorder();
	virtual bool getChangedInner();

	virtual int calcTopAbsolute();
	virtual int calcLeftAbsolute();
	virtual int calcWidthFull();
	virtual int calcHeightFull();
	virtual int calcColorCurrent();
	virtual int calcBorderColorCurrent();
	virtual int calcTopBorderAbsolute();
	virtual int calcLeftBorderAbsolute();

	virtual void drawBorder();
	virtual void drawInner();
public:
	Canvas(Canvas* parent = 0);
	virtual ~Canvas();
	static Canvas* getInstance(int id);
	virtual int getId();
	virtual Canvas* setup(
		int width,
		int height,
		int top = GUI_ADJUST,
		int left = GUI_ADJUST,
		int color = GUI_CANVAS_COLOR,
		int colorPushed = GUI_CANVAS_COLOR_PUSHED,
		int borderSize = GUI_CANVAS_BORDER_SIZE,
		int borderColor = GUI_CANVAS_BORDER_COLOR,
		int borderColorSelected = GUI_CANVAS_BORDER_COLOR_SELECTED
	);
	virtual void draw();
};

} /* namespace GUI */

#endif /* CANVAS_H_ */
