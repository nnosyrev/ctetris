#include <SDL3/SDL_timer.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "ui.h"
#include "grid.h"

#define PAUSE_DURATION 1000

Section sections[MAX_SECTIONS];
Shape shape;

unsigned int lastTime = 0, currentTime, pauseTime = 0;

int main(int argc, char* argv[])
{
    if (!UI_CreateWindow("Title", 800, 700)) {
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    shape = Grid_CreateShape();

    Grid_DrawShape(&shape);
    UI_Refresh();

    bool done = false;
    while (!done) {
        SDL_Event event;

        while (UI_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            } else if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.scancode == SDL_SCANCODE_Q) {
                    done = true;
                } else if (event.key.scancode == SDL_SCANCODE_DOWN) {
                    if (Grid_CanMoveDown(&shape)) {
                        Grid_Down(&shape);
                    }
                } else if (event.key.scancode == SDL_SCANCODE_RIGHT) {
                    if (Grid_CanMoveRight(&shape)) {
                        Grid_Right(&shape);
                    }
                } else if (event.key.scancode == SDL_SCANCODE_LEFT) {
                    if (Grid_CanMoveLeft(&shape)) {
                        Grid_Left(&shape);
                    }
                } else if (event.key.scancode == SDL_SCANCODE_UP) {
                    if (Grid_CanTurn(&shape)) {
                        Grid_Turn(&shape);
                    }
                }
            }
        }

        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + 1000) {
            if (Grid_CanMoveDown(&shape)) {
                Grid_Down(&shape);
            }

            lastTime = currentTime;
        }

        if (Grid_IsShapeChanged(&shape)) {
            UI_Refresh();
            if (Grid_LastMoveWasDown(&shape)) {
                lastTime = SDL_GetTicks();
            }
            Grid_MarkAsUpdated(&shape);
        }

        if (!Grid_CanMoveDown(&shape)) {
            if (pauseTime == 0) {
                pauseTime = SDL_GetTicks();
            }

            if (pauseTime != 0 && SDL_GetTicks() > pauseTime + PAUSE_DURATION) {
                Grid_FixShapeToGrid(&shape);

                if (Grid_CheckFullLines()) {
                    Grid_IdentifySections(sections);
                    for (int8_t i = 0; i < MAX_SECTIONS; i++) {
                        Grid_DropPart(&sections[i]);
                        UI_Refresh();
                    }

                    SDL_Delay(PAUSE_DURATION);
                    lastTime = SDL_GetTicks();
                }

                shape = Grid_CreateShape();
                Grid_DrawShape(&shape);
                UI_Refresh();

                pauseTime = 0;
            }
        }
    }

    UI_DestroyWindow();

    return EXIT_SUCCESS;
}
