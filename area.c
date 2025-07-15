#include "area.h"
#include "window.h"

Area_Area Area_Show(Window_Window window, int x, int y, Area_Color color)
{
    SDL_FRect rect;

    rect.x = x;
    rect.y = y;
    rect.w = AREA_WIDTH * SQUARE_WIDTH;
    rect.h = AREA_HEIGHT * SQUARE_WIDTH;

    SDL_SetRenderDrawColor(window.renderer, color.r, color.g, color.b, color.alpha);
    SDL_RenderFillRect(window.renderer, &rect);
    SDL_RenderPresent(window.renderer);

    Area_Area area = { .window = window, .x = x, .y = y, .color = color };

    return area;
}

void Area_DrawSquare(Area_Area area, int x, int y, Area_Color color)
{
    SDL_FRect rect;

    rect.x = x * SQUARE_WIDTH + area.x;
    rect.y = y * SQUARE_WIDTH + area.y;
    rect.w = SQUARE_WIDTH;
    rect.h = SQUARE_WIDTH;

    SDL_SetRenderDrawColor(area.window.renderer, color.r, color.g, color.b, color.alpha);
    SDL_RenderFillRect(area.window.renderer, &rect);
    SDL_RenderPresent(area.window.renderer);
}

void Area_ClearSquare(int x, int y)
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

