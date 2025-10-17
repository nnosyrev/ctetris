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

void Grid_FixShapeToGrid(int *grid, Shape *shape)
{
}

bool Grid_CanTurn(int *grid, Shape *shape)
{
    return false;
}

bool Grid_CanMoveRight(int *grid, Shape *shape)
{
    return false;
}
