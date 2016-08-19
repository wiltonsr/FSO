#include <stdio.h>
#include <stdlib.h>
#include "../lib/io.h"
#include "../lib/sort_list.h"

char *MISSING_ARG = "An arg is missing";

Sort_list get_list(int argc, int *argv[]){
}

int validate_argc(int argc){
    int is_valid = 0;

    if (argc >= 2)
        is_valid = 1;

    return is_valid;
}

void print_man(){
    printf("Use: ./run [Option] ...   (1º form)\n");
    printf(" or: ./run ...            (2º form)\n");
    printf("In 1st form, put the option and the follow itengers\n");
    printf("In 2nd form, put just the follow itengers and they will sort ");
    printf("in crescent order\n");
    printf("\n");
    printf("The all option be:\n");
    printf("\n");
    printf("\t-d, \t\tsort in crescent order\n");
    printf("\t-r, \t\tsort in decreasing order\n");
    printf("Thank you to use our program. Contact us from email: ");
    printf("tiago@sof2u.com\n");
}

void print_error(char *message){
    printf("ERROR: ");
    printf("%s\n\n", message);
    print_man();
}

int validate_argv(int argc, char *argv[]){
    for (i = 0; i < argc; i++) {
        // Adding verification
    }
}
