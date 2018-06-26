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


#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(linux) || defined(__linux) || defined(__linux__)


#elif defined(ARDUINO_AVR_ADK) || defined(TEENSYDUINO)

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

#endif /* DEFS_H_ */
