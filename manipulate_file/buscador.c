#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

void print_30_bytes(char path[256]){
    size_t* length;
    *length = 30 * sizeof(char*);
    char* buffer;
    int fd = open(path, O_RDONLY);
    lseek (fd, 0, SEEK_SET);
    read (fd, length, sizeof (*length));
    buffer = (char*) malloc (*length);
    read (fd, buffer, *length);
    close (fd);
}

navigate_dir(char path[]){
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
			navigate_dir(dir_name);
		    }
		    else{
			print_30_bytes(dir_name);
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

    navigate_dir(argv[1]);

    return 0;
}
