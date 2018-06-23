/*
 * Painter.h
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#ifndef PAINTER_H_
#define PAINTER_H_

#include <graphics.h>

namespace gui {

class Painter {
public:
	static int init(
		int width = 0,
		int height = 0,
		char* title = (char*)"Windows BGI",
		int left = 0,
		int top = 0,
		bool dbflag = false,
		bool closeflag = true
	);
	static int close();
	static void clear();
	static void hline(int x, int y1, int y2, int color);
    static void vline(int x1, int y, int x2, int color);
	static void rect(int top, int left, int width, int height, int color, int size = 1);
	static void fillrect(int top, int left, int width, int height, int color);
	static int getMaxWidth();
	static int getMaxHeight();
	static int getTextWidth(char* text, int size = 1, int style = DEFAULT_FONT);
	static int getTextHeight(char* text, int size = 1, int style = DEFAULT_FONT);
	static void text(int top, int left, char* text, int color, int bgcolor, int size = 10, int style = DEFAULT_FONT);
};

} /* namespace GUI */

#endif /* PAINTER_H_ */
