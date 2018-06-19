/*
 * ScrollPlusButton.h
 *
 *  Created on: Jun 18, 2018
 *      Author: Gyula
 */

#ifndef SCROLLPLUSBUTTON_H_
#define SCROLLPLUSBUTTON_H_

#include "Button.h"
#include "Scroll.h"

namespace GUI {

class ScrollPlusButton: public Button {
public:
	ScrollPlusButton(Canvas* parent = 0);
	virtual void onClick(int mouseLeft, int mouseTop);
};

} /* namespace GUI */

#endif /* SCROLLPLUSBUTTON_H_ */
