#ifndef _UI_H_INCLUDED_
#define _UI_H_INCLUDED_

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_events.h>

#define SQUARE_WIDTH 30
#define FRAME_WIDTH 1

#define FRAME_COLOR 0x000000

void UI_CreateWindow(char *title, int width, int height);
void UI_DestroyWindow();
bool UI_PollEvent(SDL_Event *event);
int UI_getRColor(int color);
int UI_getGColor(int color);
int UI_getBColor(int color);
void UI_drawSquare(int x, int y, int color);
void UI_clearSquare(int x, int y);
void UI_Refresh();
void UI_areaShow();
void UI_gridShow();

#endif
