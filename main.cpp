//#include "Examples/App1.h"

#include <graphics.h>
#include "style.h"
#include "Canvas.h"
#include "Label.h"
#include "App.h"


using namespace GUI;

int main(int argc, char** argv) {
    
    App app("Test App");
    app.init();
    app.run();

	return 0;
}
