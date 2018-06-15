/*
 * Painter.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "Painter.h"

#include "style.h"

namespace GUI {

	int Painter::init(int width, int height, const char* title, int left, int top, bool dbflag, bool closeflag) {

		int found = false;

	#ifdef _WIN32
		initwindow(width, height, title, left, top, dbflag, closeflag);
		found = true;
	#endif

	#ifdef linux
		initGraphics(width, height);
		found = true;
	#endif

		if (!found) {
			int g=DETECT,d;
			initgraph(&g,&d,(char*)"../../bgi");
		}

		cleardevice();

		return found;
	}

	int Painter::close() {
		closegraph();
		return 0;
	}

    void Painter::hline(int x, int y1, int y2, int color) {
        if (color == GUI_STYLE_NOCOLOR) {
            return ;
        }

        int c = getcolor();
        setcolor(color);
        line(x, y1, x, y2);
        setcolor(c);
    }

    void Painter::vline(int x1, int y, int x2, int color) {
        if (color == GUI_STYLE_NOCOLOR) {
            return ;
        }

        int c = getcolor();
        setcolor(color);
        line(x1, y, x2, y);
        setcolor(c);
    }

	void Painter::rect(int top, int left, int width, int height, int color) {
        int bottom = top+height;
        int right = left+width;

		hline(left, top, bottom, color);
		vline(left, top, right, color);
		hline(right, top, bottom, color);
		vline(left, bottom, right, color);
	}

	void Painter::fillrect(int top, int left, int width, int height, int color, int borderColor) {
        int bottom = top+height;
        int right = left+width;

		if (borderColor == -1) {
			borderColor = color;
		}

		hline(left, top, bottom, borderColor);
		vline(left, top, right, borderColor);
		hline(right, top, bottom, borderColor);
		vline(left, bottom, right, borderColor);

		top++;
		left++;
		width -= 2;
		height -= 2;
		for (int y=top; y<bottom; y++) {
			vline(left, y, right, color);
		}
	}

} /* namespace GUI */
