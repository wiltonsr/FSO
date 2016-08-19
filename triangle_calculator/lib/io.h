#ifndef IO_H
#define IO_H
#include "triangle.h"

Point *get_point(int point_number);

Triangle *get_triangle();

void print_len_sides(double *sides);

void print_perimeter(double perimeter);

void print_area(double area);

void print_error();

#endif
