#ifndef CONTAINER_H
#define CONTAINER_H

#include "Label.h"

#define CANVASES 100

namespace GUI {
    
    class Label;
    
    class Container: public Label {
    protected:
        Canvas* canvases[CANVASES];
    public:
        Container(int top, int left, const char* text = GD_CNTR_TEXT,
            int width = GD_AUTO, int height = GD_AUTO,
            int bgcolor = GD_CNTR_BGCOLOR, int txcolor = GD_CNTR_TXCOLOR, int brcolor = GD_CNTR_BRCOLOR);
        virtual void cleanup();
        void add(Canvas* canvas);
        virtual void tick();
        virtual bool draw();
    };

}

#endif
