#include <iostream>
#include <iomanip>
#include "CompteBancaire.h"
#include "CompteRemunere.h"
#include "CompteDepot.h"

using namespace std;

int main () 
{
	CompteBancaire* cb = new CompteBancaire();
	cb->depot(20);
	//delete cb;
	CompteDepot* cd = new CompteDepot();
	int N = 2;
	CompteBancaire** CompteVP = new CompteBancaire*[N];
	CompteVP[0] = cb;
	CompteVP[1] = cd;

	for (int i = 0 ; i < N; i++){
		CompteVP[i]->depot(10);
		CompteVP[i]->getSolde();
	}
	CompteBancaire c1;
	CompteDepot cd1

	return 0;
} 
