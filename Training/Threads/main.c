#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t m;

int turn = 2;

void *work(void *arg) {
	int *p = arg;
	int i;
	
	//for (i = 0; i < 10;) {
	while (1) {
		if (turn != *p) {
			pthread_mutex_lock(&m);
			printf("Hello from thread %d\n", *p);
			turn = *p;
			i++;
			pthread_mutex_unlock(&m);
			sleep(2);
		}
	}
	//}
}

int main(int argc, char *argv[]) {
	pthread_mutex_init(&m, NULL);
	int a = 1;
	int b = 2;
	int *pa = &a;
	int *pb = &b;
	pthread_t t;
	pthread_t t2;
	
	pthread_create(&t, NULL, work, pa);
	pthread_create(&t2, NULL, work, pb);
	
	pthread_join(t, NULL);
	pthread_join(t2, NULL);
	
	pthread_mutex_destroy(&m);
	return 0;
}


/*
void *work(void *arg) {
	int thread_num = (int) arg;
	
		pthread_mutex_lock(&m);
		printf("Hello from thread %d\n", thread_num);
		pthread_mutex_unlock(&m);
}

int main(int argc, char *argv[]) {
	pthread_mutex_init(&m, NULL);
	int i;
	pthread_t t[THREAD];
	
	while(1) {
		for (i = 0; i < THREAD; i++) {
			pthread_create(&t[i], NULL, work, (void *)(i + 1));
		}
		for (i = 0; i < THREAD; i++) {
			pthread_join(t[i], NULL);
		}	
		sleep(2);
	}

	pthread_mutex_destroy(&m);
	return 0;
}
*/
