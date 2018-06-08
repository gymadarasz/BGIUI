#include "App.h"

#include "Graph.h"
#include "Canvas.h"
#include "Button.h"
#include "Switch.h"

App::App(const char* title) {

    Canvas canvas(NULL, 0, 0);
    Graph graph(0, 0, &canvas, title);
    Canvas canvas1(&graph, 10, 10);
    Label label2(&graph, 10, 300);
    Button button3(&graph, 10, 150);
    Switch switch4(&graph, 40, 150);
    
    graph.run();
}


