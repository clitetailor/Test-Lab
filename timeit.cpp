#include <time.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char ** argv)
{
	clock_t t = clock();
	
	system(argv[1]);
	
	t = clock() - t;
	
	cout << (float) t/1000 << "s";
	return 0;
}