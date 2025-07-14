// Example program:
// Using SDL3 to create an application window

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>

int main(int argc, char* argv[]) {

    SDL_Window *window;                    // Declare a pointer
    SDL_Renderer *renderer;                    // Declare a pointer

    bool done = false;

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL3

    /* Create the window */
    if (!SDL_CreateWindowAndRenderer("Hello World", 800, 600, SDL_WINDOW_OPENGL, &window, &renderer)) {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        return 1;
    }

    while (!done) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT || event.type == SDL_EVENT_KEY_DOWN) {
                done = true;
            }
        }

        // Do game logic, present a frame, etc.
        const char *message = "Hello World!";
        int w = 0, h = 0;
        float x, y;
        const float scale = 4.0f;

        /* Center the message and scale it up */
        SDL_GetRenderOutputSize(renderer, &w, &h);
        SDL_SetRenderScale(renderer, scale, scale);
        x = ((w / scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * SDL_strlen(message)) / 2;
        y = ((h / scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE) / 2;

        /* Draw the message */
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDebugText(renderer, x, y, message);
        SDL_RenderPresent(renderer);
    }

    // Close and destroy the window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}
