#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

navigate_dir(char path[]){
    DIR *d;
    struct dirent *dir;
    d = opendir(path);

    if (d){
	while ((dir = readdir(d)) != NULL)
	{
	    char dir_name[265] = "";
	    strcat(dir_name, path);
	    strcat(dir_name, dir->d_name);
	    strcat(dir_name, "/");

	    if(!(strcmp(dir->d_name, ".") == 0))
		if(!(strcmp(dir->d_name, "..") == 0))
		    printf("%s\n", dir_name);

	    if(dir->d_type == 4)
		if(!(strcmp(dir->d_name, ".") == 0))
		    if(!(strcmp(dir->d_name, "..") == 0)){
			printf("%s\n", dir_name);
			navigate_dir(dir_name);
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

    navigate_dir(argv[1]);

    return 0;
}
