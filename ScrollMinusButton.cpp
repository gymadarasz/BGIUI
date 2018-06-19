/*
 * ScrollMinusButton.cpp
 *
 *  Created on: Jun 18, 2018
 *      Author: Gyula
 */

#include "ScrollMinusButton.h"

namespace GUI {

// public:

ScrollMinusButton::ScrollMinusButton(Canvas* parent): Button(parent) {

}


void ScrollMinusButton::onClick(int mouseLeft, int mouseTop) {
	Scroll* parent = (Scroll*)getParent();
	if (parent) {
		int value = parent->getValue();
		int minValue = parent->getMinValue();
		value--;
		if (value < minValue) {
			value = minValue;
		}
		parent->setValue(value);
	}
}

} /* namespace GUI */
