
#ifndef _AREA_H_INCLUDED_
#define _AREA_H_INCLUDED_

#include <SDL3/SDL_render.h>
#include "window.h"

#define SQUARE_WIDTH  30
#define AREA_WIDTH 10
#define AREA_HEIGHT 20

typedef struct {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 alpha;
} Area_Color;

void Area_Show(Window_Window window, int x, int y);

void Area_DrawSquare(Window_Window window, int x, int y, Area_Color color);
void Area_ClearSquare(int x, int y);

#endif
