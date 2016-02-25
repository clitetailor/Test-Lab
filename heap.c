#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap(int * a, int * b)
{
	int n = *b;
	*b = *a;
	*a = n;
}

int leftchildnode(int n)
{
	return 2 * n + 1;
}

int rightchildnode(int n)
{
	return 2 * n + 2;
}

int parentnode(int n)
{
	return (n-1) / 2;
}

void siftDown(int * a, int start, int count)
{
	int i = start;
	
	int imax = parentnode(count + 1);
	while (i < imax)
	{
		int currentnodeindex = i;
		int leftnodeindex = leftchildnode(i);
		int rightnodeindex = rightchildnode(i);
		
		if (leftnodeindex < count && a[leftnodeindex] < a[i])
		{
			i = leftnodeindex;
		}
		
		if (rightnodeindex < count && a[rightnodeindex] < a[i])
		{
			i = rightnodeindex;
		}
		
		if (i != currentnodeindex)
		{
			swap( &a[currentnodeindex] , &a[i] );
		}
		else
			break;
	}
}

void heapify(int * a, int count)
{
	int i;
	
	for (i = parentnode(count - 1); i > -1; --i)
	{
		siftDown(a, i, count);
	}
}


// Haven't heapify first
void heapsort(int * a, int count)
{
	int end = count - 1;
	
	while (end > 0)
	{
		swap( &a[0], &a[end]);
		siftDown(a, 0, end);
		--end;
	}
}

int main(int argc, char ** argv)
{
	//##########################################################//
	clock_t timing;
	timing = clock();
	//##########################################################//
	
	// Timing region
	
	// Declare and initialize
	time_t t;
	time(&t);
	srand((unsigned) t);
	
	int k;
	int n;
	int * a = (int *) malloc( k * sizeof(int) );
	
	// Get input
	printf("k:");
	scanf("%d", &k);
	printf("n:");
	scanf("%d", &n);
	
	n = n - k;
	
	
	// Generate numbers
	int i;
	for (i = 0; i < k; ++i)
	{
		a[i] = rand() * rand() * rand() % 1000000000;
	}
	
	// Heapify
	heapify(a, k);
	
	// Filt
	for (i = 0; i < n; ++i)
	{
		int new = rand() * rand() * rand() % 1000000000;
		
		if (new > a[0])
		{
			a[0] = new;
			siftDown(a, 0, k);
		}
	}
	
	// Sort array
	heapsort(a, k);
	
	//##########################################################//
	timing = clock() - timing;
	//##########################################################//
	
	for (i = 0; i < k; ++i)
	{
		printf("\n%d", a[i]);
	}
	
	printf("\n\n%f s\n", (float) timing / 1000);
	
	// Delete
	free(a);
	
	return 0;
}