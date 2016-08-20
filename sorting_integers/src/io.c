#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/io.h"
#include "../lib/sort_list.h"

const char *MISSING_ARG = "An arg is missing";
const int EMPTY_ARG = 0;
const int CRESCENT_ARG = 1;
const int DECREASIN_ARG = 2;
const int HELP_ARG = 3;
const int ERROR_ARG = 4;

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
    printf("\t-d, \t\t\tsort in crescent order\n");
    printf("\t-r, \t\t\tsort in decreasing order\n");
    printf("\t-h, --help \t\tshow this help\n");
    printf("Thank you to use our program. Contact us from email: ");
    printf("tiago@sof2u.com\n");
}

void print_error(const char *message){
    printf("ERROR: ");
    printf("%s\n\n", message);
    print_man();
}

int validate_argv(int argc, char *argv[]){
    int validate_response = 0;

    /* Interate in all arguments */
    for (int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-h") == 0)
            validate_response = HELP_ARG;
        else if(strcmp(argv[i], "--help") == 0)
            validate_response = HELP_ARG;
        else if(strcmp(argv[i], "-d") == 0)
            validate_response = CRESCENT_ARG;
        else if(strcmp(argv[i], "-r") == 0)
            validate_response = DECREASIN_ARG;

        if (validate_response)
            return validate_response;
    }

    return validate_response;
}
