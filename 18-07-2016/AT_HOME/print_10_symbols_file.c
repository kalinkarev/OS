#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 10

int main(int argc, char *argv[]) {
	//printf("Hello World!\n");
	char *path = argv[1];
	char buffer[BUFF_SIZE];
	char a = *argv[2], b = *argv[3];
	
	int fd = open(path, O_RDONLY);
	
	int i, ready = 1, c = 0;

	do {
		c = read(fd, buffer, BUFF_SIZE);
		
		for (i = 0; i < c; i++) {
			if (buffer[i] == a) {
				buffer[i] = b;
			}
		}
		
		write (STDOUT_FILENO, buffer, c);
	} while (c < BUFF_SIZE);

	close(fd);
	return 0;
}
