/*
 * GUITest.h
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#ifndef GUITEST_H_
#define GUITEST_H_

#include "Test.h"
#include "style.h"
#include "Label.h"
#include "Button.h"

namespace GUI {

class GUITest: public Test {
	void testWindow();
	void testCanvasIncrement();
	void testCanvasDraw();
	void testCanvasBoxing();
	void testCanvasAutoPosition();
	void testCursor();
	void testLabelAndLineBreak();
	void testButtonClick();
public:
	static int exampleButtonClicked(Canvas* btn, ...);
    virtual void run();
};

} /* namespace GUI */

#endif /* GUITEST_H_ */
