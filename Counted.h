#ifndef COUNTED_H
#define COUNTED_H

namespace GUI {

    class Counted {
    private:
        static int nxt;
    protected:
        int id;
    public:
        Counted();
    };

}

#endif
