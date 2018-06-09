#include "Window.h"

namespace GUI {
    
    void Window::init(const char* title, int top, int left, int width, int height) {
        initwindow(width, height);
        hWnd = FindWindow(NULL, "Windows BGI");
        SetWindowPos(hWnd, NULL, top, left, width, height, SWP_SHOWWINDOW);
        SetWindowText(hWnd, title);

        // use in release mode only:
        // ShowWindow(GetConsoleWindow(), SW_HIDE);

        // use for debuging:
        // ShowWindow(GetConsoleWindow(), SW_MINIMIZE);

    }
    
    HWND Window::getHWnd() {
        return hWnd;
    }
    
}
