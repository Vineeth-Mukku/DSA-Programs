#include<iostream>
using namespace std;
void MaxHeapify(int[], int);
void BuildMaxHeap(int[]);
void HeapSort(int[], int);
void PrintList(int[], int);
int HeapSize;
int main()
{
	int a[] = { 12, 11, 13, 5, 6, 7 }, n, i;
	n = sizeof(a) / sizeof(int);
	cout << "The elements before sorting:\n";
	PrintList(a, n);
	cout << "\nThe elements after applying Heap Sort:\n";
	HeapSort(a, n);
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
void MaxHeapify(int a[], int i)
{
	int l = 2 * i + 1, r = 2 * i + 2, largest;
	if (l < HeapSize && a[l] > a[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r < HeapSize && a[r] > a[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(a[i], a[largest]);
		MaxHeapify(a, largest);
	}
}
void BuildMaxHeap(int a[])
{
	int i;
	for (i = HeapSize / 2 - 1; i >= 0; i--)
	{
		MaxHeapify(a, i);
	}
}
void HeapSort(int a[], int n)
{
	int i;
	HeapSize = n;
	BuildMaxHeap(a);
	for (i = n - 1; i > 0; i--)
	{
		swap(a[0], a[HeapSize - 1]);
		HeapSize--;
		MaxHeapify(a, 0);
	}
}