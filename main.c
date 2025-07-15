#include "window.h"
#include "area.h"

int main(int argc, char* argv[])
{
    Window_Window window = Window_Create("Title", 800, 700);

    Area_Show(window, 10, 10);

    Area_Color color = { .r = 0, .g = 0, .b = 0, .alpha = 0xff };

    Area_DrawBlock(window, 0, 0, color);
    Area_DrawBlock(window, 1, 1, color);

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
