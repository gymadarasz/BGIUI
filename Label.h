#ifndef LABEL_H
#define LABEL_H

#include "Canvas.h"

namespace GUI {


    class Label: public Canvas {
    protected:
        int txcolor;
        const char* text;
        
        virtual int calcWidth();
        virtual int calcHeight();
        
    public:
        Label(Canvas* parent = NULL);
        virtual Label* setup(
            const char* text = "Label",
            int top = GD_AUTOPOSITION,
            int left = GD_AUTOPOSITION,
            int width = GD_AUTOSIZE,
            int height = GD_AUTOSIZE,
            RECT margin = {
                GD_LBL_LMARGIN,
                GD_LBL_RMARGIN,
                GD_LBL_TMARGIN,
                GD_LBL_BMARGIN
            },
            RECT padding = {
                GD_LBL_LPADDING,
                GD_LBL_RPADDING,
                GD_LBL_TPADDING,
                GD_LBL_BPADDING
            },
            int bgcolor = GD_LBL_BGCOLOR,
            int txcolor = GD_LBL_TXCOLOR,
            int brcolor = GD_LBL_BRCOLOR
        );
        virtual bool draw();
        virtual void clearText();
        virtual const char* getText();
        virtual void setText(const char* text);
        virtual void setTxColor(int txcolor);
//        virtual void onMouseOver(int x, int y);
//        virtual void onMouseLeave(int x, int y);
    };

}

#endif
