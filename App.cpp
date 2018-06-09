#include "App.h"

#include "Canvas.h"

namespace GUI {

    App::App(const char* title, int top, int left, int width, int height, int bgcolor) {
        window.init(title, top, left, width, height);
        cleanup();
        canvas = new Canvas(this, top, left, width, height, bgcolor, bgcolor);
    }
    
    void App::run() {
        init();
        while(1) {
            mouse.check();
            ticks();
            delay(1);
        }
    }

    Canvas* App::getCanvas() {
        return canvas;
    }

    Mouse App::getMouse() {
        return mouse;
    }
    
    Window App::getWindow() {
        return window;
    }
    
    Painter App::getPainter() {
        return painter;
    }

    void App::registry(Canvas* canvas) {
        for (int i=0; i < APP_CANVASES; i++) {
            if (NULL == canvases[i]) {
                canvases[i] = canvas;
                break;
            }
        }
    }
    
    // --- protected

    void App::init() {}
    
    //---- private

    void App::cleanup() {
        // clean canvases
        for (int i=0; i < APP_CANVASES; i++) {
            canvases[i] = NULL;
        }
    }

    void App::ticks() {
        // for each canvases..
        for (int i=0; i < APP_CANVASES; i++) {
            if (NULL != canvases[i]) {

                // tick
                canvases[i]->tick();

                // repaint if it's changed..
                if (canvases[i]->isChanged()) {
                    canvases[i]->draw();
                }
            }
        }
    }

}
