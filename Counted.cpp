/*
 * Counted.cpp
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#include "Counted.h"

namespace GUI {

int Counted::next = 0;

Counted::Counted() {
	id = ++next;
}

int Counted::getId() {
	return id;
}

} /* namespace GUI */
