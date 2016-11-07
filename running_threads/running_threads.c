#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int flag = 0;

void set_end_flag(int sig){
  flag = 1;
}

int main(){
  signal(SIGINT, set_end_flag); 
  while(1)  
    if(flag){
        printf("\nEncerrando a aplicação. Aguardando finalização de threads....\n");
        printf("\nAplicação encerrada com sucesso!\n Estatísticas: thread 1: XX linhas\n thread 2: YY linhas\n");
        return 0;
    }     
  return 1;
}  
