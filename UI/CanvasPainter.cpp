/*
 * Painter.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "CanvasPainter.h"

namespace gui {

	CanvasPainter::CanvasPainter(int width, int height, char* title, int left, int top, bool dbflag, bool closeflag) {

//		int found = false;

#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__)
		initwindow(width, height, title, left, top, dbflag, closeflag);
		HWND hWnd = GetActiveWindow();
		SetWindowText(hWnd, title);
//		found = true;
#endif

#if defined(linux)
		initGraphics(width, height);
//		found = true;
#endif

#if defined(__BORLANDC__)
		int g=DETECT,d;
		initgraph(&g,&d,(char*)"../../bgi");
//		found = true;
#endif

		clearScreen();
		delay(100);

//		return found;
	}

	CanvasPainter::~CanvasPainter() {}

	int CanvasPainter::close() {
		closegraph();
		return 0;
	}

	void CanvasPainter::clearScreen() {
		cleardevice();
	}

    void CanvasPainter::hline(int x, int y1, int y2, int color) {
        if (color == GUI_NONE) {
            return ;
        }

        int c = getcolor();
        setcolor(color);
        line(x, y1, x, y2);
        setcolor(c);
    }

    void CanvasPainter::vline(int x1, int y, int x2, int color) {
        if (color == GUI_NONE) {
            return ;
        }

        int c = getcolor();
        setcolor(color);
        line(x1, y, x2, y);
        setcolor(c);
    }

	void CanvasPainter::rect(int top, int left, int width, int height, int color, int size) {
		if (size && color != GUI_NONE) {
			int bottom = top+height;
			int right = left+width;

			for (int i=0; i < size; i++) {

				top -= 1;
				left -= 1;
				bottom += 1;
				right += 1;

				hline(left, top, bottom, color);
				vline(left, top, right, color);
				hline(right, top, bottom, color);
				vline(left, bottom, right, color);

			}
		}
	}

	void CanvasPainter::fillrect(int top, int left, int width, int height, int color) {
		if (color != GUI_NONE) {
			int bottom = top+height;
			int right = left+width+1;

			for (int y=top; y<=bottom; y++) {
				vline(left, y, right, color);
			}
		}
	}

	int CanvasPainter::getMaxWidth() {
		return getmaxx();
	}

	int CanvasPainter::getMaxHeight() {
		return getmaxy();
	}

	int CanvasPainter::getTextWidth(const char* text, int size, int style) {
		return getTextWidth((char*)text, size, style);
	}

	int CanvasPainter::getTextWidth(char* text, int size, int style) {
		if (!text) {
			return 0;
		}
        struct textsettingstype textinfo;
        gettextsettings(&textinfo);
        settextstyle(style, HORIZ_DIR, size);
		int ret = textwidth(text);
        settextstyle(textinfo.font, textinfo.direction, textinfo.charsize);
        return ret;
	}

	int CanvasPainter::getTextHeight(const char* text, int size, int style) {
		return getTextHeight((char*)text, size, style);
	}

	int CanvasPainter::getTextHeight(char* text, int size, int style) {
		if (!text) {
			return 0;
		}
        struct textsettingstype textinfo;
        gettextsettings(&textinfo);
        settextstyle(style, HORIZ_DIR, size);
		int ret = textheight(text);
        settextstyle(textinfo.font, textinfo.direction, textinfo.charsize);
        return ret;
	}

	void CanvasPainter::putText(int top, int left, char* text, int color, int bgcolor, int size, int style) {
        if (!size || (color == GUI_NONE && bgcolor == GUI_NONE)) {
        	return ;
        }

        int c = getcolor();
        int b = getbkcolor();
        struct textsettingstype textinfo;
        gettextsettings(&textinfo);

        setcolor(color);
        setbkcolor(bgcolor);
        settextstyle(style, HORIZ_DIR, size);

        if (size && bgcolor && color == GUI_NONE) {
        	fillrect(top, left, getTextWidth(text), getTextHeight(text), bgcolor);
        } else {
        	outtextxy(left, top, text);
        }

        setcolor(c);
        setbkcolor(b);
        settextstyle(textinfo.font, textinfo.direction, textinfo.charsize);
	}

} /* namespace GUI */
