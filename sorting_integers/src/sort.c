/* Make a sorting with the integers */
#include "../lib/core.h"

int decreasing(const void * rigth, const void * left){
    int f = *((int*)rigth);
    int s = *((int*)left);

    if (f > s) return -1;
    if (f < s) return  1;
    return 0;
}

int crescent(const void * rigth, const void * left){
    int f = *((int*)rigth);
    int s = *((int*)left);

    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

Sortlist *make_sort(Sortlist *sort_list){
    int *list = sort_list->int_list;
    qsort(list, sort_list->list_len, sizeof(int), decreasing);
    sort_list->int_list = list;

    return sort_list;
}
