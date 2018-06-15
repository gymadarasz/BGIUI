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
};

} /* namespace GUI */

#endif /* PAINTER_H_ */
