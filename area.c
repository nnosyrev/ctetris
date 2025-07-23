#include "area.h"
#include "window.h"
#include "grid.h"
#include <SDL3/SDL_render.h>

Area Area_Show(Window *window, int x, int y, int color)
{
    SDL_FRect rect;
    SDL_Renderer *renderer = window->renderer;

    rect.x = x;
    rect.y = y;
    rect.w = GRID_WIDTH * SQUARE_WIDTH;
    rect.h = GRID_HEIGHT * SQUARE_WIDTH;

    SDL_SetRenderDrawColor(renderer, Area_getRColor(color), Area_getGColor(color), Area_getBColor(color), 0xff);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);

    Area area = { .window = *window, .x = x, .y = y };

    return area;
}

void Area_DrawSquare(Area *area, int x, int y, int color)
{
    SDL_FRect outer;
    SDL_Renderer *renderer = area->window.renderer;

    outer.x = x * SQUARE_WIDTH + area->x;
    outer.y = y * SQUARE_WIDTH + area->y;
    outer.w = SQUARE_WIDTH;
    outer.h = SQUARE_WIDTH;

    SDL_SetRenderDrawColor(
        renderer, Area_getRColor(FRAME_COLOR), Area_getGColor(FRAME_COLOR), Area_getBColor(FRAME_COLOR), 0xff
    );
    SDL_RenderFillRect(renderer, &outer);

    SDL_FRect inner;

    inner.x = outer.x + FRAME_WIDTH;
    inner.y = outer.y + FRAME_WIDTH;
    inner.w = outer.w - FRAME_WIDTH * 2;
    inner.h = outer.h - FRAME_WIDTH * 2;

    SDL_SetRenderDrawColor(renderer, Area_getRColor(color), Area_getGColor(color), Area_getBColor(color), 0xff);
    SDL_RenderFillRect(renderer, &inner);

    SDL_RenderPresent(renderer);
}

void Area_ClearSquare(int x, int y)
{

}

void Area_DrawShape(Area *area, Shape *shape)
{
    for (int8_t x = 0; x < SHAPE_WIDTH; x++) {
        for (int8_t y = 0; y < SHAPE_HEIGHT; y++) {
            if (shape->shape[shape->state][x][y] == 1) {
                Area_DrawSquare(area, x, y, shape->color);
            }
        }
    }
}

int Area_getRColor(int color)
{
    return (color >> 16) & 0xFF;
}

int Area_getGColor(int color)
{
    return (color >> 8) & 0xFF;
}

int Area_getBColor(int color)
{
    return color & 0xFF;
}

/*
void Area_DrawShape(int x, int y, int color)
{

}

void Area_ClearShape(int x, int y)
{

}
*/

