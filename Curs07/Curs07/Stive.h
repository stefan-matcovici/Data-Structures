
typedef int elt;
struct NodStiva
{
    elt inf;
    NodStiva *succ;
};
struct Stiva
{
    NodStiva *prim;
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
    NodStiva *q;
    q=new NodStiva;
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
