#include<iostream>
using namespace std;
void InsertionSort(int[], int);
int main()
{
	int a[] = { 4, 3, 2, 10, 12, 1, 5, 6 }, i, n;
	n = sizeof(a) / sizeof(int);
	cout << "Elements before sorting\n";
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\nElements after Insertion Sort\n";
	InsertionSort(a, n);
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
void InsertionSort(int a[], int n)
{
	int i, j, temp;
	for (j = 1; j < n; j++)
	{
		temp = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > temp)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = temp;
	}
}