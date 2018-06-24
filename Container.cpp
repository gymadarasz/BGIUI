/*
 * Container.cpp
 *
 *  Created on: Jun 21, 2018
 *      Author: Gyula
 */

#include "Container.h"

namespace gui {

void Container::takeOutText() {
//	int textHeight = Painter::getTextHeight((char*)" ", text.size);
//	setPaddingVertical(-textHeight);
//	setMarginVertical(margin.vertical + textHeight);
}

// public

Container::Container(Canvas* parent): Canvas(parent) {
//	setAdjustSize(ADJUST_SIZE_TO_PARENT_WIDTH);
	takeOutText();
}

void Container::setTextSize(int size) {
	Canvas::setTextSize(size);
	takeOutText();

}

} /* namespace gui */
