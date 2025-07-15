#include "window.h"
#include "area.h"

Area_Color GREEN_COLOR = { .r = 0, .g = 128, .b = 0, .alpha = 0xff };

int main(int argc, char* argv[])
{
    Window_Window window = Window_Create("Title", 800, 700);

    Area_Show(window, 10, 10);

    Area_DrawSquare(window, 0, 0, GREEN_COLOR);
    Area_DrawSquare(window, 1, 1, GREEN_COLOR);

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
