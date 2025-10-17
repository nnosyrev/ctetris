#include "area.h"
#include "stdbool.h"
#include "grid.h"

int grid[GRID_WIDTH][GRID_HEIGHT] = { 0 };

int SHAPES[3][4][4][4] = { SHAPE1, SHAPE2, SHAPE3 };

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
        .color = COLOR_PURPLE
    };

    int shapeIndex = 1;

    memcpy(&shape.shape, &SHAPES[shapeIndex], sizeof(SHAPES[shapeIndex]));

    return shape;
}

void Grid_FixShapeToGrid(Shape *shape)
{
    int resx, resy = 0;

    for (int8_t x = 0; x < SHAPE_WIDTH; x++) {
        for (int8_t y = 0; y < SHAPE_HEIGHT; y++) {
            if (shape->shape[shape->state][x][y] == 1) {
                resx = shape->x + x;
                resy = shape->y + y;

                grid[resx][resy] = shape->color;
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
