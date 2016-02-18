#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char ** argv)
{
	try
	{
		srand(time(NULL));
		
		ofstream inp;
		inp.open("input");
		
		int n;
		
		istringstream(argv[1]) >> n;
		
		for (int i = 0; i < 10000; i++)
		{
			inp << (int) rand() << " ";
		}
		
		inp.close();
	}
	catch (exception e)
	{
		cout << e.what();
	}
};