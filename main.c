#include <SDL3/SDL_timer.h>
#include <stdlib.h>
#include "window.h"
#include "area.h"
#include "grid.h"

Section sections[MAX_SECTIONS];
Shape shape;

unsigned int lastTime = 0, currentTime;

int main(int argc, char* argv[])
{
    Window window = Window_Create("Title", 800, 700);

    Area area = Area_Show(&window, 10, 10, COLOR_WHITE);

    shape = Grid_CreateShape();

    Area_DrawShape(&area, &shape);

    bool done = false;
    while (!done) {
        Window_Event event;

        while (Window_PollEvent(&event)) {
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
            Area_ClearOldShape(&area, &shape);
            Area_DrawShape(&area, &shape);

            Grid_MarkAsUpdated(&shape);

            if (!Grid_CanMoveDown(&shape)) {
                Grid_FixShapeToGrid(&shape);

                if (Grid_CheckFullLines()) {
                    Grid_IdentifySections(sections);
                    for (int8_t i = 0; i < MAX_SECTIONS; i++) {
                        Area_ClearSection(&area, &sections[i]);
                        Grid_DropPart(&sections[i]);
                        Area_DropPart(&area, &sections[i]);
                    }
                }

                shape = Grid_CreateShape();
            }
        }
    }

    Window_Destroy(window);

    return EXIT_SUCCESS;
}
