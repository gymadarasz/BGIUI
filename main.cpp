#include "Graph.h"
#include "Canvas.h"
#include "Button.h"
#include "Switch.h"

void test() {
    Canvas canvas(NULL, 0, 0);
    Graph graph(0, 0, &canvas, "BGIUI Test Window");
    Canvas canvas1(&graph, 10, 10);
    Button button2(&graph, 10, 150);
    Switch switch3(&graph, 40, 150);

    graph.run();
}

int main(int argc, char** argv) {
    test();
	return 0;
}
