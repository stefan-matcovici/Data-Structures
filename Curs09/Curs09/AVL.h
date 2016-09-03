
ArbAVL ArbAVLVid();
NodAVL* newNodAVL(int e);
bool EsteVid(ArbAVL A);
NodAVL* rotatieSimplaStanga(NodAVL* x);
NodAVL* rotatieSimplaDreapta(NodAVL* x);
NodAVL* insereaza(NodAVL* p, int x);
int h(NodAVL* root);
void afisare(NodAVL* p);
void calculareFactor(NodAVL*p);
void parcurgereInordineAVL(NodAVL *p, void f(NodAVL*));
NodAVL* echilibrare(NodAVL* p);
