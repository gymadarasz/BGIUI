#include "Scroll.h"

#include "Canvas.h"
#include "Break.h"

namespace GUI {

    Scroll::Scroll(Canvas* parent): Canvas(parent) {
       // setup();
    }
    
    Scroll* Scroll::setup(
        bool direction,
        double value,
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
        setDirection(direction);

        minusBtn = (new Button(this))->setup(textMinus);
        
        if (direction == GD_VERTICAL) {
            new Break(this);
        }
        
        areaBtn = (new Button(this))->setup("");
        areaBtn->onMouseUp = onScrollAreaButtonMouseUp;
        areaBtn->onMouseLeave = onScrollAreaButtonMouseLeave;
        areaBtn->onClick = onScrollAreaButtonClick;

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
        
        setValue(value);
        
        return this;
    }

    bool Scroll::draw() {
        return Canvas::draw();
    }

    void Scroll::setValue(double value, int left) {
        if (this->value != value) {
            this->value = value;
            changed = true;
        }
        if (left == GD_AUTOPOSITION) {
            left = value * getWidth();
        }
        scrollBtn->setLeft(left);
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
    
    Button* Scroll::getScrollButton() {
        return scrollBtn;
    }
    

    int onScrollAreaButtonClick(Canvas* areaBtn, ...) {
        va_list args;
        va_start(args, areaBtn);
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        va_end(args);
        
        printf("SCROLL-CLICK:(%d, %d); ", x, y);
        
        Scroll* scroll = (Scroll*)(areaBtn->getParent());
        Button* scrollBtn = scroll->getScrollButton();
        bool direction = scroll->getDirection();
        
        if (direction == GD_HORIZONTAL) {
            int areaBtnWidth = areaBtn->getWidth();
            int scrollBtnLeftRelative = scroll->getLeft() - scrollBtn->getLeft();
            int scrollBtnWidth = scrollBtn->getWidth();
            int _left = x - scrollBtnWidth / 2;
            int _leftMax = areaBtnWidth - scrollBtnLeftRelative;
            
            printf("SCROLL-LEFT-MAX:[%d-%d=%d]; ", areaBtnWidth, scrollBtnLeftRelative, _leftMax);
            
            if (_left > _leftMax) {
                _left = _leftMax;
            }
            if (_left < 0) {
                _left = 0;
            }
            
            double value = _left / _leftMax;

            printf("SCROLL-SET:(value:%d, left:%d)\n", value, _left);
            scroll->setValue(value, _left);
        } else {
            
        }

        areaBtn->setChanged(true);
        scrollBtn->setChanged(true);
        return 0;
    }
    
    int onScrollAreaButtonMouseUp(Canvas* areaBtn, ...) {
        ((Scroll*)(areaBtn->getParent()))->getScrollButton()->setChanged(true);
        return 0;
    }

    int onScrollAreaButtonMouseLeave(Canvas* areaBtn, ...) {
        ((Scroll*)(areaBtn->getParent()))->getScrollButton()->setChanged(true);
        return 0;
    }
}
