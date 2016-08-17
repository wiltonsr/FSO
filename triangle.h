#ifndef TRIANGLE_H
#define TRIANGLE_H

// A point with coordinates X and Y
typedef struct point {
    int x;
    int y;
} Point;

// Triangle with tree points
typedef struct triangle{
    Point points[3];
} Triangle;

#endif
