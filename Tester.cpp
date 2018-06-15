/*
 * Tester.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "Tester.h"

namespace GUI {

Tester::Tester(Test* test) {
    test->run();
    test->stat();
}

} /* namespace GUI */
