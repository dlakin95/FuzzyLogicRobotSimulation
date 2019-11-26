#ifndef LAYOUTMACROS_HPP
#define LAYOUTMACROS_HPP

// General Layout Macros
#define LAYOUT_WINDOW_X(win) (win->x())
#define LAYOUT_WINDOW_Y(win) (win->y())
#define LAYOUT_WINDOW_POS(win) (win->pos())
#define LAYOUT_WINDOW_WIDTH(win) (win->width())
#define LAYOUT_WINDOW_HEIGHT(win) (win->height())
#define LAYOUT_WINDOW_GEOMETRY(win) (win->geometry())

// Position
#define LAYOUT_WINDOW_TOP(win) (LAYOUT_WINDOW_Y(win))
#define LAYOUT_WINDOW_BOTTOM(win) (LAYOUT_WINDOW_Y(win) + LAYOUT_WINDOW_HEIGHT(win))
#define LAYOUT_WINDOW_LEFT(win) (LAYOUT_WINDOW_X(win))
#define LAYOUT_WINDOW_RIGHT(win) (LAYOUT_WINDOW_X(win) + LAYOUT_WINDOW_WIDTH(win))

#define LAYOUT_CURRENT_TOP (0)
#define LAYOUT_CURRENT_BOTTOM (LAYOUT_WINDOW_HEIGHT(this))
#define LAYOUT_CURRENT_LEFT (0)
#define LAYOUT_CURRENT_RIGHT (LAYOUT_WINDOW_WIDTH(this))

#define LAYOUT_WINDOW_UP_OF(win, move) (LAYOUT_WINDOW_Y(win) - (move))
#define LAYOUT_WINDOW_BOTTOM_OF(win, move) (LAYOUT_WINDOW_Y(win) + LAYOUT_WINDOW_HEIGHT(win) + (bottom))
#define LAYOUT_WINDOW_LEFT_OF(win, move) (LAYOUT_WINDOW_X(win) - (move))
#define LAYOUT_WINDOW_RIGHT_OF(win, move) (LAYOUT_WINDOW_X(win) + LAYOUT_WINDOW_WIDTH(win) + (move))

#define LAYOUT_POS_UP_OF(pos, move) ((pos) - (move))
#define LAYOUT_POS_BOTTOM_OF(pos, move) ((pos) + (move))
#define LAYOUT_POS_LEFT_OF(pos, move) ((pos) - (move))
#define LAYOUT_POS_RIGHT_OF(pos, move) ((pos) + (move))

#define LAYOUT_CURRENT_X (LAYOUT_WINDOW_X(this))
#define LAYOUT_CURRENT_Y (LAYOUT_WINDOW_Y(this))
#define LAYOUT_CURRENT_WIDTH (LAYOUT_WINDOW_WIDTH(this))
#define LAYOUT_CURRENT_HEIGHT (LAYOUT_WINDOW_HEIGHT(this))
#define LAYOUT_CURRENT_POS (LAYOUT_WINDOW_POS(this))
#define LAYOUT_CURRENT_SIZE (LAYOUT_WINDOW_SIZE(this))
#define LAYOUT_CURRENT_GEOMETRY (LAYOUT_WINDOW_GEOMETRY(this))

#define LAYOUT_REST_OF_WIDTH(fullWinWidth, sumOfElementsWidth) ((fullWinWidth) - (sumOfElementsWidth))
#define LAYOUT_REST_OF_HEIGHT(fullWinHeight, sumOfElementsHeight) ((fullWinHeight) - (sumOfElementsHeight))

#endif // LAYOUTMACROS
