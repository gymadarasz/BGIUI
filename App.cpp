#include "App.h"


namespace GUI {
    
    Mouse App::mouse;
    Window App::window;
    Painter App::painter;
    
    App::App(const char* title, int top, int left, int width, int height, int bgcolor, int txcolor) {
        container = Container(top, left, title, width, height, bgcolor, txcolor, bgcolor);
        window.init(title, top, left, width, height);
    }
    
    void App::init() {
        // override it and add element here...
    }

    void App::run() {
        while(1) {
            mouse.check();
//            container->tick();
//            container->draw();
            delay(1);
        }
    }

//    Canvas* App::getCanvas() {
//        return canvas;
//    }

//    Mouse* App::getMouse() {
//        return mouse;
//    }
//    
//    Window* App::getWindow() {
//        return window;
//    }
//    
//    Painter* App::getPainter() {
//        return painter;
//    }
    

}
