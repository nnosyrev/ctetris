#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_log.h>

SDL_Window *window;
SDL_Renderer *renderer;

typedef SDL_Event Window_Event;

void Window_Create(char *title, int width, int height)
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        //return 1;
    }

    if (!SDL_CreateWindowAndRenderer(title, width, height, SDL_WINDOW_OPENGL, &window, &renderer)) {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        //return 1;
    }
}

void Window_Destroy()
{
    // Close and destroy the window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
}

bool Window_PollEvent(Window_Event *event)
{
    return SDL_PollEvent(event);
}

