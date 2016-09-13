#include <stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef struct Array{
  int x;
  int w;
  int n;
}Array;

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  assert( n <= 100 );
  assert( n > 0 );
  int NUM_INITIALIZER = n;
  int NUM_COMPARATIONS= ((n - 1)*(n - 2))/2;

  Array *array = malloc(NUM_INITIALIZER * sizeof(Array));

  for(int i = 0; i < NUM_INITIALIZER; i++){
    assert(argv[i+2] != NULL);
    array[i].x = atoi(argv[i+2]);
    array[i].n = i;
  }

  for(int i = 0; i < NUM_INITIALIZER; i++){
    array[i].w = 1;
  }

  printf("Number of input values = %d\n", NUM_INITIALIZER);
  if(NUM_INITIALIZER > 0){
    printf("Input values x = ");
    for(int i = 0; i < NUM_INITIALIZER; i++){
      printf("%d ",array[i].x);
    }
    printf("\n");
    printf("After initialization w = ");
    for(int i = 0; i < NUM_INITIALIZER; i++){
      printf("%d ",array[i].w);
    }
    printf("\n");

    for (int i = 0; i < NUM_INITIALIZER - 1; i++) {
      int count_compare = 0;
      for (int j = i + 1; j < NUM_INITIALIZER; j++) {
        if (array[i].x < array[j].x)
          array[i].w = 0;
        else
          array[j].w = 0;
        int w_position;
        if(array[i].x < array[j].x)
          w_position = i;
        else
          w_position = j;
        printf("Thread T(%d,%d) compares x[%d] = %d and x[%d] = %d, and writes 0 into w[%d]\n", i, j, i, array[i].x, j, array[j].x, w_position);
        count_compare++;
      }
    }

    printf("After Step 2\nw = ");
    for(int i = 0; i < NUM_INITIALIZER; i++){
      printf("%d ",array[i].w);
    }
    printf("\n");

    for(int i = 0; i < NUM_INITIALIZER; i++){
      if (array[i].w == 1){
        printf("Maximum = %d\n", array[i].x);
        printf("Location = %d\n", array[i].n);
      }
    }
  }
  return 0;
}
