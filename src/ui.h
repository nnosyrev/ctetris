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
#define AREA_COLOR 0xFFFFFF
#define WINDOW_COLOR 0x333333

#define COLOR_WHITE 0xFFFFFF
#define COLOR_RED 0xFF0000
#define COLOR_ORANGE 0xFFA500
#define COLOR_YELLOW 0xFFFF00
#define COLOR_GREEN 0x008000
#define COLOR_LIGHTBLUE 0xADD8E6
#define COLOR_BLUE 0x0000FF
#define COLOR_PURPLE 0x800080

#define AREA_X 15
#define AREA_Y 15

typedef struct {
    TTF_Font *font;
    SDL_Color color;
} TextStyle;

bool UI_CreateWindow(char *title, int width, int height);
void UI_DestroyWindow();
bool UI_PollEvent(SDL_Event *event);
int UI_getRColor(int color);
int UI_getGColor(int color);
int UI_getBColor(int color);
void UI_drawSquare(int x, int y, int col, int row, int color);
void UI_clearSquare(int x, int y, int col, int row);
void UI_Refresh(int cleansCount, Shape *shape, int level, bool isGamePause, bool isGameOver);
void UI_areaShow();
void UI_gridShow();
void UI_printText(char *text, float x, float y, TextStyle style);
char *UI_intToStr(int value);
void UI_showShape(Shape *shape, float x, float y);

#endif
