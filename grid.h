#ifndef _GRID_H_INCLUDED_
#define _GRID_H_INCLUDED_

#define GRID_WIDTH 10
#define GRID_HEIGHT 20
#define MAX_SECTIONS 2
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
        {0, 1, 1}, \
        {0, 0, 1}, \
        {0, 0, 1} \
    }, \
    { \
        {1, 1, 1}, \
        {1, 0, 0}, \
        {0, 0, 0} \
    }, \
    { \
        {1, 0, 0}, \
        {1, 0, 0}, \
        {1, 1, 0} \
    }, \
    { \
        {0, 0, 0}, \
        {0, 0, 1}, \
        {1, 1, 1} \
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
        {0, 0, 1}, \
        {0, 1, 1}, \
        {0, 0, 1} \
    }, \
    { \
        {1, 1, 1}, \
        {0, 1, 0}, \
        {0, 0, 0} \
    }, \
    { \
        {1, 0, 0}, \
        {1, 1, 0}, \
        {1, 0, 0} \
    }, \
    { \
        {0, 0, 0}, \
        {0, 1, 0}, \
        {1, 1, 1} \
    } \
}

#define FRAME_COLOR 0x000000

#define COLOR_WHITE 0xFFFFFF
#define COLOR_RED 0xFF0000
#define COLOR_ORANGE 0xFFA500
#define COLOR_YELLOW 0xFFFF00
#define COLOR_GREEN 0x008000
#define COLOR_LIGHTBLUE 0xADD8E6
#define COLOR_BLUE 0x0000FF
#define COLOR_PURPLE 0x800080

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

typedef struct {
    int bottom;
    int top;
} Section;

Shape Grid_CreateShape();

void Grid_Turn(Shape *shape);
void Grid_Down(Shape *shape);
void Grid_Right(Shape *shape);
void Grid_Left(Shape *shape);
bool Grid_IsShapeChanged(Shape *shape);
bool Grid_LastMoveWasDown(Shape *shape);
void Grid_MarkAsUpdated(Shape *shape);
bool Grid_CanMoveRight(Shape *shape);
bool Grid_CanMoveLeft(Shape *shape);
bool Grid_CanMoveDown(Shape *shape);
bool Grid_CanTurn(Shape *shape);
void Grid_FixShapeToGrid(Shape *shape);
bool Grid_CheckFullLines();
void Grid_IdentifySections(Section sections[2]);
void Grid_DropPart(Section *section);
void Grid_DrawShape(Shape *shape);
void Grid_ClearOldShape(Shape *shape);

#endif
