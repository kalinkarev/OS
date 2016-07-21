#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t a;
pthread_t *t = &a;

// връща    //приема
void *print(void *arg) {
	printf("Hello from thread!\n");	
}

int main(int argc, char **argv) {

	printf("Hello World!\n");

	pthread_create(t, NULL, print, t);

	sleep(2);

	return 0;
}
