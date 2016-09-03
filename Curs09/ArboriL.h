#include <iostream>
#include <string>
using namespace std;
typedef int elt;
struct NodA 
{
	elt inf;
	NodA* stg, *drp;
};
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
NodA* newNodA(elt e)
{
	NodA* p;
	p = new NodA;
	p->inf = e;
	p->drp = NULL;
	p->stg = NULL;
	return p;
}
