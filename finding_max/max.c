#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAX 100
int *w[MAX];
int x[MAX];
int max = 0;

void * initialize_one( void * args ){
  int *val = (int *)(args);
  w[*val] = 1;
}

void * compare( void * args ){
  int *val = (int *)(args);
  if (x[*val] < x[*val+1])
    w[*val] = 0;
  else
    w[*val+1] = 0;
}

void * print( void * args ){
  int *val = (int *)(args);
  if (w[*val] == 1)
    printf("%d\n", x[*val]);
}

int main(int argc, char *argv[])
{
  int NUM_INITIALIZER = argc - 1;
  int NUM_COMPARATIONS= ((argc - 1)*(argc - 2))/2;
  pthread_t thread[NUM_INITIALIZER];

  for(int i = 0; i < NUM_INITIALIZER; i++){
    x[i] = atoi(argv[i+1]);
  }

  for(int i = 0; i < NUM_INITIALIZER; i++){
    pthread_create(&thread[i], NULL, initialize_one, (void *)(&i));
    pthread_join(thread[i], NULL);
  }

  for(int i = 0; i < NUM_INITIALIZER; i++){
    pthread_join(thread[i], NULL);
  }

  for(int i = 0; i < NUM_INITIALIZER; i++){
    //pthread_exit(0);
  }

  for(int i = 0; i < NUM_INITIALIZER; i++){
    pthread_create(&thread[i], NULL, compare, (void *)(&x[i]));
    pthread_join(thread[i], NULL);
  }

  for(int i = 0; i < NUM_INITIALIZER; i++){
    printf("%d\n", w[i]);
  }

  for(int i = 0; i < NUM_INITIALIZER; i++){
    pthread_create(&thread[i], NULL, print, (void *)(&i));
    pthread_join(thread[i], NULL);
  }

  return 0;
}
