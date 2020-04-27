#include<iostream>
using namespace std;
int BinarySearch(int[], int, int, int);
int main()
{
	int a[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 }, n, x, pos, i;
	n = sizeof(a) / sizeof(int);
	cout << "Please enter the element you want to search among:\n";
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cin >> x;
	pos = BinarySearch(a, 0, n - 1, x);
	pos == -1 ? cout << x << " not found\n" : cout << x << " is found at position " << pos << endl;
	return 0;
}
int BinarySearch(int a[], int l, int r, int x)
{
	int mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (a[mid] == x)
		{
			return mid + 1;
		}
		else if (a[mid] > x)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return -1;
}