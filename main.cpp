#include "Graph.h"
#include "Canvas.h"
#include "Button.h"


void test() {
    Graph graph1(0, 0, 640, 480, "BGIUI Test Window");
    Canvas canvas1(&graph1, 10, 10, 120, 120);
    Button button1(&graph1, 10, 140);

    graph1.run();
}

int main(int argc, char** argv) {
    test();
//    Graph g1(0, 0, 640, 480, "Test graphics window");
//    Canvas c1(&g1, 10, 10, 120, 120, 8);
//    Button b1(&g1, 10, 130, 50, 20, 8, 15, "myButton");
//    while(1) {
//        g1.tick();
//        delay(1);
//    }
    //rectangle(10,10,100,100);
//    getch();
	return 0;
}
