#include <iostream>
using namespace std;
#define NMAX 100
typedef int elt;
void parcurge(int a[], int n, int i)
{
	cout << a[i] << " ";
	if (2 * i + 1<n)
		parcurge(a, n, 2 * i + 1);
	if (2 * i + 2 < n)
		parcurge(a, n, 2 * i + 2);
}
void insereaza(int a[], int &n, elt cheie)
{
	int j, k;
	n = n + 1;
	a[n - 1] = cheie;
	j = n - 1;
	bool heap = false;
	while (j > 0 && !heap)
	{
		k = (j - 1) / 2;
		if (a[k] > a[j])
		{
			swap(a[k], a[j]);
			j = k;
		}
		else
			heap = true;
	}
}
void elimina(int a[], int &n)
{
	int j, k;
	a[0] = a[n - 1];
	n--;
	bool heap = false;
	j = 0;
	while ((2 * j + 1 < n) && !heap)
	{
		k = j * 2 + 1;
		if (k < n - 1 && a[k] > a[k + 1])
			k++;
		if (a[j] > a[k])
		{
			swap(a[j], a[k]);
			j = k;
		}
		else
			heap = true;
	}
}
bool minheap(int a[], int n, int i)
{

	if (2 * i + 1 <= n - 1)
	{
		if (a[i] < a[2 * i + 1] && a[i]<a[2 * i + 2] && minheap(a, n, 2 * i + 1) && minheap(a, n, 2 * i + 2))
			return 1;
		return 0;
	}
	return 1;
}
void kth(int k)
{
	int e,a[NMAX],i;
	cout << "K is " << k << endl;
	i = 0;
	while (1)
	{
		cout <<"Urmatorul element: ";
		cin >> e;
		if (i < k)
		{
			insereaza(a, i, e);
			for (int j = 0; j < i; j++)
				cout << a[j]<<" ";
			cout << endl;
		}
		else
		{
			if (e > a[0])
			{
				insereaza(a, i, e);
				elimina(a, i);
			}
			for (int j = 0; j < i; j++)
				cout << a[j]<<" ";
			cout << endl;
			cout << "Alklea element este: " << a[0]<<endl;
		}
	}
}