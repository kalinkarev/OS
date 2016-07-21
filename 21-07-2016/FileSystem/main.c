#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[]) {

	char *path = argv[1];

	DIR *d = opendir(path);

	if (d == NULL) {
		perror("opendir");
	}

	struct dirent *p = readdir(d);	

	while (p != NULL) {
		if (p->d_type == DT_DIR) {
			printf("d ");
		} else {
			if (p->d_type == DT_REG) {
				printf("f ");
			} else {
				printf("? ");
			}
		}

		printf("%s\n", p->d_name);
		p = readdir(d);
	}
	
	closedir(d);
	return 0;
}
