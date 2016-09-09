#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct Array{
    int x;
    int w;
    int n;
}Array;

typedef struct pair_compare_t{
    Array *left;
    Array *right;
}pair_compare_t;

#endif
