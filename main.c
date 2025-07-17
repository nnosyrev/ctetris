#include "window.h"
#include "area.h"

int main(int argc, char* argv[])
{
    Window window = Window_Create("Title", 800, 700);

    Area area = Area_Show(window, 10, 10, COLOR_WHITE);

    Area_DrawSquare(area, 0, 0, COLOR_GREEN);
    Area_DrawSquare(area, 1, 1, COLOR_GREEN);
    Area_DrawSquare(area, 1, 2, COLOR_RED);
    Area_DrawSquare(area, 1, 3, COLOR_ORANGE);
    Area_DrawSquare(area, 1, 4, COLOR_YELLOW);
    Area_DrawSquare(area, 1, 5, COLOR_GREEN);
    Area_DrawSquare(area, 1, 6, COLOR_LIGHTBLUE);
    Area_DrawSquare(area, 1, 7, COLOR_BLUE);
    Area_DrawSquare(area, 1, 8, COLOR_PURPLE);

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
