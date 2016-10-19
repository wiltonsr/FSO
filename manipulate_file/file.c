#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
  struct stat file_stats;

  if(argc != 2)
    fprintf(stderr, "Use: ./run file.name AAAAMMDDHHmm\n"), exit(EXIT_FAILURE);

  if((stat(argv[1], &file_stats)) == -1) {
    perror("fstat");
    return 1;
  }

  printf("Filename: %s\n", argv[1]);
  printf("Time of last modification: %s", ctime(&file_stats.st_mtime));
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
  printf("\n");
  return 0;
}
