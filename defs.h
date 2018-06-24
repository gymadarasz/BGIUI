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

#define CANVASES 			48	// increment it if you need more canvases
#define TEXT_BUFFER_SIZE	48	// change it if you need more or less long strings

#define GUI_NONE -1
#define GUI_UNDEFINED -1
#define NOCOLOR -1

//
#define MARGIN_SIZE_HORIZONTAL		4
#define MARGIN_SIZE_VERTICAL		4

#define BORDER_SIZE					1
#define BORDER_COLOR				DARKGRAY
#define BORDER_COLOR_PUSHED			DARKGRAY
#define BORDER_COLOR_SELECTED		WHITE
#define BORDER_COLOR_DISABLED		DARKGRAY
#define BORDER_COLOR_PUSHED			DARKGRAY

#define PADDING_SIZE_HORIZONTAL		12
#define PADDING_SIZE_VERTICAL		4

#define COLOR						LIGHTGRAY
#define COLOR_PUSHED				DARKGRAY
#define COLOR_SELECTED				LIGHTGRAY

#define TEXT_SIZE					1
#define TEXT_COLOR					BLACK
#define TEXT_COLOR_PUSHED			BLACK
#define TEXT_COLOR_SELECTED			BLACK
#define TEXT_COLOR_DISABLED			DARKGRAY

#define BOX_COLOR					LIGHTGRAY
#define BOX_COLOR_PUSHED			DARKGRAY
#define BOX_COLOR_SELECTED			LIGHTGRAY
#define BOX_COLOR_DISABLED			LIGHTGRAY


#endif /* STYLE_H_ */
