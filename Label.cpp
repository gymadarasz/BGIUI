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
            painter.text(getTop() + (getHeight()-h)/2, getLeft() + (getWidth()-w)/2,
                txcolor, getBgColor(), getText());
            return true;
        }
        return false;
    }

    void Label::clearText() {
        int w = textwidth((char*)getText());
        int h = textheight((char*)getText());
        int bgcolor = getBgColor();
        painter.text(getTop() + (getHeight()-h)/2, getLeft() + (getWidth()-w)/2,
            bgcolor, bgcolor, getText());
    }
    
    const char* Label::getText() {
        return text;
    }

    void Label::setText(const char* text) {
        this->text = text;
        setChanged(true);
    }
    
    void Label::setTxColor(int txcolor) {
        this->txcolor = txcolor;
        setChanged(true);
    }
    
    int Label::calcWidth() {
        RECT padding = getPadding();
        return textwidth((char*)getText()) + padding.left + padding.right;
    }

    int Label::calcHeight() {
        RECT padding = getPadding();
        return textheight((char*)getText()) + padding.left + padding.right;
    }
    
}
