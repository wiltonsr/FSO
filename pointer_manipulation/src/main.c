#include <stdlib.h>
#include <stdio.h>

void make_manipulation(){
    double number1 = 7.3, number2;
    char s1[100], s2[100];

    double *dPtr;
    dPtr = &number1;
    printf("%lf\n", *dPtr);
    number2 = *dPtr;
    printf("%lf\n", number2);
    printf("%p\n", &number1);
    printf("%p\n", dPtr);

    /* printf("%d\n", *dPtr); */
}

int main(void){

    make_manipulation();

    return 0;
}
