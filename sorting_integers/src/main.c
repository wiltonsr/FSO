#define _GNU_SOURCE
#include "../lib/io.h"

int main(int argc, char *argv[]){

    int argc_is_valid = validate_argc(argc);
    int argv_is_valid = validate_argv(argc, argv);
    int arg_is_valid = (
            argc_is_valid &&
            argv_is_valid != ERROR_ARG
            && argv_is_valid != HELP_ARG
        );

    if(arg_is_valid){
        /* Implemente here */
    }
    else{
        if(!argc_is_valid)
            print_error(MISSING_ARG);
        else if(argv_is_valid == ERROR_ARG)
            print_error(MISSING_INTEGER);
        else if(argv_is_valid == HELP_ARG)
            print_man();
    }
    return 0;
}
