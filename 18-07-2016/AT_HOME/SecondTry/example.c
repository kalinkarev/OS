#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	//printf("Hello World!\n");
	char param = *argv[1];
	int n = param - 48;
	//printf("%d\n", n);
	int i;
	char *path = argv[2];
	//printf("%s\n", path);
	char *args[] = {path, (char *) NULL};
	
	for (i = 0; i < n; i++) {
		pid_t pid = fork();
		
		if (pid == 0) {
			//printf("Hello from child!\n");
			if (execv(path, args) == -1) {
				printf("There is an error!\n");
			}
			break;
		} else if (pid < 0) {
			printf("Error while forking.\n");
		} else {
			//printf("Hello from parent!\n");
			int status;
			waitpid(pid, &status, 0);
		}
	}

	return 0;
}
