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
    virtual bool equ(int a, int b, const char* msg = "Check if integers are equals..", const char* errmsg = "\nError (integers are not equals): %d != %d\n");
    virtual bool equ(const char* a, const char* b, const char* msg = "Check if strings are equals..", const char* errmsg = "\nError (strings are not equals): strcmp() result is %d\nactual:%s\nexpect:%s\n");
    virtual bool chk(bool expr, const char* msg = "Check if boolean or expression is true..", const char* errmsg = "\nError (expression as boolean is not true): %d != %d\n");
    virtual void run();
    virtual int stat();
    virtual void snapScr(int xmin, int ymin, int xmax, int ymax, int precision, bool stopView = true);
    virtual bool chkScr(int* scrData, int xmin, int ymin, int xmax, int ymax, int precision);
};

} /* namespace GUI */

#endif /* TEST_H_ */
