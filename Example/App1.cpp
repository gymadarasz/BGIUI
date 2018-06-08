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

void App1::init(Graph* graph) {

    // test initialization

    canvas1 = new Canvas(graph, 10, 10);
    label1 = new Label(graph, 10, 300, "It is only a test app.");
    label2 = new Label(graph, 20, 300, "Override the App::init(Graph* graph) function.");
    label3 = new Label(graph, 30, 300, "See more in the Example folder...");
    button1 = new Button(graph, 10, 150);
    switch1 = new Switch(graph, 40, 150);
    
    clickBtn = new Button1(graph, 100, 150, "Click here!");
    msgLbl = new Label(graph, 100, 300, "<- click on it");

}
