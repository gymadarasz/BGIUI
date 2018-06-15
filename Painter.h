/*
 * Painter.h
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#ifndef PAINTER_H_
#define PAINTER_H_

#include <graphics.h>

namespace GUI {

class Painter {
public:
	static int init(
		int width = 0,
		int height = 0,
		const char* title = "Windows BGI",
		int left = 0,
		int top = 0,
		bool dbflag = false,
		bool closeflag = true
	);
	static int close();
	static void hline(int x, int y1, int y2, int color);
    static void vline(int x1, int y, int x2, int color);
	static void rect(int top, int left, int width, int height, int color);
	static void fillrect(int top, int left, int width, int height, int color, int borderColor = -1);
};

} /* namespace GUI */

#endif /* PAINTER_H_ */
