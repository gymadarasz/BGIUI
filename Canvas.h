#ifndef CANVAS_H
#define CANVAS_H

#include <graphics.h>
#include "Counted.h"

namespace GUI {
    
    class Canvas: public Counted {
	public:
	    Canvas(Canvas* parent = NULL);
    };

}

#endif
