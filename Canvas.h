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

namespace GUI {

class Canvas {
	static int next;
	int id;
	Canvas* parent;
	int top;
	int left;
	int width;
	int height;
	int color;

	virtual Canvas* setParent(Canvas* parent = 0);
	virtual Canvas* setTop(int top);
	virtual Canvas* setLeft(int left);
	virtual Canvas* setWidth(int width);
	virtual Canvas* setHeight(int height);
	virtual Canvas* setColor(int color);
public:
	Canvas(Canvas* parent = 0);
	virtual ~Canvas();
	virtual int getId();
	virtual Canvas* setup(
		int top = -1,
		int left = -1,
		int width = -1,
		int height = -1,
		int color = GUI_STYLE_CANVAS_COLOR
	);
};

} /* namespace GUI */

#endif /* CANVAS_H_ */
