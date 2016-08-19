#include <stdlib.h>
#include <math.h>
#include "../lib/triangle.h"
#include "../lib/operations.h"

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

double *calculate_sides(Triangle *triangle){
    Point *a = triangle->point[0];
    Point *b = triangle->point[1];
    Point *c = triangle->point[2];

    double *sides = malloc(sizeof(double));
    sides[0]= calculate_distance(a, b);
    sides[1] = calculate_distance(b, c);
    sides[2] = calculate_distance(a, c);

    return sides;
}

double calculate_perimeter(Triangle *triangle){
    double *sides = calculate_sides(triangle);

    double perimeter = 0.0;
    for (int i = 0; i < 3; i++) {
        perimeter += sides[i];
    }
    return perimeter;
}

double calculate_distance(Point *a, Point *b){
    double distance = 0.0;

    distance = sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
    return distance;
}
