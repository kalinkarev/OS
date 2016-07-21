#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
	char *path = argv[1];
	
	DIR *dir = opendir(path);

	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type == DT_REG) {
			printf("====>%s<====\n", entry->d_name);
			printf("---------------------------\n");
		}
	}
		
	closedir(dir);
	return 0;
}
