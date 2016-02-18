// Given an array of N numbers, implement an algorithm to find the biggest k numbers from the array. What is time and space complexity of your implementation? Run your program for N = 1000000000 and k = 600000 and it should finish within one minute. Note: You can use the rand() function in C to generate a random sequence of N numbers.

#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <conio.h>
using namespace std;


void inserted_sort(int a[], int n)
{
	clock_t t;
	
		t = clock();
	
	for (int i = 1; i < n; i++)
	{
		int j = i;
		int temp = a[i];
		while(j != 0 && a[j - 1] > temp)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
		
	}
		cout << (float) (clock() - t)/1000 << "s";
	return ;
}



int main(int argc, char ** argv)
{
	try
	{
		long long n, k;
		istringstream(argv[1]) >> n;
		istringstream(argv[2]) >> k;
		
		int * f = (int *) malloc( k * sizeof(int) );
		
		
		clock_t t = clock();
		
		for (int i = 0; i < k; i++)
		{
			f[i] = rand();
		}
		
		cout << (float) (clock() - t)/1000 << "s";
		getch();
		
		inserted_sort(f, k);
		
		for (int i = 0; i < k; i++)
		{
			cout << f[i] << endl;
		}
		
		free(f);
	}
	catch(exception e)
	{
		cout << e.what() << endl;
		return -1;
	}
	
	return 0;
}