// Project_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

void swap(int& a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void selection_sort(int A[], int imin, int imax)
{
	if (imin == imax)
		return;

	int para = imin;
	for (int i = imin + 1; i <= imax; i++)
		if (A[para] > A[i])
			para = i;

	if (para != imin)
		swap(A[para], A[imin]);

	return selection_sort(A, imin + 1, imax);
}

void bubble_sort(int A[], int imin, int imax)
{
	for (int i = 0; i <= imax; i++)
	{
		for (int j = imax; j > i; j--)
			if (A[j] < A[j - 1])
				swap(A[j], A[j - 1]);
	}
	//return;
}

int mid_point(int imin, int imax)
{
	return (imin + imax) / 2;
}

int binary_search(int A[], int key, int imin, int imax)
{
	if (imin > imax)
		return -1;

	if (imin == imax)
		if (A[imin] == key)
			return imin;
		else
			return -1;
	int imid = mid_point(imin, imax);

	if (key > A[imid])
		return binary_search(A, key, imid + 1, imax);
	else
		return binary_search(A, key, imin, imid);
}

int main()
{
	int n;
	cout << "n = ";
	cin >> n;

	int * A = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]:";
		cin >> A[i];
	}

	bubble_sort(A, 0, n - 1);
	cout << endl << "The sorted array is:" << endl;
	for (int i = 0; i < n; i++)
		cout << "A[" << i << "]:" << A[i] << endl;

	int key;
	cout << endl << "the key is:";
	cin >> key;

	cout << "the key order is:" << binary_search(A, key, 0, n - 1);
	delete[] A;

	_getch();
	return 0;
}

