#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

int count = 0;

void print_30_bytes(char path[256], char word[256], const int max_words){
    if (count == max_words) return;
    if (!strstr(path, word)) return;

    FILE* sigD = fopen(path, "r");
    char *sig[255];
    fread(sig, 1, sizeof(sig), sigD);
    count++;
    printf("%d. %s --\n", count, path);
    printf("\t%s", sig);
}

navigate_dir(char path[], char word[256], const int max_words){

    DIR *d;
    struct dirent *dir;
    d = opendir(path);

    if (d){
	while ((dir = readdir(d)) != NULL)
	{
	    char dir_name[256] = "";
	    strcat(dir_name, path);
	    strcat(dir_name, dir->d_name);

	    if(!(strcmp(dir->d_name, ".") == 0)){
		if(!(strcmp(dir->d_name, "..") == 0)){

		    if(dir->d_type == 4){
			strcat(dir_name, "/");
			navigate_dir(dir_name, word, max_words);
		    }
		    else{
			print_30_bytes(dir_name, word, max_words);
		    }
		}
	    }
	}
	closedir(d);
    }
}

int main(int argc, char *argv[])
{

    if(argc != 4){
	printf("Use: ./buscador /path/to/want word_to_seek number_max\n");
	exit(EXIT_FAILURE);
    }
    const int max_words = atoi(argv[3]);

    navigate_dir(argv[1], argv[2], max_words);

    return 0;
}
