#ifndef APP_H
#define APP_H

#include "Graph.h"

namespace GUI {
    
    class Graph;

    class App {
    protected:
        const char* title;
    public:
        App(const char* title);
        virtual void init(Graph* graph);
        void run();
    };

}

#endif
