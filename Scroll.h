/*
 * Scroll.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Gyula
 */

#ifndef SCROLL_H_
#define SCROLL_H_

#include "Canvas.h"
//#include "Button.h"
#include "ScrollMinusButton.h"
#include "ScrollPlusButton.h"
#include "ScrollAreaCanvas.h"
#include "ScrollHandlerCanvas.h"

namespace GUI {

class ScrollMinusButton;
class ScrollPlusButton;
class ScrollAreaCanvas;

class Scroll: public Canvas {
	int value;
	int minValue;
	int maxValue;
	ScrollMinusButton* minusButton;
	ScrollAreaCanvas* scrollAreaCanvas;
	ScrollHandlerCanvas* scrollHandlerCanvas;
	ScrollPlusButton* plusButton;
	bool initializedChildren;
	bool initializedValue;

	CanvasEventHandler onScrollHandler;

	Scroll* setMinusButton(ScrollMinusButton* minusButton);
	Scroll* setScrollAreaCanvas(ScrollAreaCanvas* scrollAreaCanvas);
	Scroll* setScrollHandlerCanvas(ScrollHandlerCanvas* scrollHandlerCanvas);
	Scroll* setPlusButton(ScrollPlusButton* plusButton);
	Scroll* setInitializedChildren(bool initializedChildren);
	Scroll* setInitializedValue(bool initializedValue);

	bool getInitializedChildren();
	bool getInitializedValue();

	bool initializeChildren(char* minusText, char* plusText, int areaColor, int areaColorPushed, int handlerColor, int handlerColorPushed);

	int repositionScrollHandlerCanvas();

public:
	Scroll(Canvas* parent = 0);
	virtual ~Scroll();
//	virtual Scroll* setup(
//		int value = GUI_SCROLL_DEFAULT_VALUE,
//		int minValue = GUI_SCROLL_DEFAULT_MIN_VALUE,
//		int maxValue = GUI_SCROLL_DEFAULT_MIN_VALUE,
////		Text minusText = GUI_SCROLL_MINUS_TEXT,
////		Text plusText = GUI_SCROLL_PLUS_TEXT,
//		bool adjust = GUI_SCROLL_DEFAULT_ADJUST,
//		int width = GUI_SCROLL_DEFAULT_WIDTH,
//		int height = GUI_SCROLL_DEFAULT_HEIGHT,
//		int top = GUI_SCROLL_DEFAULT_TOP,
//		int left = GUI_SCROLL_DEFAULT_LEFT,
//		int color = GUI_SCROLL_COLOR,
//		int colorPushed = GUI_SCROLL_COLOR_PUSHED,
//		int colorSelected = GUI_SCROLL_COLOR_SELECTED,
//		int borderSize = GUI_SCROLL_BORDER_SIZE,
//		int borderColor = GUI_SCROLL_BORDER_COLOR,
//		int borderColorSelected = GUI_SCROLL_BORDER_COLOR_SELECTED,
//		int marginSize = GUI_SCROLL_MARGIN_SIZE,
//		int areaColor = GUI_SCROLL_AREA_COLOR,
//		int areaColorPushed = GUI_SCROLL_AREA_COLOR_PUSHED,
//		int handlerColor = GUI_SCROLL_HANDLER_COLOR,
//		int handlerColorPushed = GUI_SCROLL_HANDLER_COLOR_PUSHED
//	);
	virtual Scroll* setValue(int value);
	virtual Scroll* setMinValue(int minValue);
	virtual Scroll* setMaxValue(int maxValue);
	virtual int getValue();
	virtual int getMinValue();
	virtual int getMaxValue();

	ScrollMinusButton* getMinusButton();
	ScrollAreaCanvas* getScrollAreaCanvas();
	ScrollHandlerCanvas* getScrollHandlerCanvas();
	ScrollPlusButton* getPlusButton();

	virtual CanvasEventHandler getScrollHandler();

	virtual Canvas* setScrollHandler(CanvasEventHandler canvasEventHandler);

	virtual void onScroll(int value, int previousValue);
};

} /* namespace GUI */

#endif /* SCROLL_H_ */
