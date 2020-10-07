#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
	int *p = NULL;
	size_t s = 100*1024*1024;
	struct rusage usage;
	
	printf("| User CPU time (usec) | System CPU time (usec) | Page faults (w/o I/O) | Page faults (w/ I/O) | Context switches |\n");

	for(int i=0; i<10; i++)
	{
		p = malloc(s);
		if(p == NULL)
		{
			printf("Error occured!\n");
			exit(1);
		}
		memset(p, 0, s);

		getrusage(RUSAGE_SELF, &usage);
		printf("| %20ld | %22ld | %21ld | %20ld | %16ld |\n", usage.ru_utime.tv_usec, usage.ru_stime.tv_usec, usage.ru_minflt, usage.ru_majflt, usage.ru_nvcsw + usage.ru_nivcsw);
		sleep(1);
	}
	free(p);
	return 0;
} 
