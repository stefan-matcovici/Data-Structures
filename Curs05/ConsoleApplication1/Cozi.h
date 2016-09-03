struct NodCoada
{
	elt inf;
	NodCoada *succ;
};

struct Coada
{
    NodCoada *prim, *ultim;
};

void coadaVida(Coada &C)
{
    C.prim=NULL;
    C.ultim=NULL;
}

bool esteVida(Coada C)
{
    return C.prim==NULL && C.ultim==NULL;
}

elt citeste(Coada C)
{
    return C.prim->inf;
}

void insereaza(Coada &C,elt e)
{
    NodCoada *p;
    p=new NodCoada;
    p->inf=e;
    p->succ=NULL;
    if (C.ultim!=NULL)
        C.ultim->succ=p;
    else
    {
        C.prim=p;
    }
    C.ultim=p;
}

void elimina(Coada &C)
{
    if (C.prim!=NULL)
        C.prim=C.prim->succ;
    if (C.prim==NULL)
        C.ultim=NULL;
}

