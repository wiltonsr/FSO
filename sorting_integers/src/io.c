/* IO manipulation of the software */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/io.h"

const char *MISSING_ARG = "An arg is missing";
const char *MISSING_INTEGER = "Put some integers to sort";
const int EMPTY_ARG = 0;
const int CRESCENT_ARG = 1;
const int DECREASIN_ARG = 2;
const int HELP_ARG = 3;
const int ERROR_ARG = 4;

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
    printf("All option or input are:\n");
    printf("\n");
    printf("\t-d, \t\t\tsort in crescent order\n");
    printf("\t-r, \t\t\tsort in decreasing order\n");
    printf("\t-h, --help \t\tshow this help\n");
    printf("\n");
    printf("Example:\n");
    printf("\t\t./run -d 4 5 34 3 9 1 10\n");
    printf("\tor:\t./run -r 4 5 34 3 9 1 10\n");
    printf("\tor:\t./run 4 5 34 3 9 1 10\n");
    printf("\n");
    printf("Thank you to use our program. Contact us from email: ");
    printf("tiago@sof2u.com or braynwilton@gmail.com\n");
}

void print_error(const char *message){
    printf("ERROR: ");
    printf("%s\n\n", message);
    print_man();
}

int check_argc_argv(int argc, int flag){
    if(flag == HELP_ARG)
        /* Returns an error if have the flag -h or --help */
        return HELP_ARG;
    else{
        if(argc <= 2)
            /* Returns an error if have a flag -d or -r and not have numbers */
            return ERROR_ARG;
    }

    /* Returns the flag arg if everything is correct */
    return flag;
}

int validate_argv(int argc, char *argv[]){
    int validate_response = 0;

    /* Interate in all arguments */
    for (int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-h") == 0)
            validate_response = check_argc_argv(argc, HELP_ARG);
        else if(strcmp(argv[i], "--help") == 0)
            validate_response = check_argc_argv(argc, HELP_ARG);
        else if(strcmp(argv[i], "-d") == 0)
            validate_response = check_argc_argv(argc, CRESCENT_ARG);
        else if(strcmp(argv[i], "-r") == 0)
            validate_response = check_argc_argv(argc, DECREASIN_ARG);

        if (validate_response)
            return validate_response;
    }

    return validate_response;
}
