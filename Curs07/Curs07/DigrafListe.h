#include <iostream>
#include <fstream>
#include "Stive.h"
#include "Cozi.h"
#include "Arbori.h"
using namespace std;
ifstream fin("Digraf2.txt");
#define Nmax 100
struct NodListaDigraf
{
	int elt;
	NodListaDigraf* succ;
};
struct DigrafL
{
	int n,m;
	NodListaDigraf* a[Nmax];
};


DigrafL DigrafLVid()
{
	DigrafL D;
	D.n = 0;
	D.m = 0;
	return D;
}
bool esteVidDigrafL(DigrafL D)
{
	return D.n == 0 && D.m == 0;
}
void afisareL(DigrafL D)
{
	NodListaDigraf *p;
	for (int i = 0; i < D.n; i++)
	{
		p = D.a[i];
		cout << i << ": ";
		while (p != NULL)
		{
			cout << p->elt<<" ";
			p = p->succ;
		}
		cout << endl;
	}
	cout << endl;
}
void insereazaVarfL(DigrafL &D)
{
	D.n++;
	D.a[D.n - 1] = NULL;
}
void insereazaMuchieL(DigrafL &D,int i,int j)
{
	D.m++;
	NodListaDigraf *p,*q;
	p = new NodListaDigraf;
	p->elt = j;
	p->succ = NULL;
	if (D.a[i] == NULL)
		D.a[i] = p;
	else if (D.a[i]->succ == NULL && D.a[i]->elt > j)
	{
		swap(D.a[i]->elt, p->elt);
		D.a[i]->succ = p;
	}
	else
	{
		q = D.a[i];
		while (q->succ != NULL && q->succ->elt < p->elt)
		{
			q = q->succ;
		}
		if (q->succ==NULL)
			q->succ = p;
		else
		{
			p->succ = q->succ;
			q->succ = p;
		}

	}

}
DigrafL citesteDigrafL()
{
	DigrafL D;
	D = DigrafLVid();
	int nn, i, j;
	fin >> nn;
	for (i = 0; i < nn; i++)
	{
		insereazaVarfL(D);
	}
	while (fin >> i >> j)
	{
		D.m++;
		insereazaMuchieL(D, i, j);
	}
	return D;
}
void eliminaVarfL(DigrafL &D, int x)
{
	int i;
	NodListaDigraf *p, *q;
	for (i = 0; i < D.n; i++)
	{
		if (D.a[i] != NULL)
		{
			if (D.a[i]->elt == x)
				D.a[i] = D.a[i]->succ;
			else
			{
				p = D.a[i];
				while (p->succ != NULL && p->succ->elt != x)
					p = p->succ;
				if (p->succ != NULL)
				{
					q = p->succ;
					p->succ = p->succ->succ;
					delete(q);
					D.m--;
				}
			}
		}
	}
	
	p = D.a[x];
	if (p != NULL)
	{
		while (p->succ != NULL)
		{
			q = p;
			p = p->succ;
			delete(q);
		}
		delete(p);
	}

	for (i = x + 1; i < D.n; i++)
	{
		D.a[i - 1] = D.a[i];
	}
	D.n--;

}
void eliminaMuchieL(DigrafL &D, int i, int j)
{
	NodListaDigraf *p,*q;
	
	if (D.a[i]->elt == j)
	{
		D.a[i] = D.a[i]->succ;
	}
	else
	{
		p = D.a[i];
		while (p->succ->elt != j)
		{
			p = p->succ;
		}
		q = p->succ;
		p->succ = p->succ->succ;
		delete(q);
	}
		
}
void DFS(DigrafL D,int i0)
{
	int i = 0, j, S[Nmax];
	NodListaDigraf *a[Nmax];

	DigrafL ArboreDfs;
	ArboreDfs = DigrafLVid();
	for (i = 0; i < D.n;i++)
		insereazaVarfL(ArboreDfs);

	Stiva SB;
	stivaVida(SB);
	for (i = 0; i < D.n; i++)
		S[i] = 0;

	for (i = 0; i < D.n; i++)
		a[i] = D.a[i];

	push(SB, i0);
	S[i0] = 1;

	while (!esteVida(SB))
	{
		i = top(SB);
		if (a[i] == NULL)
			pop(SB);
		else
		{
			j = a[i]->elt;
			a[i] = a[i]->succ;
			if (S[j] == 0)
			{
				insereazaMuchieL(ArboreDfs, top(SB), j);
				cout << j << " ";
				push(SB, j);
				S[j] = 1;
			}
		}
	}
	cout << endl;
	afisareL(ArboreDfs);
}
void BFS(DigrafL D, int i0)
{
	int i = 0, j, S[Nmax];
	NodListaDigraf *a[Nmax];

	DigrafL ArboreBfs;
	ArboreBfs = DigrafLVid();
	for (i = 0; i < D.n; i++)
		insereazaVarfL(ArboreBfs);

	ArbBin B;
	B = arborevid();

	Coada SB;
	coadaVida(SB);
	for (i = 0; i < D.n; i++)
		S[i] = 0;

	for (i = 0; i < D.n; i++)
		a[i] = D.a[i];

	insereaza(SB, i0);
	S[i0] = 1;
	while (!esteVida(SB))
	{
		i = citeste(SB);
		if (a[i] == NULL)
			elimina(SB);
		else
		{
			j = a[i]->elt;
			a[i] = a[i]->succ;
			if (S[j] == 0)
			{
				insereazaMuchieL(ArboreBfs, citeste(SB), j);
				cout << j << " ";
				insereaza(SB, j);
				S[j] = 1;
			}
		}
	}
	cout << endl;
	afisareL(ArboreBfs);
}