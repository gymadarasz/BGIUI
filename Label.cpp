#include "Label.h"

#include "App.h"

namespace GUI {
    
    Label::Label(Canvas* parent): Canvas(parent) {
        this->text = NULL;
        setup();
    }

    Label* Label::setup(
        const char* text,
        int top,
        int left,
        int width,
        int height,
        RECT margin,
        RECT padding,
        int bgcolor,
        int txcolor,
        int brcolor
    ) {
        Canvas::setup(top, left, width, height, margin, padding, bgcolor, brcolor);
        setText(text);
        setTxColor(txcolor);
        return this;
    }

    bool Label::draw() {
        if(Canvas::draw()) {
            int w = textwidth((char*)getText());
            int h = textheight((char*)getText());
            App::painter.text(getTop() + (getHeight()-h)/2, getLeft() + (getWidth()-w)/2,
                txcolor, getBgColor(), getText());
            return true;
        }
        return false;
    }

    void Label::clearText() {
        int w = textwidth((char*)getText());
        int h = textheight((char*)getText());
        int bgcolor = getBgColor();
        App::painter.text(getTop() + (getHeight()-h)/2, getLeft() + (getWidth()-w)/2,
            bgcolor, bgcolor, getText());
    }
    
    const char* Label::getText() {
        return text;
    }

    void Label::setText(const char* text) {
//        // clear first if text already set because maybe text changes the size
//        if (NULL != getText()) {
//            clearText();
//            if (width == GD_AUTOSIZE || height == GD_AUTOSIZE) {
//                clear();
//            }
//        }
        this->text = text;
        changed = true;
    }
    
    void Label::setTxColor(int txcolor) {
        this->txcolor = txcolor;
        changed = true;
    }

//    void Label::onMouseOver(int x, int y) {}

//    void Label::onMouseLeave(int x, int y) {}

    // ---- protected

    int Label::calcWidth() {
        return textwidth((char*)getText()) + padding.left + padding.right;
    }

    int Label::calcHeight() {
        return textheight((char*)getText()) + padding.left + padding.right;
    }
    
}
