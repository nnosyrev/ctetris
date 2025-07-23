#ifndef _GRID_H_INCLUDED_
#define _GRID_H_INCLUDED_

#define GRID_WIDTH 10
#define GRID_HEIGHT 20
#define SHAPE_WIDTH 4
#define SHAPE_HEIGHT 4

#define SHAPE1 { \
    { \
        {1, 1}, \
        {1, 1} \
    }, \
    { \
        {1, 1}, \
        {1, 1} \
    }, \
    { \
        {1, 1}, \
        {1, 1} \
    }, \
    { \
        {1, 1}, \
        {1, 1} \
    } \
}

#define SHAPE2 { \
    { \
        {0, 0, 1}, \
        {0, 0, 1}, \
        {0, 1, 1} \
    }, \
    { \
        {0, 0, 0}, \
        {1, 0, 0}, \
        {1, 1, 1} \
    }, \
    { \
        {1, 1, 0}, \
        {1, 0, 0}, \
        {1, 0, 0} \
    }, \
    { \
        {1, 1, 1}, \
        {0, 0, 1}, \
        {0, 0, 0} \
    } \
}

#define SHAPE3 { \
    { \
        {0, 0, 1}, \
        {0, 1, 1}, \
        {0, 1, 0} \
    }, \
    { \
        {0, 0, 0}, \
        {1, 1, 0}, \
        {0, 1, 1} \
    }, \
    { \
        {0, 0, 1}, \
        {0, 1, 1}, \
        {0, 1, 0} \
    }, \
    { \
        {0, 0, 0}, \
        {1, 1, 0}, \
        {0, 1, 1} \
    } \
}

typedef struct {
    int x;
    int y;
    int shape[4][4][4];
    int state;
    int color;
} Shape;

Shape Grid_CreateShape();

void Grid_Turn(Shape *shape);
void Grid_Down(Shape *shape);
void Grid_Right(Shape *shape);
void Grid_Left(Shape *shape);

#endif
