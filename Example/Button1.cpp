#include "Button1.h"

#include "App1.h"

using namespace GUI;

void Button1::onClick(int x, int y) {
    Button::onClick(x, y);
    setText("Clicked!");
    App1::msgLbl->setText("Thanks! :)");
}
