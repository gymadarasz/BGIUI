#ifndef STYLE_H
#define STYLE_H

// --------- STYLE DEFINITIONS DEFAULTS --------------

// common
#define GD_AUTOSIZE         -1
#define GD_AUTOPOSITION     -1
#define GD_NOMARGIN         {0, 0, 0, 0}
#define GD_NOPADDING        {0, 0, 0, 0}

#define GD_WMARGIN          0
#define GD_HMARGIN          0
#define GD_WPADDING         10
#define GD_HPADDING         5
#define GD_BGCOLOR          DARKGRAY
#define GD_TXCOLOR          BLACK
#define GD_HLBRCOLOR        WHITE       // highlighted border color on mouse over
#define GD_PSBGCOLOR        DARKGRAY    // pushed background color on mouse pushed

// window
#define GD_WIN_BGCOLOR          GD_BGCOLOR
#define GD_WIN_DEFAULT_TOP      0
#define GD_WIN_DEFAULT_LEFT     0
#define GD_WIN_DEFAULT_WIDTH    800
#define GD_WIN_DEFAULT_HEIGHT   600

// containers
#define GD_CNTR_BGCOLOR     BLUE //GD_WIN_BGCOLOR
#define GD_CNTR_TXCOLOR     GD_TXCOLOR
#define GD_CNTR_BRCOLOR     GD_WIN_BGCOLOR
#define GD_CNTR_TEXT        ""

// break
#define GD_BREAK_HEIGHT     0   // min line height

// canvas
#define GD_CANVAS_WIDTH     128
#define GD_CANVAS_HEIGHT    160
#define GD_CANVAS_LMARGIN   GD_WMARGIN
#define GD_CANVAS_RMARGIN   GD_WMARGIN
#define GD_CANVAS_TMARGIN   GD_HMARGIN
#define GD_CANVAS_BMARGIN   GD_HMARGIN
#define GD_CANVAS_LPADDING  GD_WPADDING
#define GD_CANVAS_RPADDING  GD_WPADDING
#define GD_CANVAS_TPADDING  GD_HPADDING
#define GD_CANVAS_BPADDING  GD_HPADDING
#define GD_CANVAS_BGCOLOR   BLACK
#define GD_CANVAS_BRCOLOR   DARKGRAY

// label

#define GD_LBL_LMARGIN      GD_WMARGIN
#define GD_LBL_RMARGIN      GD_WMARGIN
#define GD_LBL_TMARGIN      GD_HMARGIN
#define GD_LBL_BMARGIN      GD_HMARGIN
#define GD_LBL_LPADDING     1
#define GD_LBL_RPADDING     1
#define GD_LBL_TPADDING     1
#define GD_LBL_BPADDING     1
#define GD_LBL_BGCOLOR      GD_WIN_BGCOLOR
#define GD_LBL_TXCOLOR      GD_TXCOLOR
#define GD_LBL_BRCOLOR      GD_WIN_BGCOLOR
//#define GD_LBL_TEXT         "Label"
//#define GD_LBL_WPADDING     1
//#define GD_LBL_HPADDING     0

// buttons

#define GD_BTN_LMARGIN      GD_WMARGIN
#define GD_BTN_RMARGIN      GD_WMARGIN
#define GD_BTN_TMARGIN      GD_HMARGIN
#define GD_BTN_BMARGIN      GD_HMARGIN
#define GD_BTN_LPADDING     GD_WPADDING
#define GD_BTN_RPADDING     GD_WPADDING
#define GD_BTN_TPADDING     GD_HPADDING
#define GD_BTN_BPADDING     GD_HPADDING
#define GD_BTN_BGCOLOR      LIGHTGRAY
#define GD_BTN_TXCOLOR      GD_LBL_TXCOLOR
#define GD_BTN_BRCOLOR      LIGHTGRAY
//#define GD_BTN_TEXT         "Button"
//#define GD_BTN_WPADDING     GD_WPADDING
//#define GD_BTN_HPADDING     GD_HPADDING

#define GD_SWITCH_BGCOLOR   GD_BTN_BGCOLOR
#define GD_SWITCH_TXCOLOR   GD_BTN_TXCOLOR
#define GD_SWITCH_BRCOLOR   GD_BTN_BRCOLOR
#define GD_SWITCH_OFF_TEXT  "Off"
#define GD_SWITCH_ON_TEXT   "On"
//#define GD_SWITCH_OFF_TEXT  "_/_"
//#define GD_SWITCH_ON_TEXT   "___"

// ----------------------------------------------------

#endif
