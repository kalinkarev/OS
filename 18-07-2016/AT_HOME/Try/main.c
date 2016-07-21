#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i;
	char param = *argv[1];
	int num = param - '0';

	char *path = argv[2];

	char *args[] = {path, (char *) NULL};

	for (i = 0; i < num; i++) {
		pid_t pid = fork(); // Making new process
		
		if (pid == 0) {
			if (execv(path, args) == -1) {
				printf("Error!\n");
			}
			break;
		} else if (pid < 0) {
			perror("Error with forking...\n");
		} else {
			int status;
			waitpid(pid, &status, 0);
		}
	}		

	return 0;
}
