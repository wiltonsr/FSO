#ifndef CORE_H
#define CORE_H

#include <stdlib.h>
#include <string.h>
#include "sort_list.h"
#include "io.h"

Sortlist *get_sort_list(const int TYPE, const int argc, char *argv[]);

int find_flag(const int FLAG, const int argc, char *argv[]);

char **remove_string_position(
        const int position_flag,
        const int argc,
        char *argv[]
        );

#endif
