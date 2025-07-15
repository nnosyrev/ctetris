#include "area.h"
#include "window.h"

Color FRAME_COLOR = { .r = 0, .g = 0, .b = 0, .alpha = 0xff };

Area Area_Show(Window window, int x, int y, Color color)
{
    SDL_FRect rect;

    rect.x = x;
    rect.y = y;
    rect.w = AREA_WIDTH * SQUARE_WIDTH;
    rect.h = AREA_HEIGHT * SQUARE_WIDTH;

    SDL_SetRenderDrawColor(window.renderer, color.r, color.g, color.b, color.alpha);
    SDL_RenderFillRect(window.renderer, &rect);
    SDL_RenderPresent(window.renderer);

    Area area = { .window = window, .x = x, .y = y, .color = color };

    return area;
}

void Area_DrawSquare(Area area, int x, int y, Color color)
{
    SDL_FRect outer;

    outer.x = x * SQUARE_WIDTH + area.x;
    outer.y = y * SQUARE_WIDTH + area.y;
    outer.w = SQUARE_WIDTH;
    outer.h = SQUARE_WIDTH;

    SDL_SetRenderDrawColor(area.window.renderer, FRAME_COLOR.r, FRAME_COLOR.g, FRAME_COLOR.b, FRAME_COLOR.alpha);
    SDL_RenderFillRect(area.window.renderer, &outer);

    SDL_FRect inner;

    inner.x = outer.x + FRAME_WIDTH;
    inner.y = outer.y + FRAME_WIDTH;
    inner.w = outer.w - FRAME_WIDTH * 2;
    inner.h = outer.h - FRAME_WIDTH * 2;

    SDL_SetRenderDrawColor(area.window.renderer, color.r, color.g, color.b, color.alpha);
    SDL_RenderFillRect(area.window.renderer, &inner);

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

