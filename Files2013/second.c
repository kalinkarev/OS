#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 5

int main(int argc, char **argv) {
	int filedescriptor;
	
	char buffer[BUFF_SIZE];
	
	if (argc < 2) {
		return 1;
	}
	
	filedescriptor = open(argv[1], O_RDONLY);
	
	read(filedescriptor, buffer, BUFF_SIZE);
	
	write(STDOUT_FILENO, buffer, BUFF_SIZE);
	
	close(filedescriptor);
	
	return 0;
}
