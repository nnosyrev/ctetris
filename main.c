#include "window.h"
#include "area.h"

int main(int argc, char* argv[])
{
    Window_Window window = Window_Create("Title", 800, 600);

    Area_Show(window, 10, 10);

    bool done = false;
    while (!done) {
        Window_Event event;

        while (Window_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT || event.type == SDL_EVENT_KEY_DOWN) {
                done = true;
            }
        }
    }

    Window_Destroy(window);

    return 0;
}
