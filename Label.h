/*
 * Label.h
 *
 *  Created on: Jun 16, 2018
 *      Author: Gyula
 */

#ifndef LABEL_H_
#define LABEL_H_

#include "Canvas.h"

namespace GUI {

class Label: public Canvas {
	char* text;
	int textColor;
	int paddingSize;

	Label* setTextColor(int color);
	Label* setPaddingSize(int paddingSize);
	virtual char* getText();
	virtual int getTextColor();
	virtual int getPaddingSize();
	virtual bool drawInner(int offsetTop, int offsetLeft);
public:
	Label(Canvas* parent = 0);
	virtual ~Label();
	virtual Label* setup(
		char* text = GUI_LABEL_DEFAULT_TEXT,
		int textColor = GUI_LABEL_TEXT_COLOR,
		bool adjust = GUI_LABEL_DEFAULT_ADJUST,
		int width = GUI_LABEL_DEFAULT_WIDTH,
		int height = GUI_LABEL_DEFAULT_HEIGHT,
		int top = GUI_LABEL_DEFAULT_TOP,
		int left = GUI_LABEL_DEFAULT_LEFT,
		int color = GUI_LABEL_COLOR,
		int colorPushed = GUI_LABEL_COLOR_PUSHED,
		int colorSelected = GUI_LABEL_COLOR_SELECTED,
		int borderSize = GUI_LABEL_BORDER_SIZE,
		int borderColor = GUI_LABEL_BORDER_COLOR,
		int borderColorSelected = GUI_LABEL_BORDER_COLOR_SELECTED,
		int marginSize = GUI_LABEL_MARGIN_SIZE,
		int paddingSize = GUI_LABEL_PADDING_SIZE
	);
	Label* setText(char* text);
};

} /* namespace GUI */

#endif /* LABEL_H_ */
