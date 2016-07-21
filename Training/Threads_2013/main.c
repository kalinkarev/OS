#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define GOLD_IN_MINE 50

int max_gold = GOLD_IN_MINE;
int gold_mine = GOLD_IN_MINE;

int current_warrior_gold = 0; // количеството злато, което е събрал всеки работник

pthread_mutex_t m;

void *work(void *arg) {
	int thread_num = (int) arg;
	
	while (current_warrior_gold < GOLD_IN_MINE) {	
		pthread_mutex_lock(&m);
			printf("Worker %d entered mine 1\n", thread_num);
			current_warrior_gold += 10;
			max_gold -= 10;
			printf("Worker %d exited mine 1\n", thread_num);
		pthread_mutex_unlock(&m);
		sleep(2);
	}
}

int main(int argc, char *argv[]) {
	int i;
	char workers = *argv[1];
	
	int num_workers = workers - '0';

	int num_threads = num_workers;

	pthread_t t[num_threads];

	pthread_mutex_init(&m, NULL);

	for (i = 0; i < num_threads; i++) {
		pthread_create(&t[i], NULL, work, (void *)(i + 1));
	}
	
	for (i = 0; i < num_threads; i++) {
		pthread_join(t[i], NULL);
	}

	printf("The gold in mine %d\t The worrior gold %d\n", gold_mine, current_warrior_gold);

	pthread_mutex_destroy(&m);
	return 0;
}
