#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thFun(void* arg)
{
	printf("This is thread #%lu\n", *(unsigned long*)arg);
	pthread_exit(NULL);
}

int main()
{
	int N;
  printf("Enter the number of threads: ");
  scanf("%d", &N);

	/*
	 * Order of printing is not defined. 
	 * Main thread can sometimes print first, 
	    and other times the new thread would print first
	 */

	for(int i=1; i<=N; i++)
	{
		pthread_t thID;
		pthread_create(&thID, NULL, thFun, &thID);
		printf("Created thread #%lu\n", thID);
	}	
	return 0;
}
