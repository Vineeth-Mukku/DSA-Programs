#include<iostream>
#include<algorithm>
using namespace std;
void CountingSort(int[], int, int);
void PrintList(int[], int);
void RadixSort(int[], int);
int main()
{
	int a[] = { 329, 457, 657, 839, 436 }, n;
	n = sizeof(a) / sizeof(int);
	cout << "The elements before sorting:\n";
	PrintList(a, n);
	cout << "\nThe elements after applying Radix Sort:\n";
	RadixSort(a, n);
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
void CountingSort(int a[], int n, int d)
{
	int* b, i, nod = pow(10, d - 1), c[10] = { 0 };
	b = new int[n]();
	for (i = 0; i < n; i++)
	{
		c[(a[i] / nod) % 10]++;
	}
	for (i = 1; i <= 9; i++)
	{
		c[i] += c[i - 1];
	}
	//Stable Sorting
	for (i = n - 1; i >= 0; i--)
	{
		b[c[(a[i] / nod) % 10] - 1] = a[i];
		c[(a[i] / nod) % 10]--;
	}
	for (i = 0; i < n; i++)
	{
		a[i] = b[i];
	}
}
void RadixSort(int a[], int n)
{
	int maxi = *max_element(a, a + n), d;
	for (d = 1; d <= (log10(maxi) + 1); d++)
	{
		CountingSort(a, n, d);
	}
}