#include "Break.h"

#include "App.h"

namespace GUI {
    
    Break::Break(Canvas* parent): Canvas(parent) {
        setup();
    }
    
    Break* Break::setup(int height) {
        int bgcolor = App::canvas->getBgColor();
        Canvas::setup(GD_AUTOPOSITION, GD_AUTOPOSITION, 0, height, GD_NOMARGIN, GD_NOPADDING, bgcolor, bgcolor);
        return this;
    }
    
    int Break::getHeight() {
        return height;
    }
    
    void Break::tick() {
        parent->cursor.nl(height);
    }
    
    bool Break::draw() {
        
        parent->cursor.nl(height);
        return true;
    }
    
    bool Break::isChanged() {
        return true;
    }
    
}
