/*
 * Cursor.h
 *
 *  Created on: Jun 16, 2018
 *      Author: Gyula
 */

#ifndef CURSOR_H_
#define CURSOR_H_

namespace GUI {

class Cursor {
	int width;
	int top;
	int left;
	int lineHeight;
	Cursor* setWidth(int width);
	Cursor* setTop(int top);
	Cursor* setLeft(int left);
	Cursor* setLineHeight(int lineHeight);
public:
	void reset(int width, int top = 0, int left = 0);
	bool step(int width, int height);
	void br();
	int getWidth();
	int getTop();
	int getLeft();
	int getLineHeight();
};

} /* namespace GUI */

#endif /* CURSOR_H_ */
