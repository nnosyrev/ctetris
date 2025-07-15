#include <SDL3/SDL_events.h>

typedef SDL_Event Window_Event;

void Window_Create(char *title, int width, int height);

void Window_Destroy();

bool Window_PollEvent(Window_Event *event);
