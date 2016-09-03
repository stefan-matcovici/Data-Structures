#include <iostream>
using namespace std;
typedef int elt;
struct Nod
{
    elt inf;
    Nod *succ;
};
struct Stiva
{
    Nod *prim;
};
void stivaVida(Stiva& S)
{
    S.prim=NULL;
}
bool esteVida(Stiva S)
{
    return S.prim==NULL;
}
void push(Stiva &S,elt e)
{
    Nod *q;
    q=new Nod;
    q->inf=e;
    q->succ=S.prim;
    S.prim=q;
}
elt top(Stiva S)
{
    return S.prim->inf;
}
void pop(Stiva &S)
{
    if (S.prim!=NULL)
    {
        S.prim=S.prim->succ;
    }
}

