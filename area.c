#include "area.h"

void Area_Show(Window_Window window, int x, int y)
{
    SDL_RenderClear(window.renderer);

    SDL_FRect rect;

    rect.x = 10;
    rect.y = 10;
    rect.w = 100;
    rect.h = 100;

    SDL_SetRenderDrawColor(window.renderer, 0xfc, 0x0c, 0x0c, 0xff);
    SDL_RenderFillRect(window.renderer, &rect);
    SDL_RenderPresent(window.renderer);
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

