#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void make_manipulation(){
    double number1 = 7.3, number2;
    char s1[100], s2[100];

    // Declare pointer
    double *dPtr;

    // Point to valor of number1
    dPtr = &number1;
    printf("Value of dPtr: %lf\n", *dPtr);

    // Number2 is equals to pointer value
    number2 = *dPtr;
    printf("Value of number2: %lf\n", number2);
    printf("Pointer to number1: %p\n", &number1);
    printf("Pointer to dPtr: %p\n", dPtr);

    /* O valor impresso decorrente do enunciado que contempla o */
    /* item anterior */
    /* é igual ao valor do endereço gravado em dPrt? */
    /*  */
    /* Não, pois, o valor de dPtr é apenas um ponteiro */
    /* indicando o endereço da variavel number1 */

    // Get a string
    printf("Put a string: ");
    scanf("%s", &s1);

    // Copy the value of the s1 to s2
    strcpy(s2, s1);

    // Compare the value of the s1 and s2
    int compare = strcmp(s1, s2);
    printf("Compare to s1 and s2: %d\n", compare);

    // Concat the value of the s1 and s2
    strcat(s1, s2);
    printf("Concat of s1 and s2: %s\n", s1);

    // Calculate the len of the s1
    int len = strlen(s1);
    printf("Len of |%s| is |%d|\n", s1, len);

}

int main(void){

    make_manipulation();

    return 0;
}
