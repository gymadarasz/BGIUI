/*
 * Container.h
 *
 *  Created on: Jun 21, 2018
 *      Author: Gyula
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Canvas.h"

namespace gui {

class Container: public Canvas {
protected:
	virtual void takeOutText();
public:
	Container(Canvas* parent = 0);
	virtual void setTextSize(int size);
};

} /* namespace gui */

#endif /* CONTAINER_H_ */
