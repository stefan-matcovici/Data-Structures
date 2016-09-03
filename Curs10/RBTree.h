#include <iostream>
#include <string>
using namespace std;
typedef int elt;
struct NodRB
{
	elt inf;
	NodRB *stg, *drp,*pred;
	string culoare;
};
struct ArbRB
{
	NodRB* rad;
	NodRB* nil;
};
ArbRB ArbRBVid()
{
	ArbRB A;
	A.nil = new NodRB;
	A.nil->culoare = "negru";
	A.rad = A.nil;
	return A;
}
bool EsteVid(ArbRB A)
{
	return A.rad == NULL;
}
NodRB* newNodRB(ArbRB t,int e)
{
	NodRB* p;
	p = new NodRB;
	p->inf = e;
	p->drp = t.nil;
	p->stg = t.nil;
	p->culoare = "rosu";
	return p;
}
void rotatieStanga(ArbRB &t,NodRB* x)
{
	NodRB* y = x->drp;
	x->drp = y->stg;
	if (y->stg != t.nil)
		y->stg->pred = x;
	y->pred = x->pred;

	if (x->pred == t.nil)
	{
		t.rad = y;
	}
	else
		if (x == x->pred->stg)
			x->pred->stg = y;
		else
			x->pred->drp = y;

	y->stg = x;
	x->pred = y;
}
void rotatieDreapta(ArbRB &t,NodRB* x)
{
	NodRB* y = x->stg;
	x->stg = y->drp;
	if (y->drp != t.nil)
		y->drp->pred = x;
	y->pred = x->pred;

	if (x->pred == t.nil)
	{
		t.rad = y;
	}
	else
		if (x == x->pred->stg)
			x->pred->stg = y;
		else
			x->pred->drp = y;

	y->drp = x;
	x->pred = y;
}
void insereazaFixRB(ArbRB &t, NodRB* z)
{
	if (z == t.rad)
	{
		t.rad->culoare = "negru";
		return;
	}

	while (!(z->pred->culoare.compare("rosu")))
	{
		if (z->pred == z->pred->pred->stg)
		{
			NodRB* y = z->pred->pred->drp;
			if (!(y->culoare.compare("rosu")))
			{
				z->pred->culoare = "negru";
				z->pred->pred->drp->culoare = "negru";
				z->pred->pred->culoare = "rosu";
				z = z->pred->pred;
			}
			else
			{
				if (z == z->pred->drp)
				{
					z = z->pred;
					rotatieStanga(t,z);
				}
				z->pred->culoare = "negru";
				z->pred->pred->culoare = "rosu";
				rotatieDreapta(t,z->pred->pred);
			}
		}
		else
		{
			NodRB* y = z->pred->pred->stg;
			if (!(y->culoare.compare("rosu")))
			{
				z->pred->culoare = "negru";
				z->pred->pred->stg->culoare = "negru";
				z->pred->pred->culoare = "rosu";
				z = z->pred->pred;
			}
			else
			{
				if (z == z->pred->stg)
				{
					z = z->pred;
					rotatieDreapta(t,z);
				}
				z->pred->culoare = "negru";
				z->pred->pred->culoare = "rosu";
				rotatieStanga(t,z->pred->pred);
			}
		}
	}
	t.rad->culoare = "negru";
}
void insereazaRB(ArbRB& t, int key)
{
	NodRB* x = t.rad;
	NodRB* y = t.nil;
	NodRB* z = newNodRB(t,key);
	while (x != t.nil)
	{
		y = x;
		if (key < x->inf)
			x = x->stg;
		else
			x = x->drp;
	}
	z->pred = y;
	if (y == t.nil)
	{
		t.rad = z;
	}
	else
		if (key < y->inf)
			y->stg = z;
		else
			y->drp = z;
	insereazaFixRB(t, z);
}
void succesor(ArbRB t,NodRB* root, NodRB*& suc, int key)
{
	if (root == t.nil)
		return;
	if (root->inf == key)
	{
		if (root->drp != t.nil)
		{
			NodRB* aux = root->drp;
			while (aux->stg != t.nil)
				aux = aux->stg;
			suc = aux;
		}
		return;
	}
	if (root->inf > key)
	{
		suc = root;
		succesor(t,root->stg, suc, key);
	}
	else
		succesor(t,root->drp, suc, key);
}
void stergeFixRB(ArbRB &t, NodRB* x)
{
	while (x != t.rad && !(x->culoare.compare("negru")))
	{
		if (x == x->pred-> stg)
		{
			NodRB* w = x->pred->drp;
			if (!(w->culoare.compare("rosu")))
			{
				w->culoare = "negru";
				x->pred->culoare = "rosu";
				rotatieStanga(t, x->pred);
				w = x->pred->drp;
			}
			if (!(w->stg->culoare.compare("negru")) && !(w->drp->culoare.compare("negru")))
			{
				w->culoare = "rosu";
				x = x->pred;
			}
			else
			{
				if (!(w->drp->culoare.compare("negru")))
				{
					w->culoare = "rosu";
					w->stg->culoare = "negru";
					rotatieDreapta(t,w->stg);
					w = x->pred->drp;
				}
				w->culoare = x->pred->culoare;
				w->drp->culoare = "negru";
				x->pred->culoare = "negru";
				rotatieStanga(t,x->pred);
				x = t.rad;
			}
		}
		else
		{
			NodRB* w = x->pred->stg;
			if (!(w->culoare.compare("rosu")))
			{
				w->culoare = "negru";
				x->pred->culoare = "rosu";
				rotatieDreapta(t, x->pred);
				w = x->pred->drp;
			}
			if (!(w->drp->culoare.compare("negru")) && !(w->stg->culoare.compare("negru")))
			{
				w->culoare = "rosu";
				x = x->pred;
			}
			else
			{
				if (!(w->stg->culoare.compare("negru")))
				{
					w->culoare = "rosu";
					w->drp->culoare = "negru";
					rotatieDreapta(t, w->drp);
					w = x->pred->stg;
				}
				w->culoare = x->pred->culoare;
				w->stg->culoare = "negru";
				x->pred->culoare = "negru";
				rotatieDreapta(t, x->pred);
				x = t.rad;
			}
		}
	}
	x->culoare = "negru";
}
void stergeRB(ArbRB t, NodRB* z)
{
	NodRB* y,*x;
	if (z->stg == t.nil || z->drp == t.nil)
		y = z;
	else
		succesor(t,t.rad, y, z->inf);

	if (y->stg != t.nil)
		x = y->stg;
	else
		x = y->drp;

	x->pred = y->pred;


	if (y->pred == t.nil)
		t.rad = x;
	else
		if (y == y->pred->stg)
			y->pred->stg = x;
		else
			y->pred->drp = x;
	
	if (y != z)
		z->inf = y->inf;
	if (!(y->culoare.compare("negru")))
		stergeFixRB(t, x);
	//return y;
}
void parcurgereInordineRB(ArbRB t,NodRB *p)
{
	if (p != t.nil)
	{
		parcurgereInordineRB(t,p->stg);
		cout << p->inf << " " << p->culoare << endl;
		parcurgereInordineRB(t,p->drp);
	}
}
NodRB* treeSearch(NodRB* t, int x)
{
	if (t == NULL || t->inf == x)
		return t;
	if (t->inf>x)
		treeSearch(t->stg, x);
	else
		treeSearch(t->drp, x);
}
int h(ArbRB t,NodRB* root)
{
	if (root != t.nil)
	{
		int hstg = h(t,root->stg);
		int hdrp = h(t,root->drp);
		if (hstg > hdrp)
			return hstg + 1;
		return hdrp + 1;
	}
	return 0;
}