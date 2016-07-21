#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int i;

	char param = *argv[1];
	int n = param - '0';
	printf("%d\n", n);

	char *path = argv[2];
	printf("%s\n", path);

	char *args[] = {path, (char*) 0};
	
	for (i = 0; i < n; i++) {
		pid_t pid = fork();
		
		if (pid == 0) {
			//printf("Hello from child!\n");
			if (execv(path, args) == -1) {
				printf("There is an error!\n");
			}
			break;
		} else if (pid < 0) {
			printf("Failed with the fork()\n");
		} else {
			//printf("Hello from parent!\n");
			int status;
			waitpid(pid, &status, 0);	
		}
	}

	return 0;
}
