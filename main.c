#include "window.h"
#include "area.c"

int main(int argc, char* argv[])
{
    Window_Create("Title", 800, 600);

    Area_Show(10, 10);

    bool done = false;
    while (!done) {
        Window_Event event;

        while (Window_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT || event.type == SDL_EVENT_KEY_DOWN) {
                done = true;
            }
        }
    }

    Window_Destroy();

    return 0;
}
