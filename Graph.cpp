#include "Graph.h"


Graph::Graph(int top, int left, int width, int height, const char* title, int bgcolor, int hbcolor) {
    initwindow(width, height);
    hWnd = FindWindow(NULL, "Windows BGI");
    SetWindowPos(hWnd, NULL, top, left, width, height, SWP_SHOWWINDOW);
    SetWindowText(hWnd, title);
    
    this->bgcolor = bgcolor;
    this->hbcolor = hbcolor;

    // use in release mode only:
    // ShowWindow(GetConsoleWindow(), SW_HIDE);

    // use for debuging:
    // ShowWindow(GetConsoleWindow(), SW_MINIMIZE);

    // clear ticks
    for (int i=0; i < CANVASES; i++) {
        canvases[i] = NULL;
    }
}

void Graph::fillBox(int top, int left, int width, int height, int color) {

    int right = left + width;
    int bottom = top + height;

    fillsettingstype fillinfo;
    getfillsettings(&fillinfo);
    int c = getcolor();

    setfillstyle(1,color);
    setcolor(color);

    rectangle(left, top, right, bottom);
    if (left < right && top < bottom) {
        floodfill(left+1, top+1, color);
    }

    setfillstyle(fillinfo.pattern, fillinfo.color);
    setcolor(c);
}

void Graph::text(int top, int left, int color, int bgcolor, const char* txt) {
    int c = getcolor();
    int b = getbkcolor();
    setcolor(color);
    setbkcolor(bgcolor);
    outtextxy(left, top, (char*)txt);
    setcolor(c);
    setbkcolor(b);
}

void Graph::registry(Canvas* canvas) {
    for (int i=0; i < CANVASES; i++) {
        if (NULL == canvases[i]) {
            canvases[i] = canvas;
            break;
        }
    }
}

void Graph::highlight(Canvas* canvas, bool activate) {
    RECT rect;
    canvas->getRect(&rect);
    
    int c = getcolor();
    setcolor(activate ? hbcolor : bgcolor);
    rectangle(rect.left-1, rect.top-1, rect.right+1, rect.bottom+1);
    setcolor(c);
}

void Graph::tick() {
    int x, y;

    // any mouse click event?
    events.onClick.happend = false;
    if (ismouseclick(WM_LBUTTONDOWN)) {
        getmouseclick(WM_LBUTTONDOWN, x, y);
        events.onClick.happend = true;
        events.onClick.position.x = x;
        events.onClick.position.y = y;
    }
    
    // double click?
    events.onDblClick.happend = false;
    if (ismouseclick(WM_LBUTTONDBLCLK)) {
        getmouseclick(WM_LBUTTONDBLCLK, x, y);
        events.onDblClick.happend = true;
        events.onDblClick.position.x = x;
        events.onDblClick.position.y = y;
    }
    
    // maybe mouse moved?
    events.onMouseMove.happend = false;
    x = mousex();
    y = mousey();
    if (x != lastMouseX || y != lastMouseY) {
        events.onMouseMove.happend = true;
        events.onMouseMove.current.x = x;
        events.onMouseMove.current.y = y;
        events.onMouseMove.previous.x = lastMouseX;
        events.onMouseMove.previous.y = lastMouseY;
        lastMouseX = x;
        lastMouseY = y;
    }
    
    
    
    
    // tick for each component..
    
    for (int i=0; i < CANVASES; i++) {
        if (NULL != canvases[i]) {
            canvases[i]->tick();
        }
    }
}

void Graph::run() {
    while(1) {
        tick();
        delay(1);
    }
}



