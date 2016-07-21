#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a = 100;
int p = 0;

pthread_mutex_t m;
pthread_mutex_t mp;

void *work(void *arg) {
	pthread_mutex_lock(&m);
	while (a > 0) {
		pthread_mutex_unlock(&m);
		
		int dig = 0; // ne sam kopal
		pthread_mutex_lock(&m);
		if (a >= 10) {
			a -= 10;
			dig = 1;
		}
		pthread_mutex_unlock(&m);
	
		if (dig == 1) { // ako ima oshte za kopane
			pthread_mutex_lock(&mp);
			p += 10;
			pthread_mutex_unlock(&mp);
		}
		pthread_mutex_lock(&m);
	}
	pthread_mutex_unlock(&m);
	
	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_mutex_init(&m, NULL);
	pthread_mutex_init(&mp, NULL);
	
	pthread_t t[2];
	pthread_create(&t[0], NULL, work, NULL);
	pthread_create(&t[1], NULL, work, NULL);
	
	pthread_join(t[0], NULL);
	pthread_join(t[1], NULL);
	
	pthread_mutex_destroy(&m);
	pthread_mutex_destroy(&m);
	
	printf("map %d\n", a);
	printf("center %d\n", p);
	
	//printf("The final gold is: %d\n", worrior_gold);

	return 0;
}
