#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int i;
	char param = *argv[1];
	int num = param - '0';
	char *path = argv[2];
	
	char *args[] = {path, (char *) 0};
	
	for (i = 0; i < num; i++) {
		pid_t child = fork();
		
		if (child == 0) { // Child process
			if (execv(path, args) == -1) {
				perror("Error!\n");
			}
			break;
		} else if (child < 0) {
			perror("Error with forking...\n");
		} else { // Parent process
				int status;
				waitpid(child, &status, 0);			
		}
	}
	
	return 0;
}
