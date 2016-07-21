#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 2

pthread_t t[NUM_THREADS];

pthread_mutex_t mutex;

void *work(void *arg) {
	int num_thread = (int) arg;
	
	pthread_mutex_lock(&mutex, NULL);
		printf("Hello from thread %d\n", num_thread);
	pthread_mutex_unlock(&mutex, NULL);
	
}

int main(int args, char **argv) {

	int i = 0;
	
	pthread_mutex_init(&mutex, NULL);
	
	while(1) {
	
		for (i = 0; i < NUM_THREADS; i++) {
			pthread_create(&t[i], NULL, work, (void*)i);
		}

		for (i = 0; i < NUM_THREADS; i++) {
			pthread_join(t[i], NULL);
		}
		
		sleep(2);
	}
	
	return 0;
}
