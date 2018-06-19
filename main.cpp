#include <graphics.h>
#include "Window.h"
#include "Canvas.h"

using namespace GUI;

int main(int argc, char** argv) {
    
    Window window;
    window.init("Test app");
    
    Canvas canvas = Canvas();

    getch();
	return 0;
}
