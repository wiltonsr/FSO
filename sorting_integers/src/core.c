/* Core of the sort program, with array manipulation, etc */
#include "../lib/core.h"
#include <string.h>

Sortlist *get_sort_list(const int flag, const int argc, char *argv[]){
    Sortlist *sort_list = malloc(sizeof(Sortlist));
    int position_flag = 0;

    if(flag){
        position_flag = find_flag(flag, argc, argv);
    }
    return sort_list;
}

int find_flag(const int flag, const int argc, char *argv[]){
    int position_flag = 0;

    for (int i = 0; i < argc; i++) {
        if(flag == CRESCENT_ARG){
            if (strcmp(argv[i], "-d"))
                position_flag = i;
        }
        else if(flag ==  DECREASIN_ARG){
            if (strcmp(argv[i], "-r"))
                position_flag = i;
        }
    }
    return position_flag;
}
