#include "window.h"

Window Window_Create(char *title, int width, int height)
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        //return 1;
    }

    Window window;

    if (!SDL_CreateWindowAndRenderer(title, width, height, SDL_WINDOW_OPENGL, &window.window, &window.renderer)) {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        //return 1;
    }

    SDL_RenderClear(window.renderer);

    return window;
}

void Window_Destroy(Window window)
{
    // Close and destroy the window
    SDL_DestroyRenderer(window.renderer);
    SDL_DestroyWindow(window.window);

    // Clean up
    SDL_Quit();
}

bool Window_PollEvent(Window_Event *event)
{
    return SDL_PollEvent(event);
}

