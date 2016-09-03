typedef int elt;
struct NodA
{
	elt inf;
	NodA *drp, *stg;
	bool tdrp;
};
struct NodS
{
    NodA* inf;
    NodS *succ;
};
struct Stiva
{
    NodS *prim;
};
void stivaVida(Stiva& S)
{
    S.prim=NULL;
}
bool esteVida(Stiva S)
{
    return S.prim==NULL;
}
void push(Stiva &S,NodA* e)
{
    NodS *q;
    q=new NodS;
    q->inf=e;
    q->succ=S.prim;
    S.prim=q;
}
NodA* top(Stiva S)
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

