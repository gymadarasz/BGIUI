#include "Break.h"

#include "App.h"

namespace GUI {
    
    Break::Break(Canvas* parent): Canvas(parent) {
        setup();
    }
    
    Break* Break::setup(int height) {
        Canvas::setup(GD_AUTOPOSITION, GD_AUTOPOSITION, 0, height, GD_NOMARGIN, GD_NOPADDING, GD_NOCOLOR, GD_NOCOLOR);
        setBreak(true);
        return this;
    }
    
}
