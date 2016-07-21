#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {

	DIR* d = opendir("/dev");	
	
	if (d == NULL) {
		perror("opendir");
	}
	
	struct dirent *p = readdir(d); // pointer kam structura parvi fail

	while(p != NULL) { // da procheta tozi fail
	
		if (p->d_type == DT_DIR) {
			printf("d ");
		} else {
			if (p->d_type == DT_REG) {
				printf("f ");
			} else {
				printf("? ");
			}
		}
	
		//printf("%d\n", p->d_type);
		printf("%s\n", p->d_name);
		p = readdir(d); // vtori fail
	}
	
	closedir(d);	
	
	return 0;
}
