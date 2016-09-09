#ifndef MAX_H
#define MAX_H
#include "structure.h"
#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>

void make_join(pthread_t *threads, int number_threads);

void * print( void * args );

void * compare( void * args );

void * initialize_one( void * args );
#endif
