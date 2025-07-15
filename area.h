
#ifndef _AREA_H_INCLUDED_
#define _AREA_H_INCLUDED_

#include <SDL3/SDL_render.h>
#include "window.h"

void Area_Show(Window_Window window, int x, int y);

void Area_DrawBlock(int x, int y, int color);

void Area_ClearBlock(int x, int y);

#endif
