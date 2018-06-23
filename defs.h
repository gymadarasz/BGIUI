/*
 * style.h
 *
 *  Created on: Jun 21, 2018
 *      Author: Gyula
 */

#ifndef STYLE_H_
#define STYLE_H_

#include <graphics.h>

// common

#define CANVASES 40		// increment it if you need more canvases

#define NOCOLOR -1

//
#define MARGIN_SIZE_HORIZONTAL		4
#define MARGIN_SIZE_VERTICAL		4

#define BORDER_SIZE					1
#define BORDER_COLOR				DARKGRAY
#define BORDER_COLOR_PUSHED			DARKGRAY
#define BORDER_COLOR_SELECTED		WHITE

#define PADDING_SIZE_HORIZONTAL		8
#define PADDING_SIZE_VERTICAL		4

#define COLOR						LIGHTGRAY
#define COLOR_PUSHED				DARKGRAY
#define COLOR_SELECTED				LIGHTGRAY

#define TEXT_BUFFER_SIZE			255
#define TEXT_SIZE					1
#define TEXT_COLOR					BLACK
#define TEXT_COLOR_PUSHED			BLACK
#define TEXT_COLOR_SELECTED			BLACK

#define BOX_COLOR					LIGHTGRAY
#define BOX_ADJUST					ADJUST_TO_PARENT_CURSOR


#endif /* STYLE_H_ */
