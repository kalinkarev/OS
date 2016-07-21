#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_MINERALS 50
#define FARM_COST 200

int a = NUM_MINERALS; // minerals on the map
int p = 0; // minerals of the user
int player_farms = 0;

pthread_t farm_buyer_thread;
 
pthread_mutex_t ma; // mutex for the map minerals
pthread_mutex_t mp; // mutex for the player minerals

void *worker(void *arg) {
	int new_thread = (int) arg;
	
	while(1) {
		pthread_mutex_lock(&ma);
		if (a >= 10) {
			printf("Worker %d is entering mine 1.\n", new_thread);
			a -= 10;
			printf("Worker %d is exiting mine 1.\n", new_thread);
		} else {
			pthread_mutex_unlock(&ma);
			break;	
		}
		pthread_mutex_unlock(&ma);
		sleep(2);
		
		pthread_mutex_lock(&mp);
		printf("Worker %d is putting into mine 1.\n", new_thread);
		p += 10;
		pthread_mutex_unlock(&mp);
	}
		
	return NULL;
}

void *farmbuyer(void *arg) {
	int next = (int) arg;
	printf("FarmBuyer %d created!\n", next);
	while(player_farms != 20){
		 pthread_mutex_lock(&mp);
		 	if(p >= FARM_COST){
		 		p = p - FARM_COST;
		 	}
		 	pthread_mutex_unlock(&mp);
		 	// SIMULATE TIME FOR BUILDING FARMS
		 	player_farms = player_farms + 1;
		 }
	}
	printf("FarmBuyer %d finished!\n", next);
	return NULL;
}

int main(int argc, char *argv[]){

	int i = 0, num;
	while (argv[1][i] != '\0') {
		num = num * 10 + argv[1][i] - 48;
		i++;
	}

	// workers from the input
	char param = *argv[2];
	int n = param - 48;
	
	pthread_mutex_init(&ma, NULL);
	pthread_mutex_init(&mp, NULL);

	pthread_t thread[n];
	int j;
	
	for (j = 0; j < n; j++) {
		pthread_create(&thread[j], NULL, worker, (void *)(j + 1));
	}
	pthread_create(&farm_buyer_thread, NULL, farmbuyer, (void*) 1);
	
	for (j = 0; j < n; j++) {
		pthread_join(thread[j], NULL);
	}
	pthread_join(farm_buyer_thread, NULL, farmbuyer, (void *) 1);

	pthread_mutex_destroy(&ma);
	pthread_mutex_destroy(&mp);

	printf("The gold in the mine is %d\n", a);
	printf("The gold in the player is %d\n", p);

	return 0;
}
