
#include <iostream>
using namespace std;
struct NodArbBin
{
    int inf;
    NodArbBin *stg, *drp;
};

struct ArbBin
{
    NodArbBin* rad;
} ;
ArbBin arborevid()
{
	ArbBin B;
	B.rad = NULL;
	return B;
}
void insereaza(NodArbBin *p, char c, int e)
{
    if (p==NULL)
    {
        p->inf=e;
        p->stg=NULL;
        p->drp=NULL;
    }
    else
    {
        NodArbBin *q;
        q=new NodArbBin;
        q->drp=NULL;
        q->stg=NULL;
        q->inf=e;
        if (p->drp==NULL || p->stg==NULL)
        {
            if (c=='S' && p->stg==NULL)
                p->stg=q;
            else if (c=='D' && p->drp==NULL)
                p->drp=q;
        }

    }
}
void parcurgerePreordine(NodArbBin *t)
{
    if (t!=NULL)
    {
        cout<<t->inf;
        parcurgerePreordine(t->stg);
        parcurgerePreordine(t->drp);
    }
}
void parcurgereInordine(NodArbBin *t)
{
    if (t!=NULL)
    {
        parcurgereInordine(t->stg);
        cout<<t->inf;
        parcurgereInordine(t->drp);
    }
}
void parcurgerePostordine(NodArbBin *t)
{
    if (t!=NULL)
    {
        parcurgerePostordine(t->stg);
        parcurgerePostordine(t->drp);
        cout<<t->inf;
    }
}
/*void parcurgereBFS(NodArbBin *t)
{
    if (t!=NULL)
    {
        Coada C;
        coadaVida(C);
        insereaza(C,t);
        while (!esteVida(C))
        {
            t=citeste(C);
            cout<<t->inf;
            if (t->stg!=NULL)
                insereaza(C,t->stg);
            if (t->stg!=NULL)
                insereaza(C,t->drp);
            elimina(C);
        }
    }
}
*/

