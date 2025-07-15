#include "window.h"
#include "area.h"

Area_Color GREEN_COLOR = { .r = 0, .g = 128, .b = 0, .alpha = 0xff };
Area_Color WHITE_COLOR = { .r = 255, .g = 255, .b = 255, .alpha = 0xff };

int main(int argc, char* argv[])
{
    Window_Window window = Window_Create("Title", 800, 700);

    Area_Area area = Area_Show(window, 10, 10, WHITE_COLOR);

    Area_DrawSquare(area, 0, 0, GREEN_COLOR);
    Area_DrawSquare(area, 1, 1, GREEN_COLOR);

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
