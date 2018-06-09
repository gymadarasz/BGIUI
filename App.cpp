#include "App.h"

#include "Label.h"

namespace GUI {
    
    Mouse App::mouse;
    Window App::window;
    Painter App::painter;
    Canvas App::rootCanvas;
    //Container App::container; // at (0, 0) by default
    
    App::App(const char* title, int top, int left, int width, int height, int bgcolor): Container() {
        window.init(title, top, left, width, height);
        add(rootCanvas.setup(0, 0, width, height, bgcolor, bgcolor));
    }

    Container* App::addContainer(Container* container) {
        for (int i=0; i < CONTAINERS; i++) {
            if (NULL == containers[i]) {
                containers[i] = container;
                return container;
            }
        }
        return NULL;
    }
    
    void App::init() {
        // override it and add element here...
        add((new Label())->setup(10, 10, "Hello World!"));
        
        Container* cntr = addContainer(new Container(30, 30));
        cntr->add((new Label())->setup(10, 10, "Hello from container!"));
        
    }

    void App::run() {
        while(1) {
            mouse.check();
            ticks();
            draws();
            
            for (int i=0; i < CONTAINERS; i++) {
                if (NULL != containers[i]) {
                    containers[i]->ticks();
                    containers[i]->draws();
                }
            }
            
            delay(1);
        }
    }
    

}
