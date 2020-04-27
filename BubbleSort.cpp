#include<iostream>
using namespace std;
void BubbleSort(int[], int);
int main()
{
	int a[] = {5, 1, 4, 2, 8}, i;
	cout << "Elements before sorting\n";
	for (i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\nElements after Bubble Sort\n";
	BubbleSort(a, sizeof(a) / sizeof(int));
	for (i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
void BubbleSort(int a[], int n)
{
	int i, j;
	bool swapped = true;
	for (i = 1; i < n && swapped; i++)
	{
		swapped = false;
		for (j = 1; j <= n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				swap(a[j - 1], a[j]);
				swapped = true;
			}
		}
	}
}