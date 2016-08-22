#ifndef CORE_H
#define CORE_H
#include <stdlib.h>
#include "sort_list.h"
#include "../lib/io.h"

Sortlist *get_sort_list(const int TYPE, const int argc, char *argv[]);

int find_flag(const int FLAG, const int argc, char *argv[]);

#endif
