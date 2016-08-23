#ifndef TRIANGLE_H
#define TRIANGLE_H

// A point with coordinates X and Y
typedef struct Point {
    int x;
    int y;
} Point;

// Triangle with tree points
typedef struct Triangle{
    Point *point[3];
} Triangle;

#endif
