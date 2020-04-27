#include<iostream>
using namespace std;
void Merge(int[], int, int, int);
void MergeSort(int[], int, int);
void PrintList(int[], int, int);
int main()
{
	int a[] = { 1, 5, 7, 8, 2, 4, 6, 9 }, n, i;
	n = sizeof(a) / sizeof(int);
	cout << "Elements before sorting:\n";
	PrintList(a, 0, n);
	cout << "\nElements after Merge sort:\n";
	MergeSort(a, 0, n - 1);
	PrintList(a, 0, n);
	return 0;
}
void PrintList(int a[], int p, int q)
{
	int i;
	for (i = p; i < q; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void Merge(int a[], int p, int q, int r)
{
	int n1, n2, i, j, k, * a1, * a2;
	n1 = q - p + 1;
	n2 = r - q;
	a1 = new int[n1 + 1];
	a2 = new int[n2 + 1];
	for (i = 0; i < n1; i++)
	{
		a1[i] = a[i + p];
	}
	a1[i] = INT_MAX;
	for (i = 0; i < n2; i++)
	{
		a2[i] = a[i + q + 1];
	}
	a2[i] = INT_MAX;
	i = 0;
	j = 0;
	for (k = p; k <= r; k++)
	{
		if (a1[i] <= a2[j])
		{
			a[k] = a1[i];
			i++;
		}
		else
		{
			a[k] = a2[j];
			j++;
		}
	}
}
void MergeSort(int a[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		MergeSort(a, p, q);
		MergeSort(a, q + 1, r);
		Merge(a, p, q, r);
	}
}