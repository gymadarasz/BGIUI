#include "Counted.h"

namespace GUI {

    int Counted::nxt = 0;
    
    Counted::Counted() {
        id = nxt++;
    }
    
    int Counted::getId() {
        return id;
    }
    
}
