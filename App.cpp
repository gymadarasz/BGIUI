#include "App.h"

#include "Graph.h"
#include "Canvas.h"

namespace GUI {

    App::App(const char* title) {
        this->title = title;
    }

    void App::run() {
        
        Canvas canvas(NULL, 0, 0);
        Graph graph(0, 0, &canvas, title);
        
        init(&graph);

        graph.run();
    }
    
    void App::init(Graph* graph) {}

}
