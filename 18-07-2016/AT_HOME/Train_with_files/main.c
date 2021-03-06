#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 420

int main(int argc, char **argv) {

	char *filename = argv[1];
	char a = *argv[2], b = *argv[3];	
	char buffer[BUFF_SIZE];
	int filedescriptor = open(filename, O_RDONLY);

	int i, ready = 1, c = 0;

	do {
		c = read(filedescriptor, buffer, BUFF_SIZE);
		
		for (i = 0; i < c; i++) {
			if (buffer[i] == a) {
				buffer[i] = b;
			}
		}
		
		write(STDOUT_FILENO, buffer, c);
	} while (c != 0);

/*
	while ((ready = read(filedescriptor, buffer, BUFF_SIZE)) > 0) {
		for (i = 0; i < ready; i++) {
			write(STDOUT_FILENO, &buffer[i], 1);
		}
	}

/*
	while (c = write(STDOUT_FILENO, buffer, ready) > ready) {
	
	}
*/

	close(filedescriptor);
	return 0;
}
