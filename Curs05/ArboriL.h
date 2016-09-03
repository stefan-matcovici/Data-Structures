#include <iostream>
#include "Stive.h"
#include <string>
using namespace std;


struct ArbBin
{
	NodA* rad;
};
ArbBin ArbBinVid()
{
	ArbBin A;
	A.rad = NULL;
	return A;
}
bool EsteVid(ArbBin A)
{
	return A.rad == NULL;
}
void insereazaArbore(ArbBin &A,NodA *p, char c, elt e)
{
	if (p == NULL)
	{
		p = new NodA;
		p->inf = e;
		p->stg = NULL;
		p->drp = NULL;
		if (A.rad == NULL)
			A.rad = p;
	}
	else
	{
		NodA *q;
		q = new NodA;
		q->drp = NULL;
		q->stg = NULL;
		q->inf = e;
		if (p->drp == NULL || p->stg == NULL)
		{
			if (c == 'S' && p->stg == NULL)
				p->stg = q;
			else if (c == 'D' && p->drp == NULL)
				p->drp = q;
		}

	}
}
void parcurgerePreordine(NodA *p)
{
	if (p != NULL)
	{
		cout << p->inf<<" ";
		parcurgerePreordine(p->stg);
		parcurgerePreordine(p->drp);
	}
}
void parcurgereInordine(NodA *p)
{
	if (p != NULL)
	{
		parcurgereInordine(p->stg);
		cout << p->inf << " ";
		parcurgereInordine(p->drp);
	}
}
void parcurgerePostordine(NodA *p)
{
	if (p != NULL)
	{
		parcurgerePostordine(p->stg);
		parcurgerePostordine(p->drp);
		cout << p->inf << " ";
	}
}
/*void parcurgereBFS(NodA *p)
{
	Coada C;
	C = coadaVida();
	insereazaArboreC(C, p);
	while (!esteVida(C))
	{
		p = citesteC(C);
		eliminaC(C);
		if (p->stg != NULL)
			insereazaArboreC(C, p->stg);
		if (p->drp != NULL)
			insereazaArboreC(C, p->drp);
		cout << p->inf << " ";


	}
}
*/
void adresePreordine(NodA *p,string adr)
{
	if (p != NULL)
	{
		cout << adr << " ";
		adresePreordine(p->stg,adr+'1');
		adresePreordine(p->drp,adr+'0');
	}
}
int comp(NodA* t1, NodA* t2)
{
	if (t1 == NULL && t2 != NULL)
		return 1;
	if (t1->inf < t2->inf)
		return 1;
	if (comp(t1->stg, t2->stg) == 1)
		return 1;
	else return comp(t1->drp, t2->drp);
}
NodA* inpreorder(int in[], int pre[], int inStrt, int inEnd);
int frontiera(NodA *p)
{
	if (p != NULL)
	{
		if (p->stg == NULL && p->drp == NULL)
			return 1 + frontiera(p->stg) + frontiera(p->drp);
		else
			return frontiera(p->stg) + frontiera(p->drp);
	}
	return 0;
}
bool singlevalued(NodA* p,int &count)
{
	if (p != NULL)
	{
		bool s, d;
		s = singlevalued(p->stg,count);
		d = singlevalued(p->drp,count);

		if (s == false && d == false)
			return 0;

		if (p->stg != NULL)
		{
			if (p->stg->inf != p->inf)
				return 0;
		}

		if (p->drp != NULL)
		{
			if (p->drp->inf != p->inf)
				return 0;
		}

		count++;
		return 1;
	}
	return true;
}
NodA* newNodA(elt e)
{
	NodA* p;
	p = new NodA;
	p->inf = e;
	p->drp = NULL;
	p->stg = NULL;
	return p;
}
NodA* citire()
{
	char s[] = "A(B,C(D,E(F,G)))";

	NodA *p,*q,*r;
	Stiva S;
	stivaVida(S);
	p = NULL;
	q = p;
	r = p;
	p=newNodA(s[0]);
	push(S, p);

	int i = 1;
	while (i < strlen(s))
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			q = newNodA(s[i]);
			push(S, q);
		}
		else if (s[i] == '$')
			push(S, NULL);
		else if (s[i] == ')')
		{
			q = top(S); pop(S);
			r = top(S); pop(S);
			top(S)->drp = q;
			top(S)->stg = r;
		}
		i++;
	}
	return top(S);

}

void alkleaInordine(NodA* p,int k)
{
	static int contor = 0;
	if (p != NULL)
	{
		alkleaInordine(p->stg, k);
		contor++;
		if (k == contor)
			cout<< p->inf;

		if (contor<k)
			alkleaInordine(p->drp, k);
	}
}
void oglinda(NodA* t)
{
	if (t != NULL)
	{
		swap(t->stg, t->drp);
		oglinda(t->stg);
		oglinda(t->drp);

	}
}
int max(int a, int b)
{
	if (a < b)
		return b;
	return a;
}
int inaltime(NodA* t)
{
	if (t==NULL)
		return -1;
	else
		return 1 + max(inaltime(t->stg),inaltime(t->drp));
}
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
void minelem(NodA* t,int &mini)
{
	if (t != NULL)
	{
		if (t->inf < mini)
			mini = t->inf;
		minelem(t->stg, mini);
		minelem(t->drp, mini);
	}
}
void doubletree(NodA* t)
{
	if (t != NULL)
	{
		doubletree(t->stg);
		doubletree(t->drp);
		if (t->stg != NULL)
		{
			NodA* p;
			p = new NodA;
			p->inf = t->inf;
			p->stg = t->stg;
			p->drp = NULL;
			t->stg = p;
		}
		else
		{
			NodA* p;
			p = new NodA;
			p->inf = t->inf;
			p->stg = t->stg;
			p->drp = NULL;
			t->stg = p;
		}
		
	}
}