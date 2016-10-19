#include <time.h>
#include <string.h>
#include<pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <utime.h>
#include <sys/types.h>
#include <sys/time.h>

void* bkp_file(void* args){
  char** file = (char**)args;
  char command[50] = "cp ";
  strcat(command, *file);
  strcat(command, " ");
  strcat(command, *file);
  strcat(command, ".bkp");
  system(command);
  return NULL;
}

void print_file(struct stat file_stats, char *argv[]){
  printf("Filename: %s\n", argv[1]);
  printf("Time of last modification: %s", ctime(&file_stats.st_mtime));
  printf("Time of last acess: %s", ctime(&file_stats.st_atime));
  printf("File Permissions: ");
  printf((S_ISDIR(file_stats.st_mode)) ? "d" : "-");
  printf((file_stats.st_mode & S_IRUSR) ? "r" : "-");
  printf((file_stats.st_mode & S_IWUSR) ? "w" : "-");
  printf((file_stats.st_mode & S_IXUSR) ? "x" : "-");
  printf((file_stats.st_mode & S_IRGRP) ? "r" : "-");
  printf((file_stats.st_mode & S_IWGRP) ? "w" : "-");
  printf((file_stats.st_mode & S_IXGRP) ? "x" : "-");
  printf((file_stats.st_mode & S_IROTH) ? "r" : "-");
  printf((file_stats.st_mode & S_IWOTH) ? "w" : "-");
  printf((file_stats.st_mode & S_IXOTH) ? "x" : "-");
  printf("\n\n");
}

int main(int argc, char *argv[]) {
  pthread_t bkp_thread;
  pthread_create(&bkp_thread, NULL, &bkp_file, &argv[1]);
  struct stat file_stats;
  time_t mtime;
  struct utimbuf new_times;
  struct tm new_date = {0};

  char *full_date = malloc(13*sizeof(char));
  strcpy(full_date, argv[2]);

  char year_string[5];
  char month_string[3];
  char day_string[3];
  char hour_string[3];
  char minute_string[3];

  memcpy(year_string, &full_date[0], 4);
  year_string[4] = '\0';

  memcpy(month_string, &full_date[4], 6);
  month_string[2] = '\0';

  memcpy(day_string, &full_date[6], 8);
  day_string[2] = '\0';

  memcpy(hour_string, &full_date[8], 10);
  hour_string[2] = '\0';

  memcpy(minute_string, &full_date[10], 12);
  minute_string[2] = '\0';

  new_date.tm_year = atoi(year_string) - 1900;
  new_date.tm_mon = atoi(month_string) - 1;
  new_date.tm_mday = atoi(day_string);

  /* Limitations on hour of the summer */
  new_date.tm_hour = atoi(hour_string) - 1;
  new_date.tm_min = atoi(minute_string);

  mtime = mktime(&new_date);

  if(argc != 3)
    fprintf(stderr, "Use: ./run file.name AAAAMMDDHHmm\n"), exit(EXIT_FAILURE);

  if((stat(argv[1], &file_stats)) == -1) {
    perror("fstat");
    return 1;
  }

  print_file(file_stats, argv);

  pthread_join(bkp_thread, NULL);

  new_times.actime = mtime;
  new_times.modtime = mtime;
  utime(argv[1], &new_times);
  stat(argv[1], &file_stats);


  print_file(file_stats, argv);
  return 0;
}
