#include "stdbool.h"

#define GRID_WIDTH 10
#define GRID_HEIGHT 20

int grid[GRID_WIDTH][GRID_HEIGHT] = { 0 };

typedef struct {
    int x;
    int y;
    int shape[];
} Shape;

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
