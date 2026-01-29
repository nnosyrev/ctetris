#include <SDL3/SDL_timer.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ui.h"
#include "grid.h"

#define INIT_PAUSE_DURATION 1000
#define LEVEL_THRESHOLD 20 // Каждые LEVEL_THRESHOLD очищенных строк увеличиваем level
#define PAUSE_REDUCING 50 // Каждый level уменьшаем паузу на PAUSE_REDUCING

Shape shape, nextShape;

int lastTime, currentTime, pauseTime;
int level;
int cleansCount;
int pauseDuration;

bool gamePause, gameOver;

int calculateLevel(int cleansCount)
{
    return (int) floor(cleansCount / LEVEL_THRESHOLD);
}

int calculatePauseDuration(int level)
{
    return INIT_PAUSE_DURATION - (level * PAUSE_REDUCING);
}

int main(int argc, char* argv[])
{
    if (!UI_CreateWindow("Title", 510, 700)) {
        return EXIT_FAILURE;
    }

    srand(time(NULL));

start:

    currentTime = SDL_GetTicks();
    lastTime = currentTime;
    pauseTime = 0;
    level = 0;
    cleansCount = 0;
    pauseDuration = INIT_PAUSE_DURATION;
    gamePause = false;
    gameOver = false;

    Grid_Init();

    shape = Grid_CreateShape();
    nextShape = Grid_CreateShape();

    Grid_DrawShape(&shape);
    UI_Refresh(cleansCount, &nextShape, level, gamePause, gameOver);

    bool done = false;
    while (!done) {
        SDL_Event event;

        while (UI_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            } else if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.scancode == SDL_SCANCODE_Q) {
                    // Exit
                    done = true;
                } else if (event.key.scancode == SDL_SCANCODE_P) {
                    // Pause
                    if (gamePause == true) {
                        gamePause = false;
                    } else {
                        gamePause = true;
                        UI_Refresh(cleansCount, &nextShape, level, gamePause, gameOver);
                    }
                } else if (event.key.scancode == SDL_SCANCODE_R) {
                    // Restart
                    goto start;
                } else if (gamePause == false && gameOver == false) {
                    if (event.key.scancode == SDL_SCANCODE_DOWN) {
                        if (Grid_CanMoveDown(&shape)) {
                            Grid_Down(&shape);
                            lastTime = SDL_GetTicks();
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
                    } else if (event.key.scancode == SDL_SCANCODE_SPACE) {
                        while (Grid_CanMoveDown(&shape)) {
                            Grid_Down(&shape);
                        }
                    }
                }
            }
        }

        currentTime = SDL_GetTicks();
        if (gamePause == false && gameOver == false && currentTime > lastTime + pauseDuration) {
            if (Grid_CanMoveDown(&shape)) {
                Grid_Down(&shape);
            }

            lastTime = currentTime;
        }

        if (Grid_IsShapeChanged(&shape)) {
            UI_Refresh(cleansCount, &nextShape, level, gamePause, gameOver);
            Grid_MarkAsUpdated(&shape);
        }

        if (!Grid_CanMoveDown(&shape)) {
            if (pauseTime == 0) {
                pauseTime = SDL_GetTicks();
            }

            if (pauseTime != 0 && SDL_GetTicks() > pauseTime + pauseDuration) {
                if (Grid_CheckFullRows()) {
                    cleansCount += Grid_DeleteFullRows();

                    level = calculateLevel(cleansCount);
                    pauseDuration = calculatePauseDuration(level);

                    lastTime = SDL_GetTicks();
                }

                shape = nextShape;
                nextShape = Grid_CreateShape();

                Grid_DrawShape(&shape);
                UI_Refresh(cleansCount, &nextShape, level, gamePause, gameOver);

                pauseTime = 0;
            }
        }
    }

    UI_DestroyWindow();

    return EXIT_SUCCESS;
}
