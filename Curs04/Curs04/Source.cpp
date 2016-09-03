#include "Stive.h"
using namespace std;
int main()
{
	int i, n,x;
	Stiva S;
	stivaVida(S);
	cin >> n;
	i = 0;
	while (i < n)
	{
		cin >> x;
		push(S, x);
		i++;
	}

	while (!esteVida(S))
	{
		cout << top(S);
		pop(S);
	}
}