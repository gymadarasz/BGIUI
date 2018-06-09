#include "App1.h"

//#include "Button1.h"

using namespace GUI;

App1::App1(const char* title): App(title) {};

Canvas* App1::canvas1 = NULL;
Label* App1::label1 = NULL;
Label* App1::label2 = NULL;
Label* App1::label3 = NULL;
Button* App1::button1 = NULL;
Switch* App1::switch1 = NULL;

Button1* App1::clickBtn = NULL;
Label* App1::msgLbl = NULL;

void App1::init() {

    // test initialization

    canvas1 = new Canvas(this, 10, 10);
    label1 = new Label(this, 10, 300, "It is only a test app.");
    label2 = new Label(this, 20, 300, "Override the App::init(Graph* graph) function.");
    label3 = new Label(this, 30, 300, "See more in the Example folder...");
    button1 = new Button(this, 10, 150);
    switch1 = new Switch(this, 40, 150);
    
    clickBtn = new Button1(this, 100, 150, "Click here!");
    msgLbl = new Label(this, 100, 300, "<- click on it");
    

}
