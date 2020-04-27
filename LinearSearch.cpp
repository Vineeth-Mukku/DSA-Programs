#include<iostream>
using namespace std;
int LinearSearch(int[], int, int);
int main()
{
	int a[] = { 10, 20, 80, 30, 60, 50, 110, 100, 130, 170 }, n, x, pos, i;
	n = sizeof(a) / sizeof(int);
	cout << "Please enter the element you want to search among:\n";
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cin >> x;
	pos = LinearSearch(a, n, x);
	pos == -1 ? cout << x << " not found\n" : cout << x << " is found at position " << pos << endl;
	return 0;
}
int LinearSearch(int a[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			return i + 1;
		}
	}
	return -1;
}