
#ifndef _AREA_H_INCLUDED_
#define _AREA_H_INCLUDED_

#include <SDL3/SDL_render.h>
#include "window.h"

#define SQUARE_WIDTH  30
#define AREA_WIDTH 10
#define AREA_HEIGHT 20
#define FRAME_WIDTH 1

typedef struct {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 alpha;
} Color;

typedef struct {
    Window window;
    float x;
    float y;
    Color color;
} Area;

Area Area_Show(Window window, int x, int y, Color color);

void Area_DrawSquare(Area area, int x, int y, Color color);
void Area_ClearSquare(int x, int y);

#endif
