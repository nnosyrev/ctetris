#include "ui.h"
#include "grid.h"

#define AREA_X 10
#define AREA_Y 10
#define AREA_COLOR 0xFFFFFF

SDL_Window *window;
SDL_Renderer *renderer;

extern int grid[GRID_WIDTH][GRID_HEIGHT];

bool UI_CreateWindow(char *title, int width, int height)
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return false;
    }

    if (!SDL_CreateWindowAndRenderer(title, width, height, SDL_WINDOW_OPENGL, &window, &renderer)) {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

void UI_DestroyWindow()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool UI_PollEvent(SDL_Event *event)
{
    return SDL_PollEvent(event);
}

int UI_getRColor(int color)
{
    return (color >> 16) & 0xFF;
}

int UI_getGColor(int color)
{
    return (color >> 8) & 0xFF;
}

int UI_getBColor(int color)
{
    return color & 0xFF;
}

void UI_drawSquare(int x, int y, int color)
{
    if (y < 0) {
        return;
    }

    SDL_FRect outer;

    outer.x = x * SQUARE_WIDTH + AREA_X;
    outer.y = y * SQUARE_WIDTH + AREA_Y;
    outer.w = SQUARE_WIDTH;
    outer.h = SQUARE_WIDTH;

    SDL_SetRenderDrawColor(
        renderer, UI_getRColor(FRAME_COLOR), UI_getGColor(FRAME_COLOR), UI_getBColor(FRAME_COLOR), 0xff
    );
    SDL_RenderFillRect(renderer, &outer);

    SDL_FRect inner;

    inner.x = outer.x + FRAME_WIDTH;
    inner.y = outer.y + FRAME_WIDTH;
    inner.w = outer.w - FRAME_WIDTH * 2;
    inner.h = outer.h - FRAME_WIDTH * 2;

    SDL_SetRenderDrawColor(renderer, UI_getRColor(color), UI_getGColor(color), UI_getBColor(color), 0xff);
    SDL_RenderFillRect(renderer, &inner);
}

void UI_clearSquare(int x, int y)
{
    if (y < 0) {
        return;
    }

    SDL_FRect outer;

    outer.x = x * SQUARE_WIDTH + AREA_X;
    outer.y = y * SQUARE_WIDTH + AREA_Y;
    outer.w = SQUARE_WIDTH;
    outer.h = SQUARE_WIDTH;

    SDL_SetRenderDrawColor(
        renderer, UI_getRColor(AREA_COLOR), UI_getGColor(AREA_COLOR), UI_getBColor(AREA_COLOR), 0xff
    );
    SDL_RenderFillRect(renderer, &outer);
}

void UI_Refresh()
{
    //SDL_RenderClear(renderer);

    UI_areaShow();
    UI_gridShow();

    SDL_RenderPresent(renderer);
}

void UI_areaShow()
{
    SDL_FRect rect;

    rect.x = AREA_X;
    rect.y = AREA_Y;
    rect.w = GRID_WIDTH * SQUARE_WIDTH;
    rect.h = GRID_HEIGHT * SQUARE_WIDTH;

    SDL_SetRenderDrawColor(renderer, UI_getRColor(AREA_COLOR), UI_getGColor(AREA_COLOR), UI_getBColor(AREA_COLOR), 0xff);
    SDL_RenderFillRect(renderer, &rect);
}

void UI_gridShow()
{
    for (int8_t y = 0; y < GRID_HEIGHT; y++) {
        for (int8_t x = 0; x < GRID_WIDTH; x++) {
            if (grid[x][y] == 0) {
                UI_clearSquare(x, y);
            } else {
                UI_drawSquare(x, y, grid[x][y]);
            }
        }
    }
}
