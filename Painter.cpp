/*
 * Painter.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "Painter.h"

#include "style.h"

namespace GUI {

	int Painter::init(int width, int height, char* title, int left, int top, bool dbflag, bool closeflag) {

		int found = false;

#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__)
		initwindow(width, height, title, left, top, dbflag, closeflag);
		found = true;
#endif

#if defined(linux)
		initGraphics(width, height);
		found = true;
#endif

#if defined(__BORLANDC__)
		int g=DETECT,d;
		initgraph(&g,&d,(char*)"../../bgi");
		found = true;
#endif

		clear();

		return found;
	}

	int Painter::close() {
		closegraph();
		return 0;
	}

	void Painter::clear() {
		cleardevice();
	}

    void Painter::hline(int x, int y1, int y2, int color) {
        if (color == GUI_NOCOLOR) {
            return ;
        }

        int c = getcolor();
        setcolor(color);
        line(x, y1, x, y2);
        setcolor(c);
    }

    void Painter::vline(int x1, int y, int x2, int color) {
        if (color == GUI_NOCOLOR) {
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

	int Painter::getmaxwidth() {
		return getmaxx();
	}

	int Painter::getmaxheight() {
		return getmaxy();
	}

	int Painter::getTextWidth(char* text) {
		if (!text) {
			return 0;
		}
		return textwidth(text);
	}

	int Painter::getTextHeight(char* text) {
		if (!text) {
			return 0;
		}
		return textheight(text);
	}

	void Painter::text(int top, int left, char* text, int color, int bgcolor) {
        if (color == GUI_NOCOLOR) {
            if (bgcolor != GUI_NOCOLOR) {
                fillrect(top, left, getTextWidth(text), getTextHeight(text), bgcolor);
            }
        }

        int c = getcolor();
        int b = getbkcolor();
        setcolor(color);
        setbkcolor(bgcolor);
        outtextxy(left, top, text);
        setcolor(c);
        setbkcolor(b);
	}

} /* namespace GUI */
