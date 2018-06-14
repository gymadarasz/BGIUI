#ifndef SCROLL_H
#define SCROLL_H

#include "Canvas.h"
#include "Button.h"

namespace GUI {
    
    class Scroll: public Canvas {
    protected:
        double value;
//        int minValue;
//        int maxValue;
        int direction;
        Button* minusBtn;
        Button* plusBtn;
        Button* scrollBtn;
        Button* areaBtn;

        virtual int calcWidth();
        virtual int calcHeight();
        
    public:
        Scroll(Canvas* parent = NULL);
        virtual Scroll* setup(
            bool direction = GD_HORIZONTAL,
            double value = 0,
//            int minValue = 0,
//            int maxValue = 255,
            const char* textPlus = "+",
            const char* textMinus = "-",
            int top = GD_AUTOPOSITION,
            int left = GD_AUTOPOSITION,
            int width = GD_AUTOSIZE,
            int height = GD_AUTOSIZE,
            RECT margin = {
                GD_SCROLL_LMARGIN,
                GD_SCROLL_RMARGIN,
                GD_SCROLL_TMARGIN,
                GD_SCROLL_BMARGIN
            },
            RECT padding = {
                GD_SCROLL_LPADDING,
                GD_SCROLL_RPADDING,
                GD_SCROLL_TPADDING,
                GD_SCROLL_BPADDING
            },
            int bgcolor = GD_SCROLL_BGCOLOR,
            int brcolor = GD_SCROLL_BRCOLOR
        );

        virtual bool draw();
        
        virtual void setValue(double value, int left = GD_AUTOPOSITION);
//        virtual void setMinValue(int minValue);
//        virtual void setMaxValue(int maxValue);
        virtual void setDirection(bool direction);
        
        virtual int getValue();
//        virtual int getMinValue();
//        virtual int getMaxValue();
        virtual bool getDirection();
        virtual Button* getScrollButton();
        
    };

//    int onScrollMinusButtonClick(Canvas* areaButton, ...);
//    int onScrollPlusButtonClick(Canvas* areaButton, ...);
//    int onScrollAreaButtonClick(Canvas* areaButton, ...);
    int onScrollAreaButtonClick(Canvas* areaBtn, ...);
    int onScrollAreaButtonMouseUp(Canvas* areaBtn, ...);
    int onScrollAreaButtonMouseLeave(Canvas* areaBtn, ...);

}

#endif
