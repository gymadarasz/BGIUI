/*
 * Menu.cpp
 *
 *  Created on: Jun 25, 2018
 *      Author: Gyula
 */

#include "Menu.h"

namespace gui {

Menu::Menu(Canvas* parent, int width, int height): Canvas(parent, width, height) {

}

Menu::~Menu() {}

Canvas* Menu::add(const char* txt, bool br) {
	return add((char*)txt, br);
}

Canvas* Menu::add(char* txt, bool br) {
	Canvas* item = new Canvas(this);
	item->setText(txt);
	item->setBreakLine(br);
	return item;
}

} /* namespace gui */
