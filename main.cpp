#include "Graph.h"
#include "Canvas.h"
#include "Button.h"

int main(int argc, char** argv) {
    Graph g1(0, 0, 640, 480, "Test graphics window");
    Canvas c1(&g1, 10, 10, 120, 120, 8);
    Button b1(&g1, 10, 130, 50, 20, 8, 15, "myButton");
    while(1) {
        g1.tick();
        delay(1);
    }
    //rectangle(10,10,100,100);
    getch();
	return 0;
}
