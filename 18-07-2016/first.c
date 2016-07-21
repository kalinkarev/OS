#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
	int i;

	char param = *argv[1];

	int n = param - '0';

	char *path = argv[2];

	int p = argc - 3;

	char *args[] = {path, (char*) 0};

	//printf("%d\n", p);

	for (i = 0; i < n; i++) {
		pid_t pid = fork(); // New process 
		
		if (pid == 0) { // Child Process
				if (execv(path,args) == -1) {
					printf("Error!\n");
				}
				break;
		} else if (pid < 0) {
					printf(" - Failed to fork()\n");
		} else { // Parent Process
					int status;
					waitpid(pid, &status, 0);
		}
	}
	
	return 0;
}
