// Example program:
// Using SDL3 to create an application window

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>

int main(int argc, char* argv[]) {

    SDL_Window *window;                    // Declare a pointer
    SDL_Renderer *renderer;                    // Declare a pointer

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return 1;
    }

    /* Create the window */
    if (!SDL_CreateWindowAndRenderer("Hello World", 800, 600, SDL_WINDOW_OPENGL, &window, &renderer)) {
        SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
        return 1;
    }

    /*
    const char *message = "Hello World!";
    int w = 0, h = 0;
    float x, y;
    const float scale = 4.0f;

    SDL_GetRenderOutputSize(renderer, &w, &h);
    SDL_SetRenderScale(renderer, scale, scale);
    x = ((w / scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * SDL_strlen(message)) / 2;
    y = ((h / scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE) / 2;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDebugText(renderer, x, y, message);
    SDL_RenderPresent(renderer);
    */




    /* Lines (line segments, really) are drawn in terms of points: a set of
       X and Y coordinates, one set for each end of the line.
       (0, 0) is the top left of the window, and larger numbers go down
       and to the right. This isn't how geometry works, but this is pretty
       standard in 2D graphics. */
    static const SDL_FPoint line_points[] = {
        { 100, 354 }, { 220, 230 }, { 140, 230 }, { 320, 100 }, { 500, 230 },
        { 420, 230 }, { 540, 354 }, { 400, 354 }, { 100, 354 }
    };

    /* as you can see from this, rendering draws over whatever was drawn before it. */
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, SDL_ALPHA_OPAQUE);  /* grey, full alpha */
    SDL_RenderClear(renderer);  /* start with a blank canvas. */

    /* You can draw lines, one at a time, like these brown ones... */
    SDL_SetRenderDrawColor(renderer, 127, 49, 32, SDL_ALPHA_OPAQUE);
    SDL_RenderLine(renderer, 240, 450, 400, 450);
    SDL_RenderLine(renderer, 240, 356, 400, 356);
    SDL_RenderLine(renderer, 240, 356, 240, 450);
    SDL_RenderLine(renderer, 400, 356, 400, 450);

    /* You can also draw a series of connected lines in a single batch... */
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderLines(renderer, line_points, SDL_arraysize(line_points));

    /* here's a bunch of lines drawn out from a center point in a circle. */
    /* we randomize the color of each line, so it functions as animation. */
    int i;
    for (i = 0; i < 360; i++) {
        const float size = 30.0f;
        const float x = 320.0f;
        const float y = 95.0f - (size / 2.0f);
        SDL_SetRenderDrawColor(renderer, SDL_rand(256), SDL_rand(256), SDL_rand(256), SDL_ALPHA_OPAQUE);
        SDL_RenderLine(renderer, x, y, x + SDL_sinf((float) i) * size, y + SDL_cosf((float) i) * size);
    }

    SDL_RenderPresent(renderer);  /* put it all on the screen! */



    bool done = false;
    while (!done) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT || event.type == SDL_EVENT_KEY_DOWN) {
                done = true;
            }
        }
    }

    // Close and destroy the window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}
