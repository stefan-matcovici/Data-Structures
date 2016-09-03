#include "RBTree.h"
int main()
{
	ArbRB t;
	t = ArbRBVid();
	insereazaRB(t, 25);
	insereazaRB(t,20);
	insereazaRB(t, 10);
	insereazaRB(t,3);
	insereazaRB(t, 15);
	insereazaRB(t,22);
	insereazaRB(t, 35);
	insereazaRB(t, 30);
	insereazaRB(t, 50);
	insereazaRB(t, 32);

	parcurgereInordineRB(t,t.rad);
	cout << endl << h(t, t.rad)<<endl;

	NodRB* p = treeSearch(t.rad,10);
	stergeRB(t,p);
	parcurgereInordineRB(t, t.rad);
	//cout << endl;
	//caz1(t.rad->stg->drp);
	//parcurgereInordineRB(t.rad);
}