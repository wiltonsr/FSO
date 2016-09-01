#define _GNU_SOURCE
#include "io.h"
#include "operations.h"
#include "triangle.h"


int main(void){
    Triangle *triangle = get_triangle();
    double area = calculate_area(triangle);
    double *sides = calculate_sides(triangle);
    double perimeter = calculate_perimeter(triangle);

    if(area > 0 && perimeter > 0){
        print_area(area);
        print_len_sides(sides);
        print_perimeter(perimeter);
    }
    else{
        if(area <= 0){
            print_error("This triangle not exists.");
        }
        else if(perimeter <= 0){
            print_error("This triangle not exists.");
        }
        else{
            print_error("");
        }
    }

    free_memory(triangle);
    free_memory(sides);

    return 0;
}
