#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<pthread.h>
#include "max.h"
#include "structure.h"

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  assert( n <= 100 );
  assert( n > 0 );
  int NUM_INITIALIZER = n;
  int NUM_COMPARATIONS= ((n - 1)*(n - 2))/2;
  pthread_t thread[NUM_INITIALIZER];

  Array *thread_args = malloc(NUM_INITIALIZER * sizeof(Array));

  for(int i = 0; i < NUM_INITIALIZER; i++){
    assert(argv[i+2] != NULL);
    thread_args[i].x = atoi(argv[i+2]);
    thread_args[i].n = i;
  }

  printf("Number of input values = %d\n", NUM_INITIALIZER);
  if(NUM_INITIALIZER > 0){
    printf("Input values x = ");
    for(int i = 0; i < NUM_INITIALIZER; i++){
      printf("%d ",thread_args[i]);
    }
    printf("\n");

    for(int i = 0; i < NUM_INITIALIZER; i++){
      thread_args[i].n = i;
      pthread_create(&thread[i], NULL, initialize_one, &thread_args[i]);
    }

    make_join(thread, NUM_INITIALIZER);

    printf("After initialization w = ");
    for(int i = 0; i < NUM_INITIALIZER; i++){
      printf("%d ",thread_args[i].w);
    }
    printf("\n");

    pair_compare_t *pair_compare = malloc(
        NUM_COMPARATIONS * sizeof(pair_compare_t)
        );

    for (int i = 0; i < NUM_INITIALIZER - 1; i++) {
      int count_compare = 0;
      for (int j = i + 1; j < NUM_INITIALIZER; j++) {
        pair_compare[count_compare].left = &thread_args[i];
        pair_compare[count_compare].right = &thread_args[j];
        pthread_create(
            &thread[i],
            NULL,
            compare,
            &pair_compare[count_compare]
            );
        int w_position;
        if(thread_args[i].x < thread_args[j].x)
          w_position = i;
        else
          w_position = j;
        printf("Thread T(%d,%d) compares x[%d] = %d and x[%d] = %d, and writes 0 into w[%d]\n", i, j, i, thread_args[i].x, j, thread_args[j].x, w_position);
        count_compare++;
      }
    }

    make_join(thread, NUM_INITIALIZER);

    printf("After Step 2\nw = ");
    for(int i = 0; i < NUM_INITIALIZER; i++){
      printf("%d ",thread_args[i].w);
    }
    printf("\n");

    for(int i = 0; i < NUM_INITIALIZER; i++){
      pthread_create(&thread[i], NULL, print, &thread_args[i]);
    }

    make_join(thread, NUM_INITIALIZER);
  }
  return 0;
}
