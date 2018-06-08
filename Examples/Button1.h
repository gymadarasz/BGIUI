#ifndef BUTTON1_H
#define BUTTON1_H

#include "../Button.h"

using namespace GUI;

class Button1: public Button {
public:
    using Button::Button;
    virtual void onClick(int x, int y);
};

#endif
