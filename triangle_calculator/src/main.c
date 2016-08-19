#define _GNU_SOURCE
#include "../lib/io.h"
#include "../lib/triangle.h"
#include "../lib/operations.h"

int main(void){
    Triangle *triangle = get_triangle();
    double area = calculate_area(triangle);
    double *sides = calculate_sides(triangle);
    double perimeter = calculate_perimeter(triangle);

    if(area >= 0 || perimeter >= 0){
        print_area(area);
        print_len_sides(sides);
        print_perimeter(perimeter);
    }
    else
        print_error();

    free_memory(triangle);
    free_memory(sides);

    return 0;
}
