// to create 5 threads
// to make one loop from 1 to 1000
// to see what will be the result after the five threads
// Congratulations

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_t t[5];

int c = 0;

void *l(void *arg) {
	int thread_num = (int) arg;
	
//	for (c = 0; c < 1000; c++) {
//		printf("%d\n", c);
//	}

	printf("Thread number: %d\n", thread_num);
}

int main(int argc, char **argv) {
	
	int i = 0;

// Creates the threads	
	for (i = 0; i < 5; i++) {
		pthread_create(&t[i], NULL, l, (void*)(i + 1));		
		for (c = 0; c < 100; c++) {
			c++;
			printf("%d\n", c);
		}
	}

// Joint the threads	
	for (i = 0; i < 5; i++) {
		pthread_join(t[i], NULL);
	}

	printf("%d\n", c);
	
	return 0;
}
