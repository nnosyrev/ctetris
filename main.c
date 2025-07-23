#include <stdlib.h>
#include "window.h"
#include "area.h"
#include "grid.h"

int main(int argc, char* argv[])
{
    Window window = Window_Create("Title", 800, 700);

    Area area = Area_Show(&window, 10, 10, COLOR_WHITE);

    Shape shape = Grid_CreateShape();

    Area_DrawShape(&area, &shape);

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

    return EXIT_SUCCESS;
}
