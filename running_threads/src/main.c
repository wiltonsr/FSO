#define _DEFAULT_SOURCE
#define ASCII_START 65
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>

int TERMINATE_FLAG = 0;
pthread_mutex_t lock;

void set_end_flag(int sig){
  TERMINATE_FLAG = 1;
}

struct info_thread_t{
  int number;
  int qtd_lines;
};

void *print_line(void *args){
  struct info_thread_t *info = (struct info_thread_t *) args;
  while(!TERMINATE_FLAG){
    pthread_mutex_lock(&lock);
    for (int i = 0; i <= info->number; i++){
      printf("%c", ASCII_START + info->number);
    }
    printf("\n");
    pthread_mutex_unlock(&lock);
    info->qtd_lines++;
    usleep(500000);
  }
}

int main(int argc, char *argv[]){

  if(argc != 2 || ((atoi(argv[1])) > 10) || ((atoi(argv[1])) < 1)){
    printf("Usage Error\n"
        "Use: ./run qtd_threads\n"
        "Where qtd_threads must be a integer between 1 and 10\n");
    exit(EXIT_FAILURE);
  }

  int MAX_THREAD = atoi(argv[1]);

  pthread_t thread[MAX_THREAD];
  struct info_thread_t info_thread[MAX_THREAD];

  for (int i = 0; i < MAX_THREAD; i++){
    info_thread[i].number = i;
    info_thread[i].qtd_lines = 0;
  }

  if (pthread_mutex_init(&lock, NULL) != 0){
    printf("Failed to init mutex\n");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < MAX_THREAD; i++){
    pthread_create(&thread[i], NULL, &print_line, &info_thread[i]);
  }

  while(!TERMINATE_FLAG){
    signal(SIGINT, set_end_flag);
  }

  if(TERMINATE_FLAG){
    printf("\nEncerrando a aplicação. Aguardando finalização de threads....\n");
    for (int i = 0; i < MAX_THREAD; i++){
      pthread_join(thread[i], NULL);
    }
    printf("Aplicação encerrada com sucesso!\n"
        "Estatísticas: \n");
    for (int i = 0; i < MAX_THREAD; i++){
      printf("Thread %d: %d linhas\n", i, info_thread[i].qtd_lines);
    }
    return 0;
  }

  pthread_mutex_destroy(&lock);

  return EXIT_SUCCESS;
}
