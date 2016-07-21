#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t a;
pthread_t *gosho = &a; // address

void* ivan(void *h) {
	
	pthread_t *v = (pthread_t*) h;

	//int thread_customer = (int) h;
	printf("Hi!\n");
}

int main() {

	printf("Hello World!\n");

	pthread_create(gosho, NULL, ivan, gosho); // name, name of types

	pthread_join(a, NULL);

	//sleep(2);

	return 0;
}