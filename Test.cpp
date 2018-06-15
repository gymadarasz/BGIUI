/*
 * GUITests.cpp
 *
 *  Created on: Jun 15, 2018
 *      Author: Gyula
 */

#include "Test.h"

namespace GUI {

Test::Test() {
    runs = 0;
    failed = 0;
    success = 0;
}

Test::~Test() {

}

void Test::run() {
    printf("Nothing to test here..\n");
}


void Test::equ(int a, int b, const char* errmsg) {
    runs++;
    if (a == b) {
        printf(".");
        success++;
    } else {
        printf(errmsg, a, b);
        failed++;
    }
}

void Test::equ(const char* a, const char* b, const char* errmsg) {
    int res = strcmp(a, b);
    runs++;
    if (!res) {
        printf(".");
        success++;
    } else {
        printf(errmsg, res, a, b);
        failed++;
    }
}

int Test::stat() {
    printf("\nRuns: %d, Success: %d, Failed: %d\n", runs, success, failed);
    if (runs == success) {
        printf("All test SUCCESS.\n:)\n");
        return 0;
    } else {
        printf("FAILED tests found. :(\n");
        return 1;
    }
}


} /* namespace GUI */
