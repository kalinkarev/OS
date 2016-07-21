#include <stdio.h>
#include <sys/stat.h>

int main() {

// stat dopulnitelna informasiia

	struct stat s;
	
	int e = stat("stat.c", &s);
	if (e != 0) {
		perror("stat");
	}
	
	printf("%zd\n", s.st_size); // size of the directory

	return 0;
}
