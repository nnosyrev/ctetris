#include "area.h"
#include "window.h"

void Area_Show(Window_Window window, int x, int y)
{
    SDL_FRect rect;

    rect.x = x;
    rect.y = y;
    rect.w = AREA_WIDTH * SQUARE_WIDTH;
    rect.h = AREA_HEIGHT * SQUARE_WIDTH;

    SDL_SetRenderDrawColor(window.renderer, 0xfc, 0x0c, 0x0c, 0xff);
    SDL_RenderFillRect(window.renderer, &rect);
    SDL_RenderPresent(window.renderer);
}

void Area_DrawBlock(Window_Window window, int x, int y, Area_Color color)
{
    SDL_FRect rect;

    rect.x = x * SQUARE_WIDTH /* Добавить смещение начала Area */ + 10;
    rect.y = y * SQUARE_WIDTH /* Добавить смещение начала Area */ + 10;
    rect.w = SQUARE_WIDTH;
    rect.h = SQUARE_WIDTH;

    SDL_SetRenderDrawColor(window.renderer, color.r, color.g, color.b, color.alpha);
    SDL_RenderFillRect(window.renderer, &rect);
    SDL_RenderPresent(window.renderer);
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

