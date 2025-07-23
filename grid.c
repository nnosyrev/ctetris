#include "area.h"
#include "stdbool.h"
#include "grid.h"

int grid[GRID_WIDTH][GRID_HEIGHT] = { 0 };

int SHAPES[3][4][4][4] = { SHAPE1, SHAPE2, SHAPE3 };

void Grid_Turn(Shape *shape)
{
    shape->state = (shape->state + 1) % 4;
}

void Grid_Down(Shape *shape)
{
    shape->y = shape->y + 1;
}

void Grid_Right(Shape *shape)
{
    shape->x = shape->x + 1;
}

void Grid_Left(Shape *shape)
{
    shape->x = shape->x - 1;
}

Shape Grid_CreateShape()
{
    Shape shape = { .x = 0, .y = 0, .color = COLOR_PURPLE, .state = 0 };

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
