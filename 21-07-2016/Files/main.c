#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 420

int main(int argc, char *argv[]) {
	if (argc < 2) {
		perror("You should enter and a file\n");
	} else {
		char *filename = argv[1];
		char a = *argv[2], b = *argv[3];
		char buffer[BUFF_SIZE];
		int fd = open(filename, O_RDONLY);
		int i, c;
		
	     char message[100];
	     strcpy(message, "tail: cannot open `");
	     strcat(message, filename);
	     strcat(message, "` for reading: No such file or directory");

		if (fd < 0) {
			write(STDOUT_FILENO, message, strlen(message));
			return -1;
		}
		
		do {
			c = read(fd, buffer, BUFF_SIZE);
		
			for (i = 0; i < c; i++) {
				if (buffer[i] == a) {
					buffer[i] = b;
				}
			}
		
			write(STDOUT_FILENO, buffer, c);
		} while (c != 0);
	
		close(fd);
	}	
	return 0;
}
