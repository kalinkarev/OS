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
	char buffer[100];
	int i, ready, s;
	int fd = open(filename, O_RDONLY);
	
	while ((ready = read(fd, buffer, 100)) > 0) {
		for (i = 0; i < ready; i++) {
			if (buffer[i] == a) {
				buffer[i] = b;
			}
		}
		
		while (s = write(STDOUT_FILENO, buffer, ready) > ready) {
		
		}
	}

	return 0;
}
