#ifndef BREAK_H
#define BREAK_H

#include "Canvas.h"

namespace GUI {
    
    class Break: public Canvas {
    protected:
        bool isChanged();
    public:
        Break(Canvas* parent = NULL);
        virtual Break* setup(int height = GD_BREAK_HEIGHT);
        virtual void tick();
        virtual bool draw();
        virtual int getHeight();
    };

}
#endif
