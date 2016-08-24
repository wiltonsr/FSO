#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void make_manipulation(){
    double number1 = 7.3, number2;
    char s1[100], s2[100];

    double *dPtr;
    dPtr = &number1;
    printf("Value of dPtr: %lf\n", *dPtr);
    number2 = *dPtr;
    printf("Value of number2: %lf\n", number2);
    printf("Pointer to number1: %p\n", &number1);
    printf("Pointer to dPtr: %p\n", dPtr);

    printf("Put a string: ");
    scanf("%s", &s1);
    strcpy(s2, s1);
    int compare = strcmp(s1, s2);
    printf("Compare to s1 and s2: %d\n", compare);
    strcat(s1, s2);
    printf("Concat of s1 and s2: %s\n", s1);
    int len = strlen(s1);
    printf("Len of |%s| is |%d|\n", s1, len);

}

int main(void){

    make_manipulation();

    return 0;
}
