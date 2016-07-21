#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS_NUM 5

void *print_hello(void *arg)
{
	size_t thread_num = (size_t)arg;
	
	printf("Hello from the %zd thread\n", thread_num);
}

int main(int argc, char **argv) 
{
	size_t i;
	pthread_t t[THREADS_NUM];
	
	for (i = 0; i < THREADS_NUM; i++)
	{
		pthread_create(&t[i], NULL, print_hello, (void*)i);
	}
	
//	sleep(2);
	
	for (i = 0; i < THREADS_NUM; i++) 
	{
		pthread_join(t[i], NULL);
	}

	return 0;
}
