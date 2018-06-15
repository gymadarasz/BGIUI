/*
 * GUITests.h
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#ifndef TEST_H_
#define TEST_H_

#include <stdio.h>

#include "Canvas.h"
#include "Window.h"

namespace GUI {

class Test {
protected:
    int runs;
    int failed;
    int success;
public:
    Test();
    virtual ~Test();
    virtual void equ(int a, int b, const char* msg = "OK", const char* errmsg = "\nError (integers are not equals): %d != %d\n");
    virtual void equ(const char* a, const char* b, const char* msg = "OK", const char* errmsg = "\nError (strings are not equals): strcmp() result is %d\nactual:%s\nexpect:%s\n");
    virtual void run();
    virtual int stat();
};

} /* namespace GUI */

#endif /* TEST_H_ */
