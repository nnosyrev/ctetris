#ifndef _WINDOW_H_INCLUDED_
#define _WINDOW_H_INCLUDED_

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_events.h>

typedef SDL_Event Window_Event;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
} Window;

Window Window_Create(char *title, int width, int height);

void Window_Destroy(Window window);

bool Window_PollEvent(Window_Event *event);

#endif
