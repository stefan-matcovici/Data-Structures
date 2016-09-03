//#include "Search.h"
#include <iostream>
using namespace std;
struct NodAVL
{
	int inf, ech;
	NodAVL *stg, *drp;
};
struct ArbAVL
{
	NodAVL* rad;
};

ArbAVL ArbAVLVid()
{
	ArbAVL A;
	A.rad = nullptr;
	return A;
}
NodAVL* newNodAVL(int e)
{
	NodAVL* p;
	p = new NodAVL;
	p->inf = e;
	p->drp = nullptr;
	p->stg = nullptr;
	p->ech = 0;
	return p;
}
bool EsteVid(ArbAVL A)
{
	return A.rad == nullptr;
}
int h(NodAVL* root)
{
	if (root != nullptr)
	{
		int hstg = h(root->stg);
		int hdrp = h(root->drp);
		if (hstg > hdrp)
			return hstg + 1;
		return hdrp + 1;
	}
	return 0;
}
void calculareFactor(NodAVL*p)
{
	int hstg = h(p->stg);
	int hdrp = h(p->drp);
	p->ech = hdrp - hstg;
}
NodAVL* rotatieSimplaStanga(NodAVL* x)
{
	NodAVL* y = x->drp;
	x->drp = y->stg;
	y->stg = x;
	calculareFactor(x);
	calculareFactor(y);
	return y;
}
NodAVL* rotatieSimplaDreapta(NodAVL* x)
{
	NodAVL* y = x->stg;
	x->stg = y->drp;
	y->drp = x;
	calculareFactor(x);
	calculareFactor(y);
	return y;
}
NodAVL* rotatieDublaDreapta(NodAVL* x)
{
	x->stg = rotatieSimplaStanga(x->stg);
	x = rotatieSimplaDreapta(x);
	return x;
}
NodAVL* rotatieDublaStanga(NodAVL* x)
{
	x->drp=rotatieSimplaDreapta(x->drp);
	x=rotatieSimplaStanga(x);
	return x;
}
NodAVL* echilibrare(NodAVL* p)
{
	calculareFactor(p);
	if (p->ech == -2)
	{
		if (p->stg != NULL)
		{
			if (p->stg->ech == 1)
				p = rotatieDublaDreapta(p);
			else
				p = rotatieSimplaDreapta(p);
		}
		else
			p = rotatieSimplaDreapta(p);
	}
		
	
	if (p->ech == 2)
	{
		if (p->drp != NULL)
		{
			if (p->drp->ech == -1)
				p = rotatieDublaStanga(p);
			else
				p = rotatieSimplaStanga(p);
		}
		else
			p = rotatieSimplaStanga(p);
		}
	return p;
}
NodAVL* insereaza(NodAVL*& p, int x)
{
	if (p == nullptr)
	{
		return newNodAVL(x);
	}
	else
	{
		if (x < p->inf)
			p->stg = insereaza(p->stg, x);
		else
		{
			if (x > p->inf)
				p->drp = insereaza(p->drp, x);
		}
	}
	return  echilibrare(p);
	//return p;
}
void afisare(NodAVL* p)
{
	cout << p->inf << " " << p->ech<<endl;
}
void parcurgereInordineAVL(NodAVL *p,void f(NodAVL*))
{
	if (p != nullptr)
	{
		parcurgereInordineAVL(p->stg,f);
		f(p);
		parcurgereInordineAVL(p->drp,f);
	}
}