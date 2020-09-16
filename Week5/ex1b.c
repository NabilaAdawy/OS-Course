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

	for(int i=1; i<=N; i++)
	{
		pthread_t thID;
		pthread_create(&thID, NULL, thFun, &thID);
		printf("Created thread #%lu\n", thID);
    pthread_join(thID, NULL);

    /* The ID printed is the same for all of them, 
		   since the previous one exited and the ID can be reused
		*/
	}	
	return 0;
}
