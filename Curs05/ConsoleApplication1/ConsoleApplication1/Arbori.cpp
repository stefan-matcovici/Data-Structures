#include "ArboriL.h"
int main()
{
	ArbBin A;
	A = ArbBinVid();
	insereazaArbore(A, A.rad, 'S', 4);
	insereazaArbore(A, A.rad, 'S', 8);
	insereazaArbore(A, A.rad, 'D', 10);
	insereazaArbore(A, A.rad->stg, 'S', 4);
	insereazaArbore(A, A.rad->stg, 'D', 5);
	insereazaArbore(A, A.rad->drp, 'S', 20);

	ArbBin B;
	B = ArbBinVid();
	insereazaArbore(B, B.rad, 'S', 1);
	insereazaArbore(B, B.rad, 'S', 2);
	insereazaArbore(B, B.rad, 'D', 3);
	insereazaArbore(B, B.rad->stg, 'S', 5);
	insereazaArbore(B, B.rad->stg, 'D', 5);
	insereazaArbore(B, B.rad->drp, 'S', 6);
	insereazaArbore(B, B.rad->drp, 'D', 7);
	insereazaArbore(B, B.rad->stg->stg, 'S', 8);
	insereazaArbore(B, B.rad->stg->stg, 'D', 9);
	insereazaArbore(B, B.rad->stg->drp, 'S', 10);
	insereazaArbore(B, B.rad->stg->drp, 'D', 11);

	/*
	parcurgerePreordine(A.rad);
	cout << endl;
	parcurgereInordine(A.rad);
	cout << endl; 
	parcurgerePostordine(A.rad);
	cout << endl;
	parcurgereBFS(A.rad);
	cout << endl;

	string s = "1";
	adresePreordine(A.rad, s);
	cout << endl;

	cout << frontiera(A.rad);
	

	int count = 0;
	singlevalued(A.rad, count);
	cout << count << endl;
	

	A.rad=citire();
	parcurgereInordine(A.rad);
	cout << endl;


	parcurgereInordine(A.rad);
	cout << endl;
	alkleaInordine(A.rad, 4);
	

	parcurgereInordine(A.rad);
	cout << endl;
	oglinda(A.rad);
	parcurgereInordine(A.rad);
	cout << endl;
	

	cout << inaltime(A.rad);
	

	cout<<comp(A.rad, B.rad);
	
	
	int mini=A.rad->inf;
	minelem(A.rad, mini);
	cout << mini;
	*/

	parcurgereInordine(A.rad);
	cout << endl;
	doubletree(A.rad);
	parcurgereInordine(A.rad);
	cout << endl;

	return 0;
}