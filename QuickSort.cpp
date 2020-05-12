#include<iostream>
using namespace std;
int Partition(int[], int, int);
void QuickSort(int[], int, int);
void PrintList(int[], int);
int main()
{
	int a[] = { 10, 80, 30, 90, 40, 50, 70 }, n;
	n = sizeof(a) / sizeof(int);
	cout << "Array a before sorting:\n";
	PrintList(a, n);
	cout << "Array a after Quick Sort:\n";
	QuickSort(a, 0, n - 1);
	PrintList(a, n);
	return 0;
}
void PrintList(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int Partition(int a[], int p, int q)
{
	int pivot = a[q], i, j;
	i = p - 1;
	for (j = p; j < q; j++)
	{
		if (a[j] <= pivot)
		{
			i += 1;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[q]);
	return i + 1;
}
void QuickSort(int a[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}