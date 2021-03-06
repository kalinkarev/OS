#include <stdio.h>
#include <stdlib.h>

#define THREADS_NUM 5

int c = 0;

pthread_mutex_t mutex;

void *increment(void *arg)
{
	int i = 0;
	int threads_num = (int) arg;
	
	pthread_mutex_lock(&mutex, NULL);
	for (i = 0; i < 1000; i++)
	{
		
		c++;
		
	}
	pthread_mutex_unlock(&mutex, NULL);
	
	printf("%d\n", c);
}

int main(int argc, char **argv)
{
	int j;

	pthread_t t[THREADS_NUM];

	pthread_mutex_init(&mutex, NULL);
	
	for (j = 0; j < THREADS_NUM; j++)
	{
		pthread_create(&t[j], NULL, increment, (void*)j);
	}

	for (j = 0; j < THREADS_NUM; j++)
	{
		pthread_join(t[j], NULL);
	}

	printf("Result: %d\n", c);

	pthread_mutex_destroy(&mutex);

	return 0;
}
