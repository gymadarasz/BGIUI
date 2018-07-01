/*
 * Painter.h
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#ifndef GUI_CANVASPAINTER_H_
#define GUI_CANVASPAINTER_H_


#include "../guidefs.h"

namespace gui {

class CanvasPainter {
public:
	virtual ~CanvasPainter();
	virtual int init(
		int width = 0,
		int height = 0,
		char* title = (char*)"Windows BGI",
		int left = 0,
		int top = 0,
		bool dbflag = false,
		bool closeflag = true
	);
	virtual int close();
	virtual void clearScreen();
	virtual void hline(int x, int y1, int y2, int color);
	virtual void vline(int x1, int y, int x2, int color);
	virtual void rect(int top, int left, int width, int height, int color, int size = 1);
	virtual void fillrect(int top, int left, int width, int height, int color);
	virtual int getMaxWidth();
	virtual int getMaxHeight();
	virtual int getTextWidth(const char* text, int size = 1, int style = DEFAULT_FONT);
	virtual int getTextWidth(char* text, int size = 1, int style = DEFAULT_FONT);
	virtual int getTextHeight(const char* text, int size = 1, int style = DEFAULT_FONT);
	virtual int getTextHeight(char* text, int size = 1, int style = DEFAULT_FONT);
	virtual void putText(int top, int left, char* text, int color, int bgcolor, int size = 10, int style = DEFAULT_FONT);
};

} /* namespace gui */

#endif /* GUI_CANVASPAINTER_H_ */
