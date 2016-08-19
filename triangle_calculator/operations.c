#include <stdlib.h>
#include <math.h>
#include "triangle.h"
#include "operations.h"

double calculate_area(Triangle *triangle){
    Point *a = triangle->point[0];
    Point *b = triangle->point[1];
    Point *c = triangle->point[2];
    double area = 0.0;
    double denominator = 0.0;

    denominator = a->x * (b->y - c->y) + b->x * (c->y - a->y) + c->x * (a->y - b->y);
    area = (double)(abs(denominator))/2;

    return area;
}

double calculate_sides(Triangle *triangle){
    return 0.0;
}

double calculate_perimeter(Triangle *triangle){
    return 0.0;
}

double calculate_distance(Point *a, Point *b){
    double distance = 0.0;

    distance = sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
    return distance;
}
