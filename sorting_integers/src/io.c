#include <stdio.h>
#include <stdlib.h>
#include "../lib/io.h"
#include "../lib/sort_list.h"

Sort_list get_list(int argc, int *argv[]){
}

int validate_argc(int argc){
    int is_valid = 0;

    if (argc >= 2)
        is_valid = 1;

    return is_valid;
}
