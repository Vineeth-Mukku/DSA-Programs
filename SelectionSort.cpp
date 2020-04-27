#include<iostream>
using namespace std;
void SelectionSort(int[], int);
int main()
{
	int a[] = {64, 25, 12, 22, 11}, i;
	cout << "Elements before sorting\n";
	for (i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\nElements after Selection Sort\n";
	SelectionSort(a, sizeof(a) / sizeof(int));
	for (i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
void SelectionSort(int a[], int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(a[i], a[min]);
		}
	}
}