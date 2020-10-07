//vmstat didn't work for me. i work on ubuntu for windows.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int *p = NULL;
	size_t s = 100*1024*1024;
	for(int i=0; i<10; i++)
	{
		p = malloc(s);
		if(p == NULL)
		{
			printf("Error occured!\n");
			exit(1);
		}
		memset(p, 0, s);
		sleep(1);
	}

	free(p);

	return 0;
} 
