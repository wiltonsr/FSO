#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void handler(int signal_number){
  printf("Son finished\n");
}

int main(void)
{
  int pid_son = fork(); //Create a son process

  if (pid_son == 0){ //The son process was sucessfuly created
    sleep(5); //Wait 5 second
    kill(getppid(), SIGALRM); //Kill the son process and send a SIGALRM
  }
  else if (pid_son < 0)
    perror("Error on fork call"); //The fork doesnt work
  else{ //The father process
    printf("Waiting for the SIGALRM from my son!\n");
    signal(SIGALRM, handler);
    pause(); //Wait for the SIGALRM from the son process
    printf("The SIGALRM arrived!\n");
  }

  return 0;
}
