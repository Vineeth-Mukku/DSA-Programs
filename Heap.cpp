#include<iostream>
#define Parent(i) (i - 1) / 2;
#define LChild(i) 2 * i + 1;
#define RChild(i) 2 * i + 2;
using namespace std;
void Insert(int[], int, int&);
void DeleteMax(int[]);
int ExtractMax(int[]);
void IncreaseKey(int[], int, int);
void DecreaseKey(int[], int, int);
int HeapSize;
void MaxHeapify(int[], int);
void BuildMaxHeap(int[], int);
void PrintList(int[], int);
int main()
{
	int a[] = { 1, 2, 5, 3, 4, 6, 7 }, n, i, x;
	n = sizeof(a) / sizeof(int);
	cout << "Array a before making it a heap:\n";
	PrintList(a, n);
	cout << "Building heap out of a. Here is how it looks:\n";
	BuildMaxHeap(a, n);
	PrintList(a, n);
	cout << "Max element in a is " << ExtractMax(a) << endl;
	cout << "Deleting Max element from a\n";
	DeleteMax(a);
	cout << "Now the heap looks as:\n";
	PrintList(a, HeapSize);
	cout << "Enter an element you want to insert into heap\n";
	cin >> x;
	Insert(a, x, n);
	cout << "Heap structure:\n";
	PrintList(a, HeapSize);
	cout << "Enter the index(0-indexing) of the element you want to increase the value of and the increased value of that element\n";
	cin >> i >> x;
	IncreaseKey(a, i, x);
	cout << "Heap structure:\n";
	PrintList(a, HeapSize);
	cout << "Enter the index(0-indexing) of the element you want to decrease the value of and the decreased value of that element\n";
	cin >> i >> x;
	DecreaseKey(a, i, x);
	cout << "Heap structure:\n";
	PrintList(a, HeapSize);
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
	int l, r, largest;
	l = LChild(i);
	r = RChild(i);
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
void BuildMaxHeap(int a[], int n)
{
	int i;
	HeapSize = n;
	for (i = n / 2 - 1; i >= 0; i--)
	{
		MaxHeapify(a, i);
	}
}
int ExtractMax(int a[])
{
	if (HeapSize > 0)
	{
		return a[0];
	}
	return -1;
}
void DeleteMax(int a[])
{
	if (HeapSize > 0)
	{
		swap(a[0], a[HeapSize - 1]);
		HeapSize -= 1;
		MaxHeapify(a, 0);
	}
}
void DecreaseKey(int a[], int i, int x)
{
	if (i >= 0 && i < HeapSize && a[i] > x)
	{
		a[i] = x;
		MaxHeapify(a, i);
	}
}
void IncreaseKey(int a[], int i, int x)
{
	if (i >= 0 && i < HeapSize && a[i] < x)
	{
		a[i] = x;
		while (i >= 0 && a[i] > a[(i - 1) / 2])
		{
			swap(a[i], a[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}
}
void Insert(int a[], int x, int& n)
{
	if (HeapSize == n)
	{
		a = (int*)realloc(a, (n + 1) * sizeof(int));
		n = n + 1;
	}
	HeapSize += 1;
	a[HeapSize - 1] = INT_MIN;
	IncreaseKey(a, HeapSize - 1, x);	
}