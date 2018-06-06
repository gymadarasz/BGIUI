#include "Graph.h"


Graph::Graph(int top, int left, int width, int height, const char* title) {
    initwindow(width, height);
    hWnd = FindWindow(NULL, "Windows BGI");
    SetWindowPos(hWnd, NULL, top, left, width, height, SWP_SHOWWINDOW);
    SetWindowText(hWnd, title);

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

void Graph::text(int top, int left, int color, char* txt) {
    int c = getcolor();
    outtextxy(left, top, txt);
    setcolor(c);
}

void Graph::registry(Canvas* canvas) {
    for (int i=0; i < CANVASES; i++) {
        if (NULL == canvases[i]) {
            canvases[i] = canvas;
            break;
        }
    }
}

void Graph::tick() {
    
    // any mouse click event?
    events.onClick.happend = false;
    if(ismouseclick(WM_LBUTTONDOWN)) {
        int x, y;
        getmouseclick(WM_LBUTTONDOWN, x, y);
        events.onClick.happend = true;
        events.onClick.x = x;
        events.onClick.y = y;
    }
    
    
    // tick for each component..
    
    for (int i=0; i < CANVASES; i++) {
        if (NULL != canvases[i]) {
            canvases[i]->tick();
        }
    }
}

