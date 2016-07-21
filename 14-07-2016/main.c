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

void linesInFile(int descriptor) {
	int ready = 1;
	char buffer[BUFF_SIZE];
	int i = 0;
	int count = 0;
	
	lseek(descriptor, 0, SEEK_SET);

	while ((ready = read(descriptor, buffer, BUFF_SIZE)) > 0) {
		for (i = 0; i < ready; i++) {
				write(STDOUT_FILENO, &buffer[i], 1);
		}
	}
}

int print(const char *filename) {
	int descriptor = openFile(filename);
	linesInFile(descriptor);
	close(descriptor);	
}

int main(int argc, char **argv) {
	
	int j = 0;
	
	for (j = 1; j < (argc - 2); j++) {
		print(argv[j]);
	}
	
	printf("\n");
	
//	printf("%s\n", argv[2]);
//	printf("%s\n", argv[3]);

	char a = *argv[2]; // dereference pointers
	char b= *argv[3];
	
	printf("%c\n", a);
	printf("%c\n", b);
	
	return 0;
}
