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


void Test::equ(int a, int b, const char* msg, const char* errmsg) {
    runs++;
    printf("\nTEST %d: ", runs);
    printf(msg, a, b);
    if (a == b) {
        success++;
    } else {
        printf(errmsg, a, b);
        failed++;
    }
}

void Test::equ(const char* a, const char* b, const char* msg, const char* errmsg) {
    runs++;
    int res = strcmp(a, b);
    printf("\nTEST %d: ", runs);
    printf(msg, res, a, b);
    if (!res) {
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
