#include "io.h"
#include "triangle.h"
#include "operations.h"


int main(void){
    Triangle *triangle = get_triangle();
    double area = calculate_area(triangle);
    print_area(area);
    return 0;
}
