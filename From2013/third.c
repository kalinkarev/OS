#include <stdlib.h>
#include <stdio.h>

#define THREADS_NUM 5

int c = 0;

void *increment(void *arg)
{
	int i = 0;
	//size_t thread_num = (size_t) arg;
	
	int thread_num = (int) arg;
	
	//printf("Hello form %zd thread\n", thread_num);
	
	for (i = 0; i < 1000; i++)
	{
		c++;
	}
	
	printf("%d\n", c);
}

int main(int argc, char **argv) 
{
	int i;
	pthread_t t[THREADS_NUM];
	
	for (i = 0; i < THREADS_NUM; i++)
	{
		pthread_create(&t[i], NULL, increment, (void*)i);
	}

	for (i = 0; i < THREADS_NUM; i++)
	{
		pthread_join(t[i], NULL);
	}

	printf("Result: %d\n", c);

	return 0;
}
