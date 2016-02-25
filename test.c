#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MY_MAX_RAND 1000000000

int main()
{
	int i;
	
	srand(5000);
	printf("\n");
	for (i = 0; i < 100; ++i)
	{
		printf("%d   ", rand() * rand() % MY_MAX_RAND);
	}
	
	return 0;
} 