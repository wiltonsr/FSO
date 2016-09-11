#include <stdio.h>
#include <stdlib.h>

int a[3][2] = {
   {0, 1,},
   {4, 5,},
   {8, 9,}
};

int b[2][3] = {
   {0, 1, 2},
   {4, 5, 6},
};

int c[3][3] = {
   {0, 0, 0},
   {0, 0, 0},
   {0, 0, 0},
};

int get_sum(int i, int j){
    int sum_elem = 0;

    sum_elem = a[i][0] * b[0][j] + a[i][1] * b[1][j];
    return sum_elem;
}

void iterate_matrix(){
    int result = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result = get_sum(i, j);
            c[i][j] = result;
        }
    }
}

void print_matrix(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, const char *argv[]){
    iterate_matrix();
    print_matrix();
    return 0;
}
