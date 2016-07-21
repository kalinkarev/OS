#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a = 100; // all gold on the MAP
int p = 0; // players gold

pthread_mutex_t m;
pthread_mutex_t mp;

void *work(void *arg) {
	int thread_num = (int) arg;
	
	while (1) {
		pthread_mutex_lock(&m);
		printf("Worker %d is transporting\n", thread_num);
		if (a >= 10) {
			a -= 10;
		} else {
			pthread_mutex_unlock(&m);
			break;
		}
		pthread_mutex_unlock(&m);
		sleep(2);
	
		pthread_mutex_lock(&mp);
		printf("Worker %d is putting into mine 1\n", thread_num);
		p += 10;
		pthread_mutex_unlock(&mp);
	}
	
	return NULL;
}

int main(int argc, char *argv[]) {

	int i;

	pthread_mutex_init(&m, NULL);
	pthread_mutex_init(&mp, NULL);
	
	pthread_t t[2];

	for (i = 0; i < 2; i++) {
		pthread_create(&t[i], NULL, work, (void*)(i + 1));
	}
	
	for (i = 0; i < 2; i++) { 
		pthread_join(t[i], NULL);
	}
	
	pthread_mutex_destroy(&m);
	pthread_mutex_destroy(&m);
	
	printf("map %d\n", a);
	printf("center %d\n", p);

	return 0;
}
