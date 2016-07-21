#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFF_FOR_FIRST_10_SYMBOLS 10
#define ERROR_BUFF_SIZE 5

int main(int argc, char **argv) {
	char *filename = argv[1];
	char a = *argv[2], b = *argv[3];
	char buffer[BUFF_FOR_FIRST_10_SYMBOLS];
	int fd = open(filename, O_RDONLY);
	int i, ready = 1, c;

	if (argc < 2) {
	
		char usage[ERROR_BUFF_SIZE];
		strcpy(usage, "Usage: ");
		strcat(usage, argv[0]);
		strcat(usage, " FILE\n");
		
		write(STDERR_FILENO, usage, strlen((usage)));	
	
		return 1;
	}

/*
	while ((ready = read(fd, buffer, BUFF_FOR_FIRST_10_SYMBOLS)) > 0) {
		for (i = 0; i < ready; i++) {
			//write(STDOUT_FILENO, &buffer[i], 1);
		}

		while (c = write(STDOUT_FILENO, buffer, ready) > ready) {

		}
	}
*/	
	ssize_t readBytes = 0;

	do {
		readBytes = read(fd, buffer, BUFF_FOR_FIRST_10_SYMBOLS);
		
		for (i = 0; i < readBytes; i++) {
			if (buffer[i] == a) {
				buffer[i] = b;
			}
		}
		
		write(STDOUT_FILENO, buffer, readBytes);
	} while (readBytes < 10);

	close(fd);

	return 0;
}
