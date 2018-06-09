#ifndef APP1_H
#define APP1_H

#include "../App.h"
#include "../Canvas.h"
#include "../Label.h"
#include "../Button.h"
#include "../Switch.h"
#include "Button1.h"
#include "../Container.h"

using namespace GUI;

class App1 : public App {
public:
    static Canvas canvas1;
    static Label* label1;
    static Label* label2;
    static Label* label3;
    static Button* button1;
    static Switch* switch1;

    static Button1* clickBtn;
    static Label* msgLbl;
    
    static Container* cntr1;
    
    using App::App;
    virtual void init();
};

#endif
