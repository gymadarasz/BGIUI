/*
 * ScrollMinusButton.h
 *
 *  Created on: Jun 18, 2018
 *      Author: Gyula
 */

#ifndef SCROLLMINUSBUTTON_H_
#define SCROLLMINUSBUTTON_H_

#include "Button.h"
#include "Scroll.h"

namespace GUI {

class ScrollMinusButton: public Button {
public:
	ScrollMinusButton(Canvas* parent = 0);
	virtual void onClick(int mouseLeft, int mouseTop);
};

} /* namespace GUI */

#endif /* SCROLLMINUSBUTTON_H_ */
