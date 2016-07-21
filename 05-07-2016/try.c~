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

	pthread_t a[3];
	int i;
	for (i = 0; i < 3; i++) {
		pthread_create(&a[i], NULL, ivan, gosho); // name, name of types
	}
	
	for (i = 0; i < 3; i++) {
		pthread_join(a[i], NULL);
	}

	//sleep(2);

	return 0;
}
