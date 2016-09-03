#include "DigrafListe.h"
int main()
{
	/*DigrafM D,B;
	D=citesteDigrafM();
	afisareM(D);
	B = DigrafMVid();
	detInchReflTranz(D, B);
	afisareM(B);
	*/
	
	DigrafL D;
	D = citesteDigrafL();
	afisareL(D);
	BFS(D, 0);
	

	


}