#include "Button.h"

Button::Button(Graph* graph, int top, int left, int width, int height, int bgcolor, int color, const char* label, int padding): Canvas(graph, top, left, width, height, bgcolor) {
    this->color = color;
    this->label = label;
    this->padding = padding;
    draw();
}

void Button::draw() {
    graph->text(top + padding, left + padding, color, bgcolor, label);
}

void Button::onClick(int x, int y) {
    printf("Button::onClick\n");
}

