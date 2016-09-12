#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>

typedef struct identifier_t{
  int a0;
  int a1;
  int b0;
  int b1;
  int id_x;
  int id_y;
}identifier_t;

int a[3][2] = {
  {0, 1,},
  {4, 5,},
  {8, 9,}
};

int b[2][3] = {
  {0, 1, 2},
  {4, 5, 6},
};

int c[3][3] = {
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
};

void *get_sum(void *args){
  identifier_t *id = (identifier_t*) args;

  int a0 = id->a0;
  int a1 = id->a1;
  int b0 = id->b0;
  int b1 = id->b1;

  int sum_elem = 0;

  sum_elem = a0 * b0 + a1 * b1;
  c[id->id_x][id->id_y] = sum_elem;
}

void make_join(pthread_t *threads, int number_threads){
  for(int i = 0; i < number_threads; i++){
    pthread_join(threads[i], NULL);
  }
}

void iterate_matrix(){
  int result = 0;
  int count = 0;
  int count_threads = 0;
  int num_proc = system("cat /proc/cpuinfo | grep -c processor");
  pthread_t thread[9];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      identifier_t *id = malloc(sizeof(identifier_t));

      id->a0 = a[i][0];
      id->a1 = a[i][1];
      id->b0 = b[0][j];
      id->b1 = b[1][j];
      id->id_x = i;
      id->id_y = j;

      pthread_create(&thread[count], NULL, get_sum, id);
      count++;
      count_threads++;
      if (num_proc == count){
        make_join(thread, count_threads);
        count_threads = 0;
      }
    }
  }
}

void print_matrix(){
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
}

int main(int argc, const char *argv[]){
  iterate_matrix();
  print_matrix();
  return 0;
}
