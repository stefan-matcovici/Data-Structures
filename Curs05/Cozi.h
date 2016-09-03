typedef int elt;
struct NodA
{
	elt inf;
	NodA *drp, *stg;
	bool tdrp;
};
struct Nodc
{
    NodA* inf;
    Nodc *succ;
};
struct Coada
{
    Nodc *prim, *ultim;
};

Coada coadaVida()
{
	Coada C;
    C.prim=NULL;
    C.ultim=NULL;
	return C;
}

bool esteVida(Coada C)
{
    return C.prim==NULL && C.ultim==NULL;
}

NodA* citesteC(Coada C)
{
    return C.prim->inf;
}

void insereazaC(Coada &C,NodA* e)
{
    Nodc *p;
    p=new Nodc;
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

void eliminaC(Coada &C)
{
    if (C.prim!=NULL)
        C.prim=C.prim->succ;
    if (C.prim==NULL)
        C.ultim=NULL;
}

