/*
 * GUITest.h
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#ifndef GUITEST_H_
#define GUITEST_H_

#include "Test/Test.h"

#include "Window.h"
#include "Canvas.h"
#include "Label.h"
#include "Button.h"
//#include "Switch.h" // TODO: needs tests
#include "Scroll.h"

using namespace GUI;
using namespace test;

class GUITest: public Test {
	void testWindow();
	void testCanvasIncrement();
	void testCanvasDraw();
	void testCanvasBoxing();
	void testCanvasAutoPosition();
	void testCursor();
	void testLabelAndLineBreak();
	void testButtonClick();
	void testMarginsAndOffset();
	void testScrollView();
public:
//	GUITest();
//	virtual ~GUITest();
	static int exampleButtonClicked(Canvas* btn, ...);
    virtual void run();
};

#endif /* GUITEST_H_ */
