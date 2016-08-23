#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include "sort_list.h"

int crescent(const void * rigth, const void * left);

int decreasing(const void * rigth, const void * left);

Sortlist *make_sort(Sortlist *sort_list);

#endif
