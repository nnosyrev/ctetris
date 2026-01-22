#ifndef _UI_H_INCLUDED_
#define _UI_H_INCLUDED_

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_events.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "grid.h"

#define SQUARE_WIDTH 30
#define FRAME_WIDTH 1

#define FRAME_COLOR 0x000000

bool UI_CreateWindow(char *title, int width, int height);
void UI_DestroyWindow();
bool UI_PollEvent(SDL_Event *event);
int UI_getRColor(int color);
int UI_getGColor(int color);
int UI_getBColor(int color);
void UI_drawSquare(int x, int y, int col, int row, int color);
void UI_clearSquare(int x, int y, int col, int row);
void UI_Refresh(int cleansCount, Shape *shape, int level);
void UI_areaShow();
void UI_gridShow();
void UI_printText(char *text, float x, float y);
char *UI_intToStr(int value);
void UI_showShape(Shape *shape, float x, float y);

#endif
