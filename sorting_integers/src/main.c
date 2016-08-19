#define _GNU_SOURCE
#include "../lib/io.h"

int main(int argc, char *argv[]){

    int argc_is_valid = validate_argc(argc);
    if(argc_is_valid){
        /* Implemente here */
    }
    else{
        if(!argc_is_valid)
            print_error(MISSING_ARG);
    }
    return 0;
}
