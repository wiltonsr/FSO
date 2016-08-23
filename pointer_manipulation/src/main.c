#include <stdlib.h>
#include <string.h>
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

    scanf("%s", &s1);
    strcpy(s2, s1);
    int compare = strcmp(s1, s2);
    printf("%d\n", compare);

}

int main(void){

    make_manipulation();

    return 0;
}
