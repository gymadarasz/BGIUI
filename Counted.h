/*
 * Counted.h
 *
 *  Created on: Jun 14, 2018
 *      Author: Gyula
 */

#ifndef COUNTED_H_
#define COUNTED_H_

namespace GUI {

class Counted {
	static int next;
	int id;
public:
	Counted();
	int getId();
};

} /* namespace GUI */

#endif /* COUNTED_H_ */
