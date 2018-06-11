#include "App.h"

#include "Canvas.h"
#include "Label.h"
#include "Break.h"
#include "Button.h"
#include "Switch.h"


namespace GUI {
    
    Mouse App::mouse;
    Window App::window;
    Painter App::painter;
    Canvas App::rootCanvas;
    //Container App::container; // at (0, 0) by default
    
    App::App(
        const char* title,
        int top,
        int left,
        int width,
        int height,
        int bgcolor
    ): Container(0, 0, width, height) {
        window.init(title, top, left, width, height);
        rootCanvas.setContainer(this)->setup(0, 0, width, height, GD_NOMARGIN, GD_NOPADDING, bgcolor, bgcolor);
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
        (new Label(this))->setup("Hello World!");
        
        new Break(this);

        (new Label(this))->setup("One");
        (new Label(this))->setup("Two");
        (new Label(this))->setup("Three");
        (new Label(this))->setup("Four");
        
        Container* cntr = addContainer(new Container(40, 40, 200, 100));
        new Button(cntr);
        (new Label(cntr))->setup("In container!");
        (new Label(cntr))->setup("Hello!...");
        (new Label(cntr))->setup("Hello!...");
        (new Label(cntr))->setup("Hello!...");
        new Switch(cntr);
        

        Container* cntr2 = addContainer(new Container(150, 300, 50, 50));
        (new Canvas(cntr2))->setup(0, 0, 50, 50, GD_NOMARGIN, GD_NOPADDING, 2, 3);
        (new Label(cntr2))->setup("AAaaa");
        (new Label(cntr2))->setup("BBbbb");
        (new Label(cntr2))->setup("CCccc");
        (new Label(cntr2))->setup("DDddd");
        (new Label(cntr2))->setup("DDddd");
        
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
            
            delay(0);
        }
    }
    

}
