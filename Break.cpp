#include "Break.h"

#include "App.h"

namespace GUI {
    
    Break::Break(Container* container): Canvas(container) {
        setup();
    }
    
    Break* Break::setup(int height) {
        Canvas::setup(GD_AUTOPOSITION, GD_AUTOPOSITION, 0, height, GD_NOMARGIN, GD_NOPADDING, App::rootCanvas.getBgColor(), App::rootCanvas.getBgColor());
        return this;
    }
    
    int Break::getHeight() {
        return height;
    }
    
    void Break::tick() {
        container->breakCursor(height);
    }
    
    bool Break::draw() {
        
        container->breakCursor(height);
        return true;
    }
    
    bool Break::isChanged() {
        return true;
    }
    
}
