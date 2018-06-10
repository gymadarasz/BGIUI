#ifndef COUNTED_H
#define COUNTED_H

namespace GUI {

    class Counted {
    private:
        static int nxt;
        int id;
    public:
        Counted();
        int getId();
    };

}

#endif
