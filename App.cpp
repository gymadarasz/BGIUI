#include "App.h"

#include "Canvas.h"
#include "Label.h"
#include "Break.h"
#include "Button.h"
#include "Switch.h"
#include "Scroll.h"

int onHelloClick(GUI::Canvas*, ...) {
    printf("Hello\n");
    return 0;
}

namespace GUI {
    
    Window App::window;
    //Canvas* App::canvas = NULL;
    
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
        
        (new Break(canvas))->setup();

        (new Label(canvas))->setup("One");
        (new Label(canvas))->setup("Two");
        (new Label(canvas))->setup("Three");
        (new Label(canvas))->setup("Four");

        (new Break(canvas))->setup();
        
        Canvas* cntr = (new Canvas(canvas))->setup();

        (new Button(cntr))->setup()->onClick = onHelloClick;

        (new Break(cntr))->setup();
        
        (new Label(cntr))->setup("In container!");

        (new Break(cntr))->setup();

        (new Label(cntr))->setup("Hello1!...");
        (new Label(cntr))->setup("Hello2!...");
        (new Label(cntr))->setup("Hello3!...");

        (new Break(cntr))->setup();

        (new Switch(cntr))->setup();
        
        (new Label(canvas))->setup("Next to the container");
        

        Canvas* cntr2 = (new Canvas(canvas))->setup(150, 300, 50, 50);
        (new Canvas(cntr2))->setup(0, 0, 50, 50, GD_NOMARGIN, GD_NOPADDING, 2, 3);
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

        (new Scroll(canvas))->setup(); //GD_HORIZONTAL); //->setWidth(100);
        (new Scroll(canvas))->setup(GD_VERTICAL); //->setWidth(100);
        
        
    }

    void App::run() {
        while(1) {
            Canvas::mouse.check();
            canvas->process();
            
            delay(0);
        }
    }
    

}
