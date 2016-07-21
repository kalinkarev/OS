#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 5
#define ERROR_BUFF_SIZE 4096

int main(int argc, char **argv) {
	
	int fd;
	char buffer[BUFF_SIZE];
	
	if (argc < 2) {
		char usage[ERROR_BUFF_SIZE];
		
		strcpy(usage, "Usage: ");
		strcat(usage, argv[0]);
		strcat(usage, " FILE\n");
		
		write(STDERR_FILENO, usage, strlen((usage)));
		return 1;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror(argv[1]);
		return 1;
	}
	
	read(fd, buffer, BUFF_SIZE);
	write (STDOUT_FILENO, buffer, BUFF_SIZE);

	write(STDOUT_FILENO, "\n", 1);
	
	int error = close(fd);
	if (error == -1) {
		perror("close()");
		return 1;
	}

	return 0;
}
