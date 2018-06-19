/*
 * ScrollAreaCanvas.cpp
 *
 *  Created on: Jun 18, 2018
 *      Author: Gyula
 */

#include "ScrollAreaCanvas.h"

namespace GUI {

// public:

ScrollAreaCanvas::ScrollAreaCanvas(Canvas* parent): Canvas(parent) {

}

void ScrollAreaCanvas::onClick(int mouseLeft, int mouseTop) {
	Canvas::onClick(mouseLeft, mouseTop);

	Scroll* parent = (Scroll*)getParent();
	if (parent) {
		ScrollHandlerCanvas* scrollHandlerCanvas = parent->getScrollHandlerCanvas();
			if (scrollHandlerCanvas) {
			int minValue = parent->getMinValue();
			int maxValue = parent->getMaxValue();
			int areaWidth = getWidth();
			int handlerWidth = scrollHandlerCanvas->getWidth();
			int scrollSize = areaWidth - handlerWidth;
			int minmaxDiff = abs(maxValue - minValue);
			int clickLeft = mouseLeft - (handlerWidth / 2);
			int newValue = (clickLeft * minmaxDiff) / scrollSize;
			if (newValue < minValue) {
				newValue = minValue;
			}
			if (newValue > maxValue) {
				newValue = maxValue;
			}
			parent->setValue(newValue);
		}
	}

}



void ScrollAreaCanvas::onMouseDrag(int mouseLeftFrom, int mouseTopFrom, int mouseLeftCurrent, int mouseTopCurrent) {
	Canvas::onMouseDrag(mouseLeftFrom, mouseTopFrom, mouseLeftCurrent, mouseTopCurrent);
	onClick(mouseLeftCurrent, mouseTopCurrent);
}


} /* namespace GUI */
