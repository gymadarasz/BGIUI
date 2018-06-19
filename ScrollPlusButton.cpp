/*
 * ScrollPlusButton.cpp
 *
 *  Created on: Jun 18, 2018
 *      Author: Gyula
 */

#include "ScrollPlusButton.h"

namespace GUI {


// public:

ScrollPlusButton::ScrollPlusButton(Canvas* parent): Button(parent) {

}


void ScrollPlusButton::onClick(int mouseLeft, int mouseTop) {
	Button::onClick(mouseLeft, mouseTop);
	Scroll* parent = (Scroll*)getParent();
	if (parent) {
		int value = parent->getValue();
		int maxValue = parent->getMaxValue();
		value++;
		if (value > maxValue) {
			value = maxValue;
		}
		parent->setValue(value);
	}
}

} /* namespace GUI */
