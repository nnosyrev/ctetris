
#ifndef _AREA_H_INCLUDED_
#define _AREA_H_INCLUDED_

#include <SDL3/SDL_render.h>
#include "window.h"
#include "grid.h"

#define SQUARE_WIDTH 30
#define FRAME_WIDTH 1

#define FRAME_COLOR 0x000000

#define COLOR_WHITE 0xFFFFFF
#define COLOR_RED 0xFF0000
#define COLOR_ORANGE 0xFFA500
#define COLOR_YELLOW 0xFFFF00
#define COLOR_GREEN 0x008000
#define COLOR_LIGHTBLUE 0xADD8E6
#define COLOR_BLUE 0x0000FF
#define COLOR_PURPLE 0x800080

typedef struct {
    Window window;
    float x;
    float y;
} Area;

Area Area_Show(Window *window, int x, int y, int color);

void Area_DrawSquare(Area *area, int x, int y, int color);
void Area_ClearSquare(int x, int y);

int Area_getRColor(int color);
int Area_getGColor(int color);
int Area_getBColor(int color);

void Area_DrawShape(Area *area, Shape *shape);

#endif
