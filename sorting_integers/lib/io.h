#ifndef IO_H
#define IO_H
#include "sort_list.h"

Sort_list get_list(int argc, int *argv[]);

int validate_argc(int argc);

void print_error(char *menssage);

void print_man();

#endif
