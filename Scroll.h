/*
 * Scroll.h
 *
 *  Created on: Jun 24, 2018
 *      Author: Gyula
 */

#ifndef SCROLL_H_
#define SCROLL_H_


#include "defs.h"
#include "Canvas.h"

namespace gui {

class ScrollHandler: public Canvas {
public:
	ScrollHandler(Canvas* canvas = 0, int width = 0, int height = 0);
	virtual ~ScrollHandler();
	virtual void onKeyPress(int key);
};

class Scroll: public Canvas {
	Canvas* handler;
	int value;
	int minValue;
	int maxValue;
	int repositionScrollHandlerCanvas();
public:

	CanvasEventHandler onScrollHandler;

	Scroll(Canvas* parent = 0, int width = 0, int height = 0);
	virtual ~Scroll();
	virtual void setInterval(int minValue, int maxValue);
	virtual void setValue(int value);

	virtual int getValue();

	virtual void onClick(int mouseLeft, int mouseTop);
	virtual void onMouseDrag(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent);
	virtual void onScroll(int oldValue, int newValue);

	int getMinValue() const {
		return minValue;
	}

	int getMaxValue() const {
		return maxValue;
	}
};


} /* namespace gui */

#endif /* SCROLL_H_ */
