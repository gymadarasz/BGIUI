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


bool Test::equ(int a, int b, char* msg, char* errmsg) {
	bool ret = false;
    runs++;
    printf("\nTEST %d: ", runs);
    printf(msg, a, b);
    if (a == b) {
        success++;
        ret = true;
    } else {
        printf(errmsg, a, b);
        failed++;
    }
    return ret;
}

bool Test::equ(char* a, char* b, char* msg, char* errmsg) {
    int res = strcmp(a, b);
	bool ret = false;
    runs++;
    printf("\nTEST %d: ", runs);
    printf(msg, res, a, b);
    if (!res) {
        success++;
        ret = true;
    } else {
        printf(errmsg, res, a, b);
        failed++;
    }
    return ret;
}

bool Test::chk(bool expr, char* msg, char* errmsg) {
	bool ret = false;
    runs++;
    printf("\nTEST %d: ", runs);
    printf(msg, expr, true);
    if (expr == true) {
        success++;
        ret = true;
    } else {
        printf(errmsg, expr, true);
        failed++;
    }
    return ret;
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

void Test::snapScr(int xmin, int ymin, int xmax, int ymax, int precision, bool stopView) {
	if (!stopView) {
		return ;
	}
	printf("\n// Snap screen from area [%d, %d - %d, %d; precision:%d]:\n", xmin, ymin, xmax, ymax, precision);
	int i = 0;
	int len = (xmax-xmin) * (ymax-ymin);
	printf("int scrData[%d] = {", len);
	for (int x = xmin; x < xmax; x += precision) {
		printf("\n\t");
		for (int y = ymin; y < ymax; y += precision) {
			if (i > 0) {
				printf(",");
			}
			printf("%d", getpixel(x,y));
			putpixel(x,y,BLACK);
			i += precision;
		}
	}
	printf("\n}; // Snap screen end.\n");
	printf(
		"chk(chkScr(scrData, %d, %d, %d, %d, %d), \"Check screen snap area [%d, %d - %d, %d; precision:%d]\");\n",
		xmin, ymin, xmax, ymax, precision,
		xmin, ymin, xmax, ymax, precision
	);
	getch();
}

bool Test::chkScr(int* scrData, int xmin, int ymin, int xmax, int ymax, int precision) {
	int i = 0;
	for (int x = xmin; x < xmax; x += precision) {
		for (int y = ymin; y < ymax; y += precision) {
			if (getpixel(x, y) != scrData[i]) {
				return false;
			}
			i++;
		}
	}
	return true;
}


} /* namespace GUI */
