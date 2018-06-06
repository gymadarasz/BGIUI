#include "BGIUI.h"


void test() {
    Graph graph1(0, 0, 640, 480, "BGIUI Test Window");
    Canvas canvas1(&graph1, 10, 10, 120, 120);
    Button button1(&graph1, 10, 140);

    graph1.run();
}

int main(int argc, char** argv) {
    test();
	return 0;
}
