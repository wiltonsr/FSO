#include "max.h"

void make_join(pthread_t *threads, int number_threads){
  for(int i = 0; i < number_threads; i++){
    pthread_join(threads[i], NULL);
  }
}

void * print( void * args ){
  Array *val= (Array*) args;
  if (val->w == 1){
    printf("Maximum = %d\n", val->x);
    printf("Location = %d\n", val->n);
  }
}

void * compare( void * args ){
  pair_compare_t * pair_compare = (pair_compare_t*) args;
  if (pair_compare->left->x < pair_compare->right->x)
    pair_compare->left->w = 0;
  else
    pair_compare->right->w = 0;
}

void * initialize_one( void * args ){
  Array *thread_args = (Array*) args;
  thread_args->w = 1;
}
