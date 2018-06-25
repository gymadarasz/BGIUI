/*
 * Menu.h
 *
 *  Created on: Jun 25, 2018
 *      Author: Gyula
 */

#ifndef GUI_MENU_H_
#define GUI_MENU_H_

#include "Canvas.h"

namespace gui {

class Menu: public Canvas {
public:
	Menu(Canvas* parent = 0, int width = 0, int height = 0);
	virtual ~Menu();
	virtual Canvas* add(const char* txt, bool br = false);
	virtual Canvas* add(char* txt, bool br = false);
};

} /* namespace gui */

#endif /* GUI_MENU_H_ */
