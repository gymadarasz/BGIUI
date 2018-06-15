/*
 * Tester.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "Tester.h"

namespace GUI {

int Tester::run(Test* test) {
    test->run();
    return test->stat();
}

} /* namespace GUI */
