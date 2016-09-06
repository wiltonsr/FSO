#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAX 100
typedef struct Array{
    int x;
    int w;
    int n;
}Array;

typedef struct pair_compare_t{
    Array *left;
    Array *right;
}pair_compare_t;

/* int *w[MAX]; */
/* int x[MAX]; */
/* int max = 0; */

/* void * print( void * args ){ */
/*   int *val = (int *)(args); */
/*   if (w[*val] == 1) */
/*     printf("%d\n", x[*val]); */
/* } */

void * compare( void * args ){
  pair_compare_t * pair_compare = (pair_compare_t*) args;
  if (pair_compare->left->x < pair_compare->right->x)
    pair_compare->left->w = 0;
  else
    pair_compare->right->w = 0;

  printf("pasosu\n");
}

void * initialize_one( void * args ){
  Array *thread_args = (Array*) args;
  thread_args->w = 1;
}

int main(int argc, char *argv[])
{
  int NUM_INITIALIZER = argc - 1;
  int NUM_COMPARATIONS= ((argc - 1)*(argc - 2))/2;
  pthread_t thread[NUM_INITIALIZER];

  Array *thread_args = malloc(NUM_INITIALIZER * sizeof(Array));

  for(int i = 0; i < NUM_INITIALIZER; i++){
    thread_args[i].x = atoi(argv[i+1]);
  }

  for(int i = 0; i < NUM_INITIALIZER; i++){
    thread_args[i].n = i;
    pthread_create(&thread[i], NULL, initialize_one, &thread_args[i]);
  }


  for(int i = 0; i < NUM_INITIALIZER; i++){
    pthread_join(thread[i], NULL);
  }

  pair_compare_t *pair_compare = malloc(NUM_COMPARATIONS * sizeof(pair_compare_t));
  int count_compare = 0;

  for (int i = 0; i < NUM_INITIALIZER - 1; i++) {
      for (int j = i + 1; j < NUM_INITIALIZER; j++) {
        pair_compare[count_compare].left = &thread_args[i];
        pair_compare[count_compare].right = &thread_args[j];
        count_compare++;

        pthread_create(&thread[i], NULL, compare, &pair_compare);
      }
  }

  for(int i = 0; i < NUM_INITIALIZER; i++){
    pthread_join(thread[i], NULL);
  }

  for (int i = 0; i < NUM_INITIALIZER; i++) {
      printf("w = %d\n", thread_args[i].w);
  }
  /* for(int i = 0; i < NUM_INITIALIZER; i++){ */
  /*   pthread_create(&thread[i], NULL, compare, (void *)(&x[i])); */
  /*   pthread_join(thread[i], NULL); */
  /* } */
  /*  */
  /* for(int i = 0; i < NUM_INITIALIZER; i++){ */
  /*   printf("%d\n", w[i]); */
  /* } */
  /*  */
  /* for(int i = 0; i < NUM_INITIALIZER; i++){ */
  /*   pthread_create(&thread[i], NULL, print, (void *)(&i)); */
  /*   pthread_join(thread[i], NULL); */
  /* } */
  /*  */
  return 0;
}
