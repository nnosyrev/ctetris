#include "stdbool.h"
#include "grid.h"

int grid[GRID_WIDTH][GRID_HEIGHT] = { 0 };

int shape1[2][2] = {
    {1, 1},
    {1, 1}
};

int shape2[3][3] = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 1, 1}
};

int shape3[3][3] = {
    {0, 0, 0},
    {1, 1, 0},
    {0, 1, 1}
};

int shape4[3][3] = {
    {0, 0, 0},
    {0, 1, 1},
    {1, 1, 0}
};

int shape5[3][3] = {
    {0, 0, 0},
    {0, 0, 1},
    {1, 1, 1}
};

int shape6[3][3] = {
    {0, 0, 0},
    {1, 0, 0},
    {1, 1, 1}
};

int shape7[4][4] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0}
};

void Grid_Turn(int *shape)
{
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
