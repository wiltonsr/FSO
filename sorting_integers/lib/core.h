#ifndef CORE_H
#define CORE_H

#include <stdlib.h>
#include <string.h>
#include "sort_list.h"
#include "io.h"

// Get a list of a sort component
Sortlist *get_sort_list(const int TYPE, const int argc, char *argv[]);

// Find a flag of args in the argv
int find_flag(const int FLAG, const int argc, char *argv[]);

// Parser a array of strings in int
int *parser_to_int(const int argv_len, const int argc, char *argv[]);

// Count a number of null in a array
int count_null(const int len, char *argv[]);

// Create a node of sort list
Sortlist *create_sort_list(
        const int len,
        const int flag,
        const int *sort_list_int
        );

// Remove a string in a determinate position of the array
char **remove_string_position(
        const int position_flag,
        const int argc,
        char *argv[]
        );

#endif
