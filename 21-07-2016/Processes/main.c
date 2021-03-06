#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	char param = *argv[1];
	int num = param - 48;
	char *path = argv[2];
	char *args[] = {path, (char *) NULL};
	int i;
	
	for (i = 0; i< num; i++) {
		pid_t pid = fork();
		
		if (pid == 0) {
			if (execv(path, args) == -1) {
				perror("There is a problem with exec\n");
			}
			break;
		} else if (pid < 0) {
				printf("Error!\n");
		} else {
			int status;
			waitpid(pid, &status, 0);
		}
	}
	return 0;
}
