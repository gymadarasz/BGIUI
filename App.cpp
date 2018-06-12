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
//    Container App::rootContainer;
    Canvas* App::canvas = NULL;
    //Container App::container; // at (0, 0) by default
    
    App::App(
        const char* title,
        int top,
        int left,
        int width,
        int height,
        int bgcolor
    ) {
        window.init(title, top, left, width, height);
        canvas = (new Canvas())->setup(0, 0, width, height, GD_NOMARGIN, GD_NOPADDING, bgcolor, bgcolor);
    }
    
    void App::init() {
        // override it and add element here...
        (new Label(canvas))->setup("Hello World!");
        
        (new Break(canvas));

        (new Label(canvas))->setup("One");
        (new Label(canvas))->setup("Two");
        (new Label(canvas))->setup("Three");
        (new Label(canvas))->setup("Four");
        
        Canvas* cntr = (new Canvas(canvas))->setup();

        (new Button(cntr))->setup();
        (new Label(cntr))->setup("In container!");
        (new Break(cntr));
        (new Label(cntr))->setup("Hello1!...");
        (new Label(cntr))->setup("Hello2!...");
        (new Label(cntr))->setup("Hello3!...");
        (new Switch(cntr))->setup();
        
        (new Label(canvas))->setup("Next to the container");
        

        Canvas* cntr2 = (new Canvas(canvas))->setup(150, 300, 50, 50);
        //(new Canvas(cntr2))->setup(0, 0, 50, 50, GD_NOMARGIN, GD_NOPADDING, 2, 3);
        (new Label(cntr2))->setup("A");
        (new Label(cntr2))->setup("BB");
        (new Label(cntr2))->setup("CCC");
        (new Label(cntr2))->setup("DD");
        (new Label(cntr2))->setup("EEEEEEE");
        (new Label(cntr2))->setup("F");
        (new Label(cntr2))->setup("GG");
        (new Label(cntr2))->setup("HHH");
        (new Label(cntr2))->setup("IIII");
        (new Label(cntr2))->setup("JJJJJ");
        
    }

    void App::run() {
        while(1) {
            mouse.check();
            canvas->process();
//            canvas->ticks();
//            canvas->draws();
            
//            for (int i=0; i < CONTAINERS; i++) {
//                if (NULL != containers[i]) {
//                    containers[i]->ticks();
//                    containers[i]->draws();
//                }
//            }
            
            delay(0);
        }
    }
    

}
