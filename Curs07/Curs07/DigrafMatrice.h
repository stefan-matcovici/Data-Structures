#define Nmax 100
#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("Digraf.txt");
struct DigrafM
{
	int n,m;
	int a[Nmax][Nmax];
};
DigrafM DigrafMVid()
{
	DigrafM D;
	D.n = 0;
	D.m = 0;
	return D;
}
bool esteVidDigrafM(DigrafM D)
{
	return D.n == 0 && D.m == 0;
}
void afisareM(DigrafM D)
{
	for (int i = 0; i < D.n; i++)
	{
		for (int j = 0; j < D.n; j++)
			cout << D.a[i][j]<<" ";
		cout << endl;
	}
	cout << endl;
}
void insereazaVarfM(DigrafM &D)
{
	D.n++;
	for (int i = 0; i < D.n; i++)
	{
		D.a[i][D.n - 1] = 0;
		D.a[D.n-1][i] = 0;
	}
}
void insereazaMuchieM(DigrafM &D,int i,int j)
{
	D.m++;
	D.a[i][j] = 1;
}
DigrafM citesteDigrafM()
{
	DigrafM D;
	D = DigrafMVid();
	int nn,i,j;
	fin >> nn;
	for (i = 0; i < nn; i++)
	{
		insereazaVarfM(D);
	}
	while (fin >> i >> j)
	{
		D.m++;
		insereazaMuchieM(D, i, j);
	}
	return D;
}
void eliminaVarfM(DigrafM &D,int x)
{
	int i,j;
	for (i = 0; i < D.n; i++)
	{
		if (D.a[x][i] == 1)
			D.m--;
	}

	for (i = x + 1; i < D.n; i++)
	{
		for (j = 0; j < D.n; j++)
		{
			D.a[i - 1][j] = D.a[i][j];
		}
	}

	for (i = x + 1; i < D.n; i++)
	{
		for (j = 0; j < D.n; j++)
		{
			D.a[j][i-1] = D.a[j][i];
		}
	}

	D.n--;
}
void eliminaMuchieM(DigrafM &D,int i,int j)
{
	D.m--;
	D.a[i][j] = 0;
}
void detInchReflTranz(DigrafM D, DigrafM &B)
{
	int i, j, k;
	B.n = D.n;
	for (i = 0; i < D.n; i++)
	{
		for (j = 0; j < D.n; j++)
		{
			B.a[i][j] = D.a[i][j];
			if (i == j)
				B.a[i][j] = 1;
		}
	}
	for (k = 0; k < D.n; k++)
	{
		for (i = 0; i < D.n; i++)
		{
			if (B.a[i][k] == 1)
			{
				for (j = 0; j < D.n; j++)
					if (B.a[k][j])
						B.a[i][j] = 1;
			}
		}
	}
}
