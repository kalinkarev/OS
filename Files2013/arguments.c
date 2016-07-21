#include <stdio.h>

int main(int argc, char **argv) {

	int i;
	int count = 0;

	for (i = 1; i < argc; i++) {
		count++;
		printf("%s\n", argv[i]);
	}
	
	printf("The number of inputs is/are: %d\n", count);

	return 0;
}
