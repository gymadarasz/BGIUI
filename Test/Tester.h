/*
 * Tester.h
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#ifndef TESTER_H_
#define TESTER_H_

#include "Test.h"

namespace test {

class Tester {
public:
    virtual ~Tester();
	virtual int run(Test* test);

};

} /* namespace test */

#endif /* TESTER_H_ */
