/*
 * style.h
 *
 *  Created on: Jun 21, 2018
 *      Author: Gyula
 */

#ifndef DEFS_H_
#define DEFS_H_


// more info: https://arduino.stackexchange.com/questions/21137/arduino-how-to-get-the-board-type-in-code

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(_WIN64) || defined(__CYGWIN__) || defined(__MINGW32__)

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

#elif defined(__APPLE__) || defined(__MACH__)

#error "unsupported hardware"

#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(linux) || defined(__linux) || defined(__linux__)

#include <graphics.h>

#elif defined(ARDUINO) || defined(ARDUINO_AVR_ADK) || defined(TEENSYDUINO)

#include <Adafruit_GFX.h>
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define DARKGRAY		0x5555
#define LIGHTGRAY		0xaaaa
#define DEFAULT_FONT	0

#endif



#include "themes/solid.h"	// <- change (or add your custom) theme here..
//#include "themes/matrix.h"
//#include "themes/blue.h"
//#include "themes/clown.h"

#define CANVASES 			64	// increment it if you need more canvases
#define TEXT_BUFFER_SIZE	64	// change it if you need more or less long strings

#define GUI_NONE -1
#define GUI_UNDEFINED -1
#define NOCOLOR -1


//#include "UI/UIKeyboard.h"
//#include "UI/UIMouse.h"
//#include "UI/UIPainter.h"
//#include "Canvas.h"
//#include "Scroll.h"
//#include "Menu.h"

#endif /* DEFS_H_ */
