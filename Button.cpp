#include "Button.h"

Button::Button(Graph* graph, int top, int left, int width, int height, int bgcolor, int color, char* label): Canvas(graph, top, left, width, height, bgcolor) {
    this->color = color;
    this->label = label;
    draw();
}

void Button::draw() {
    graph->text(top, left, color, label);
}

void Button::onClick(int x, int y) {
    printf("Button::onClick\n");
}

