#include <SDL3/SDL_scancode.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "window.h"
#include "area.h"
#include "grid.h"

Shape shape;
pthread_t thread;
pthread_mutex_t lock;

void* ticker(void *arg)
{
    while (1) {
        sleep(1);
        pthread_mutex_lock(&lock);
        Grid_Down(&shape);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    Window window = Window_Create("Title", 800, 700);

    Area area = Area_Show(&window, 10, 10, COLOR_WHITE);

    shape = Grid_CreateShape();

    Area_DrawShape(&area, &shape);

    pthread_mutex_init(&lock, NULL);
    pthread_create(&thread, NULL, &ticker, NULL);

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
                    pthread_mutex_lock(&lock);
                    Grid_Down(&shape);
                    pthread_mutex_unlock(&lock);
                } else if (event.key.scancode == SDL_SCANCODE_RIGHT) {
                    pthread_mutex_lock(&lock);
                    Grid_Right(&shape);
                    pthread_mutex_unlock(&lock);
                } else if (event.key.scancode == SDL_SCANCODE_LEFT) {
                    pthread_mutex_lock(&lock);
                    Grid_Left(&shape);
                    pthread_mutex_unlock(&lock);
                } else if (event.key.scancode == SDL_SCANCODE_UP) {
                    pthread_mutex_lock(&lock);
                    Grid_Turn(&shape);
                    pthread_mutex_unlock(&lock);
                }
            }
        }
        //SDL_Log("Внезапно!");

        if (Grid_IsShapeChanged(&shape)) {
            Area_ClearOldShape(&area, &shape);
            Area_DrawShape(&area, &shape);

            Grid_MarkAsUpdated(&shape);
        }
    }

    Window_Destroy(window);

    pthread_mutex_destroy(&lock);
    pthread_cancel(thread);
    pthread_join(thread, NULL);

    return EXIT_SUCCESS;
}
