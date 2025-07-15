#include <SDL3/SDL_render.h>
#include "window.c"

#define AREA_BLOCK_SIZE 40
#define AREA_GRID_WIDTH 10
#define AREA_GRID_HEIGHT 20

void Area_Show(int x, int y)
{
    SDL_RenderClear(renderer);

    SDL_FRect rect;

    rect.x = 10;
    rect.y = 10;
    rect.w = 100;
    rect.h = 100;

    SDL_SetRenderDrawColor(renderer, 0xfc, 0x0c, 0x0c, 0xff);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
}

void Area_DrawBlock(int x, int y, int color)
{

}

void Area_ClearBlock(int x, int y)
{

}

/*
void Area_DrawShape(int x, int y, int color)
{

}

void Area_ClearShape(int x, int y)
{

}
*/

