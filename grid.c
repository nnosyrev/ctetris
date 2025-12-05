#include "area.h"
#include "stdbool.h"
#include "grid.h"
#include <stdlib.h>

int grid[GRID_WIDTH][GRID_HEIGHT] = { 0 };

int SHAPES[7][4][4][4] = { SHAPE1, SHAPE2, SHAPE3, SHAPE4, SHAPE5, SHAPE6, SHAPE7 };

int COLORS[] = { COLOR_RED, COLOR_ORANGE, COLOR_YELLOW, COLOR_GREEN, COLOR_LIGHTBLUE, COLOR_BLUE, COLOR_PURPLE };

void Grid_Turn(Shape *shape)
{
    shape->oldState = shape->state;
    shape->state = (shape->state + 1) % 4;
}

void Grid_Down(Shape *shape)
{
    shape->oldy = shape->y;
    shape->y = shape->y + 1;
}

void Grid_Right(Shape *shape)
{
    shape->oldx = shape->x;
    shape->x = shape->x + 1;
}

void Grid_Left(Shape *shape)
{
    shape->oldx = shape->x;
    shape->x = shape->x - 1;
}

bool Grid_IsShapeChanged(Shape *shape)
{
    if (shape->x != shape->oldx || shape->y != shape->oldy || shape->state != shape->oldState) {
        return true;
    }
    return false;
}

void Grid_MarkAsUpdated(Shape *shape)
{
    shape->oldx = shape->x;
    shape->oldy = shape->y;
    shape->oldState = shape->state;
}

Shape Grid_CreateShape()
{
    Shape shape = {
        .oldx = 0,
        .x = 0,
        .oldy = 0,
        .y = 0,
        .oldState = 0,
        .state = 0,
        .color = COLORS[rand() % 7]
    };

    int shapeIndex = rand() % 7;

    memcpy(&shape.shape, &SHAPES[shapeIndex], sizeof(SHAPES[shapeIndex]));

    return shape;
}

void Grid_FixShapeToGrid(Shape *shape)
{
    for (int8_t x = 0; x < SHAPE_WIDTH; x++) {
        for (int8_t y = 0; y < SHAPE_HEIGHT; y++) {
            if (shape->shape[shape->state][x][y] == 1) {
                grid[shape->x + x][shape->y + y] = shape->color;
            }
        }
    }
}

bool Grid_CanTurn(Shape *shape)
{
    int resx, resy = 0;

    for (int8_t x = 0; x < SHAPE_WIDTH; x++) {
        for (int8_t y = 0; y < SHAPE_HEIGHT; y++) {
            if (shape->shape[(shape->state + 1) % 4][x][y] == 1) {
                resx = shape->x + x;
                resy = shape->y + y;
                if (resx < 0 || resx >= GRID_WIDTH || resy >= GRID_HEIGHT || grid[resx][resy] != 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool Grid_CanMoveRight(Shape *shape)
{
    int resx, resy = 0;

    for (int8_t x = 0; x < SHAPE_WIDTH; x++) {
        for (int8_t y = 0; y < SHAPE_HEIGHT; y++) {
            if (shape->shape[shape->state][x][y] == 1) {
                resx = shape->x + x + 1;
                resy = shape->y + y;
                if (resx >= GRID_WIDTH || resy >= GRID_HEIGHT || grid[resx][resy] != 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool Grid_CanMoveLeft(Shape *shape)
{
    int resx, resy = 0;

    for (int8_t x = 0; x < SHAPE_WIDTH; x++) {
        for (int8_t y = 0; y < SHAPE_HEIGHT; y++) {
            if (shape->shape[shape->state][x][y] == 1) {
                resx = shape->x + x - 1;
                resy = shape->y + y;
                if (resx < 0 || resy < 0 || grid[resx][resy] != 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool Grid_CanMoveDown(Shape *shape)
{
    int resx, resy = 0;

    for (int8_t x = 0; x < SHAPE_WIDTH; x++) {
        for (int8_t y = 0; y < SHAPE_HEIGHT; y++) {
            if (shape->shape[shape->state][x][y] == 1) {
                resx = shape->x + x;
                resy = shape->y + y + 1;
                if (resx >= GRID_WIDTH || resy >= GRID_HEIGHT || grid[resx][resy] != 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool Grid_CheckFullLines()
{
    int count;
    for (int8_t y = GRID_HEIGHT - 1; y >= 0; y--) {
        count = 0;
        for (int8_t x = 0; x < GRID_WIDTH; x++) {
            if (grid[x][y] != 0) {
                count++;
            }
        }
        if (count == GRID_WIDTH) {
            return true;
       }
    }

    return false;
}

void Grid_IdentifySections(Section sections[MAX_SECTIONS])
{
    Section section = { -1, -1 };

    int i = 0;

    int count;
    for (int8_t y = GRID_HEIGHT - 1; y >= 0; y--) {
        count = 0;
        for (int8_t x = 0; x < GRID_WIDTH; x++) {
            if (grid[x][y] != 0) {
                count++;
            }
        }

        if (count == GRID_WIDTH) {
            if (section.bottom == -1) {
                section.bottom = y;
                section.top = y;
            } else {
                section.top = y;
            }
        } else {
            if (section.top != -1) {
                sections[i] = section;
                i++;

                section.top = -1;
                section.bottom = -1;
            }
        }
    }
}

void Grid_DropPart(Section *section)
{
    int height = section->bottom - section->top + 1;

    for (int8_t y = section->top - 1; y >= 0; y--) {
        for (int8_t x = 0; x < GRID_WIDTH; x++) {
            grid[x][y + height] = grid[x][y];
        }
    }
}
