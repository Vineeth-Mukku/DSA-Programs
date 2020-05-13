#include<iostream>
#include<algorithm>
using namespace std;
void CountingSort(int[], int, int[], int);
void PrintList(int[], int);
int main()
{
	int a[] = { 2, 5, 3, 0, 2, 3, 0, 3 }, n, k;
	n = sizeof(a) / sizeof(int);
	int* b = new int[n];
	k = *max_element(a, a + n);
	cout << "The elements before sorting:\n";
	PrintList(a, n);
	cout << "\nThe elements after applying Counting Sort:\n";
	CountingSort(a, n, b, k);
	PrintList(b, n);
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
void CountingSort(int a[], int n, int b[], int k)
{
	int *c, i;
	c = new int[k + 1]();
	for (i = 0; i < n; i++)
	{
		c[a[i]]++;
	}
	for (i = 1; i <= k; i++)
	{
		c[i] += c[i - 1];
	}
	for (i = n - 1; i >= 0; i--)
	{
		b[c[a[i]] - 1] = a[i];
		c[a[i]]--;
	}
}