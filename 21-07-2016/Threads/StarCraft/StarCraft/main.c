#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//CONSTANTS
#define WARRIOR 5
#define MINERALS 100

int current_minerals = 0;
int current_worriors = 0;
int minerals = MINERALS;
int comandcenter = 1;
int storage[20];

pthread_mutex_t ccenters[20];
pthread_mutex_t minerals_mined;

pthread_t threads[180];

void *worker(void *arg) {

	int thread_number = (int) arg;
	
	while (1) {
		printf("SCV %d is mining\n", thread_number);
		pthread_mutex_lock(&minerals_mined);
		if (minerals >= 8) {
			minerals -= 8;
		} else {
			pthread_mutex_unlock(&minerals_mined);
			break;	
		}
		pthread_mutex_unlock(&minerals_mined);
		
		printf("SCV %d is transporting minerals\n", thread_number);
		sleep(2);
		
		int j = 0;
		int ready = 0;
		while(ready < 1) {
			for (j = 0; j < comandcenter; j++) {
				pthread_mutex_lock(&ccenters[j]);
				storage[j] += 8;
				pthread_mutex_unlock(&ccenters[j]);
				ready += 1;
				break;
			}
			if (ready != 1) {
				sleep(1);
			}
		}
	}

	return NULL;
}

int main(int argc, char *argv[]){

	int personal_minerals = 0, i = 0;
	storage[0] = 0;

	pthread_mutex_init(&ccenters[0], NULL);
	pthread_mutex_init(&minerals_mined, NULL);	

	for (i = 0; i < 5; i++) {
		pthread_create(&threads[i], NULL, worker, (void *)(i + 1));
	}

	int k = 0; 
	char option[5];
	while (current_worriors < WARRIOR) {
		scanf("%s", option);
		for (k = 0; k < comandcenter; k++) {
			current_minerals += storage[k];
		}
		if (strcmp(option, "s") == 0) {
			if (current_minerals >= 50) {
				pthread_mutex_lock(&ccenters[0]);
					storage[0] -= 50;
				pthread_mutex_unlock(&ccenters[0]);
				personal_minerals += 50;
				pthread_create(&threads[i], NULL, worker, (void *)(i + 1));
				printf("Good to go sir.\n");
				i = i + 1;
			}
		}
		if (strcmp(option, "m") == 0) {
			if (current_minerals >= 50) {
				pthread_mutex_lock(&ccenters[0]);
					storage[0] -= 50;
				pthread_mutex_unlock(&ccenters[0]);
				personal_minerals += 50;
				printf("You wana piece of me boy.\n");
				i = i + 1;
			} else {
				printf("You can`t have piece of me boy.\n");
			}
		}
		current_minerals = 0;
	}

	for (k = 0; k < comandcenter; k++) {
		current_minerals += storage[k];
	}

	printf("%d\n", current_minerals);
	printf("%d\n", personal_minerals);

	pthread_mutex_destroy(&ccenters[0]);
	pthread_mutex_destroy(&minerals_mined);
	return 0;
}
