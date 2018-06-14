#ifndef BREAK_H
#define BREAK_H

#include "Canvas.h"

namespace GUI {
    
    class Break: public Canvas {
    public:
        Break(Canvas* parent = NULL);
        virtual Break* setup(int height = GD_BREAK_HEIGHT);
    };

}
#endif
