#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define THREADS_NUM 3

int c = 0;

void *change_number(void *arg)
{
	size_t thread_num = (size_t) arg;
	size_t result = 0;
	
	printf("Hello form %zd thread\n", thread_num);
	
	for (c = 0; c < 1000; c++)
	{
		result = result + random();
	}
	
	printf("The result is: %zd\n", result);
}

int main(int argc, char **argv) 
{	
	size_t i;
	pthread_t t[THREADS_NUM];
	
	for (i = 0; i < THREADS_NUM; i++) 
	{
		pthread_create(&t[i], NULL, change_number, (void*) i);
	}

	for (i = 0; i < THREADS_NUM; i++)
	{
		pthread_join(t[i], NULL);
	}

	return 0;
}
