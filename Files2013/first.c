/*#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 5

int main(int argc, char **argv) {

	int fd;
	char buff[BUFF_SIZE];
	
	fd = open("test.txt", O_RDONLY);
	
	read(STDOUT_FILENO, buff, BUFF_SIZE);
	
	close(fd);

	return 0;
}
*/



#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 420

int openFile(const char *filename) {
	int descriptor = open(filename, O_RDONLY);
}

void linePrint(int descriptor) {
	int ready = 1;
	char buff[BUFF_SIZE];
	int i = 0;
	
	lseek(descriptor, 0, SEEK_SET);
	
	while ((ready = read(descriptor, buff, BUFF_SIZE)) >0 ) {
		for (i = 0; i < ready; i++) {
			write(STDOUT_FILENO, &buff[i], 1);
		}
	}
}

void tail(const char *filename) {
	int descriptor = openFile(filename);
	linePrint(descriptor);
	close(descriptor);
}

int main(int argc, char **argv) {
	
	int j = 0;
	
	for (j = 1; j < argc; j++) {
		printf("-----");
		tail(argv[j]);
	}

	return 0;
}
