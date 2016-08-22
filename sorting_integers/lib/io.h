#ifndef IO_H
#define IO_H

// Validate the number of the argc
int validate_argc(int argc);

// Print a given error
void print_error(const char *menssage);

// Print the man of the software
void print_man();

// Check if the argv is correct
int check_argc_argv(int argc, int flag);

// Validate all argv
int validate_argv(int argc, char *argv[]);

// Global messages to send to print error
extern const char *MISSING_ARG;
extern const char *MISSING_INTEGER;

// Flags to identify types of args
extern const int EMPTY_ARG;
extern const int CRESCENT_ARG;
extern const int DECREASIN_ARG;
extern const int HELP_ARG;
extern const int ERROR_ARG;

#endif
