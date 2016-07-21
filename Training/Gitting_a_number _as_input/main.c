#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int i = 0, num;
	
	while (argv[1][i] != '\0') {
		num = num * 10 + argv[1][i] - 48;
		i++;
	}

	printf("The number is: %d\n", num);


	return 0;
}
