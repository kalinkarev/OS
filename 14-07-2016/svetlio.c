#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	
	char *filename = argv[1];
	
	char a = *argv[2], b = *argv[3];
	
	char buf[100];
	
	int s, i, d, c;
	
	int fd = open(filename, O_RDONLY);
	
	while ((s = read(fd, buf, 100)) > 0) {
		for (i = 0; i < s; i++) {
			if (buf[i] == a) {
				buf[i] = b;
			}
		}
		while (c = write(STDOUT_FILENO, buf, s) > s){
			// ако е много голям прочита се целия файл 
		}
	}

	printf("------------------\n");

	printf("%c\n", a);
	printf("%c\n", b);

/*
	if (buf[0] == argv[2][0]) {
		buf[0] = argv[3][0];
	}
	write(STDOUT_FILENO, buf, s);
*/
	
//	printf("\n");

	close(fd);
	
	return 0;
}
