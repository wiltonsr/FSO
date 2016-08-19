#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "triangle.h"

Point *get_point(int point_number){
    Point *point = malloc(sizeof(Point));
    int x, y;

    printf("Put coordinates X and Y of the point %d (0 0):\n", point_number);
    scanf("%d %d", &x, &y);
    point->x = x;
    point->y = y;

    return point;
}

Triangle *get_triangle(){
    printf("We will get 3 points form your triangle\n");
    Triangle *triangle = malloc(sizeof(Triangle));

    int i;
    for (i = 0; i < 3; i++) {
        triangle->point[i] = get_point(i);
    }

    return triangle;
}

void print_len_sides(double *sides){
    for (int i = 0; i < 3; i++) {
        printf("The len of the side %d is %.2lf\n", i, sides[i]);
    }
}

void print_perimeter(double perimeter){
    printf("The perimeter is %.2lf\n", perimeter);
}

void print_area(double area){
    printf("The area is %.2lf\n", area);
}

void print_error(){
    printf("Program error. Exiting...");
    exit(-1);
}
