#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MINERALS 1000
#define NUM_THREADS 5
#define WORRIORS 5

int a = MINERALS; // MINERALS ON THE MAP
int p = 0; // MINERALS OF THE PLAYER
int current_worriors = 0;

pthread_t t[5];

pthread_mutex_t ma; // MUTEX FOR THE MINERALS
pthread_mutex_t mp; // MUTEX FOR THE PLAYER`S MINERALS

void *worker(void *arg) {

	int thread_num = (int) arg;

	while ((a > 0) && (current_worriors < WORRIORS)) {
		pthread_mutex_lock(&ma);
			printf("SCV %d is mining\n", thread_num);
		if (a >= 8) {
			a -= 8;
		} else {
			pthread_mutex_unlock(&ma);
			break;	
		}
		printf("SCV %d is transporting minerals\n", thread_num);
		pthread_mutex_unlock(&ma);
		sleep(2);
	
		pthread_mutex_lock(&mp);
		p += 8;
		pthread_mutex_unlock(&mp);
		
	}
	return NULL;
}

int main(int argc, char *argv[]) {

	int personal_minerals = 0;

	pthread_mutex_init(&ma, NULL);
	pthread_mutex_init(&mp, NULL);
	
	int i;
	for (i = 0; i < NUM_THREADS; i++) {
		pthread_create(&t[i], NULL, worker, (void *)(i+1));
	}
	
	for (i = 0; i < NUM_THREADS; i++) {
		pthread_join(t[i], NULL);
	}

	char option[5];
	while(current_worriors < WORRIORS) {
		scanf("%s", &option);
		if (strcmp(option, "m") == 0) {
			if (p >= 50) {
				pthread_mutex_lock(&mp);
				p -= 50;
				pthread_mutex_unlock(&mp);
				sleep(1);
				personal_minerals += 50;
				current_worriors += 1;
				printf("You wanna piece of me boy\n");
			} else {
				printf("You can`t\n");
			}
		}
	}	
	
	pthread_mutex_destroy(&ma);
	pthread_mutex_destroy(&mp);

	printf("The minerals on the map are: %d\n", a);
	printf("The players minerals are: %d\n", p);

	return 0;
}
