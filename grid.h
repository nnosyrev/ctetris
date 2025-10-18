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
        {1, 0, 0}, \
        {1, 0, 0}, \
        {1, 1, 0} \
    }, \
    { \
        {0, 0, 0}, \
        {0, 0, 1}, \
        {1, 1, 1} \
    }, \
    { \
        {0, 1, 1}, \
        {0, 0, 1}, \
        {0, 0, 1} \
    }, \
    { \
        {1, 1, 1}, \
        {1, 0, 0}, \
        {0, 0, 0} \
    } \
}

#define SHAPE4 { \
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

#define SHAPE5 { \
    { \
        {1, 0, 0}, \
        {1, 1, 0}, \
        {0, 1, 0} \
    }, \
    { \
        {0, 0, 0}, \
        {0, 1, 1}, \
        {1, 1, 0} \
    }, \
    { \
        {1, 0, 0}, \
        {1, 1, 0}, \
        {0, 1, 0} \
    }, \
    { \
        {0, 0, 0}, \
        {0, 1, 1}, \
        {1, 1, 0} \
    } \
}

#define SHAPE6 { \
    { \
        {0, 1, 0, 0}, \
        {0, 1, 0, 0}, \
        {0, 1, 0, 0}, \
        {0, 1, 0, 0} \
    }, \
    { \
        {0, 0, 0, 0}, \
        {1, 1, 1, 1}, \
        {0, 0, 0, 0}, \
        {0, 0, 0, 0} \
    }, \
    { \
        {0, 1, 0, 0}, \
        {0, 1, 0, 0}, \
        {0, 1, 0, 0}, \
        {0, 1, 0, 0} \
    }, \
    { \
        {0, 0, 0, 0}, \
        {1, 1, 1, 1}, \
        {0, 0, 0, 0}, \
        {0, 0, 0, 0} \
    } \
}

#define SHAPE7 { \
    { \
        {0, 0, 0}, \
        {0, 1, 0}, \
        {1, 1, 1} \
    }, \
    { \
        {1, 0, 0}, \
        {1, 1, 0}, \
        {1, 0, 0} \
    }, \
    { \
        {1, 1, 1}, \
        {0, 1, 0}, \
        {0, 0, 0} \
    }, \
    { \
        {0, 0, 1}, \
        {0, 1, 1}, \
        {0, 0, 1} \
    } \
}

typedef struct {
    int oldx;
    int x;
    int oldy;
    int y;
    int oldState;
    int state;
    int shape[4][4][4];
    int color;
} Shape;

Shape Grid_CreateShape();

void Grid_Turn(Shape *shape);
void Grid_Down(Shape *shape);
void Grid_Right(Shape *shape);
void Grid_Left(Shape *shape);
bool Grid_IsShapeChanged(Shape *shape);
void Grid_MarkAsUpdated(Shape *shape);
bool Grid_CanMoveRight(Shape *shape);
bool Grid_CanMoveLeft(Shape *shape);
bool Grid_CanMoveDown(Shape *shape);
bool Grid_CanTurn(Shape *shape);
void Grid_FixShapeToGrid(Shape *shape);

#endif
