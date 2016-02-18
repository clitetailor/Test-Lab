#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void inserted_sort(int a[], int n)
{
	for (int i = 1; i<n; i++)
	{
		int j = i;
		int temp = a[i];g
		while(j != 0 && a[j - 1] > t)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}
	return ;
}

int main () {
	int a[10];
	int n;
	cout << "n = ";
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cout << endl << "a[" << i + 1 << "] = ";
		cin >> a[i];
	}
	
	system ("CLS");
	inserted_sort (a, n);
	
	for (int i = 0; i < n; i++) 
		cout << a[i] << " ";
		
	getch();
	return 0;
}