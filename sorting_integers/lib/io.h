#ifndef IO_H
#define IO_H
#include "sort_list.h"

Sort_list get_list(int argc, int *argv[]);

int validate_argc(int argc);

void print_error(char *menssage);

void print_man();

int validate_argv(int argc, char *argv[]);

extern const char *MISSING_ARG;
extern const int EMPTY_ARG;
extern const int CRESCENT_ARG;
extern const int DECREASIN_ARG;
extern const int HELP_ARG;
extern const int ERROR_ARG;

#endif
