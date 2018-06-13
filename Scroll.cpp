#include "Scroll.h"

#include "Canvas.h"
#include "Break.h"

namespace GUI {

    Scroll::Scroll(Canvas* parent): Canvas(parent) {
       // setup();
    }
    
    Scroll* Scroll::setup(
            bool direction,
            int value,
            int minValue,
            int maxValue,
            const char* textPlus,
            const char* textMinus,
            int top,
            int left,
            int width,
            int height,
            RECT margin,
            RECT padding,
            int bgcolor,
            int brcolor
    ) {
        Canvas::setup(top, left, width, height, margin, padding, bgcolor, brcolor);
        setValue(value);
        setMinValue(minValue);
        setMaxValue(maxValue);
        setDirection(direction);

        minusBtn = (new Button(this))->setup(textMinus);
//        minusBtn->on(ON_CLICK, onMinusClick);
        
        if (direction == GD_VERTICAL) {
            new Break(this);
        }
        
        areaBtn = (new Button(this))->setup("");
        scrollBtn = (new Button(areaBtn))->setup(" ");
        plusBtn = (new Button(this))->setup(textPlus);

        setBgColor(bgcolor);
        areaBtn->setBgColor(bgcolor);
        
        if (direction == GD_HORIZONTAL) {
            plusBtn->setTop(0);
            plusBtn->setLeft(this->getFullWidth() - plusBtn->getFullWidth());
            areaBtn->setWidth(this->getFullWidth() - minusBtn->getFullWidth() - plusBtn->getFullWidth());
            areaBtn->setHeight(this->getHeight());
        } else {
            plusBtn->setLeft(0);
            plusBtn->setTop(this->getFullHeight() - plusBtn->getFullHeight());
            areaBtn->setHeight(this->getFullHeight() - minusBtn->getFullHeight() - plusBtn->getFullHeight());
            areaBtn->setWidth(this->getWidth());
        }
        
        return this;
    }

    bool Scroll::draw() {
        return Canvas::draw();
    }

    void Scroll::setValue(int value) {
        if (this->value != value) {
            this->value = value;
            changed = true;
        }
    }

    void Scroll::setMinValue(int minValue) {
        if (this->minValue != minValue) {
            this->minValue = minValue;
            changed = true;
        }
    }

    void Scroll::setMaxValue(int maxValue) {
        if (this->maxValue != maxValue) {
            this->maxValue = maxValue;
            changed = true;
        }
    }
    
    void Scroll::setDirection(bool direction) {
        if (this->direction != direction) {
            this->direction = direction;
            changed = true;
        }
    }


    bool Scroll::getDirection() {
        return direction;
    }

    int Scroll::getValue() {
        return value;
    }

    int Scroll::getMinValue() {
        return minValue;
    }

    int Scroll::getMaxValue() {
        return maxValue;
    }

    // ---

    int Scroll::calcWidth() {
        int w = width;
        if (w == GD_AUTOSIZE) {
            if(direction == GD_HORIZONTAL) {
                w = GD_SCROLL_DEFAULT_SIZE;
            } else {
                w = minusBtn->getWidth() > plusBtn->getWidth() ? minusBtn->getWidth() : plusBtn->getWidth();
            }
        }
        return w;
    }

    int Scroll::calcHeight() {
        int h = height;
        if (h == GD_AUTOSIZE) {
            if(direction == GD_VERTICAL) {
                h = GD_SCROLL_DEFAULT_SIZE;
            } else {
                h = minusBtn->getHeight() > plusBtn->getHeight() ? minusBtn->getHeight() : plusBtn->getHeight();
            }
        }
        return h;
    }

}
