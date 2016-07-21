#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 420
#define BUFFER_NOT_FULL_CONTENT 10

int main(int argc, char **argv) {
	
	char buffer[BUFFER_SIZE];
	char *filename = argv[1];
	char a = *argv[2], b = *argv[3];

	int fd = open(filename, O_RDONLY); // only to read it
	int i, c;
	int ready = 1;
	
	while ((ready = read(fd, buffer, BUFFER_SIZE)) > 0) {
		for (i = 0; i < ready; i++) {
			if (buffer[i] == a) {
				buffer[i] = b;
			}
			
			//write(STDOUT_FILENO, &buffer[i], 1);
		}
		
		while (c = write(STDOUT_FILENO, buffer, ready) > ready) {
			
		}
	
	//	while (c = write(STDOUT_FILENO, &buffer[i], ready) > ready) {
		
	//	}
	}

	printf("-------------------------------------\n");

	printf("%c\n", a);
	printf("%c\n", b);

	return 0;
}
