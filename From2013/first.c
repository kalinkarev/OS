#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *arg) 
{
	size_t thread_num = (size_t)arg;
	
    printf("Hello world! It's me - thread %zd\n", thread_num);

//	return 0;
}

int main(int argc, char **argv) 
{
	size_t i;
	pthread_t t[NUM_THREADS];
	
	for (i = 0; i < NUM_THREADS; i++) 
	{
		printf("Creating %zd thread:\n", i);
		
		int errno = pthread_create(&t[i], NULL, print_hello, (void*) i);
		
		if (errno != 0)
		{
			printf("ERROR Creating thread!\n");
		}
		
	}
	
	pthread_exit(NULL);
	
	return 0;
}
