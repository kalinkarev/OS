#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 420
#define ERROR_BUFF_SIZE 4096

int main(int argc, char **argv) {
	int fd;
	char buffer[BUFF_SIZE];
	
	if (argc < 2) {
		char usage[ERROR_BUFF_SIZE];
		
		strcpy(usage, "Usage: ");
		strcat(usage, argv[0]);
		strcat(usage, " FILE\n");
		
		write(STDERR_FILENO, usage, strlen(usage));
		return 1;
	}
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror(argv[1]);
		return 1;
	}
	
	ssize_t bytes_read = read(fd, buffer, BUFF_SIZE);
	while (bytes_read < BUFF_SIZE) {
		ssize_t current_bytes_read = read(fd, buffer + bytes_read, BUFF_SIZE - bytes_read);
		if (current_bytes_read == -1) {
			perror("read()");
			return 1;
		}
		
		bytes_read = bytes_read + current_bytes_read;
	}
	
	ssize_t bytes_written = write(STDOUT_FILENO, buffer, BUFF_SIZE);
	while (bytes_written < BUFF_SIZE) {
		ssize_t current_bytes_written = write(fd, buffer + bytes_written, BUFF_SIZE - bytes_written);
		if (current_bytes_written == -1) {
			perror("write()");
			return 1;
		}
		
		bytes_written = bytes_written + current_bytes_written;
	}
	
	int error = close(fd);
	if (error == -1) {
		perror("close()");
		return 1;
	}
	
	return 0;	
}
