#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
void echange(T& e1, T& e2)
{
	T aux=e1; e1=e2; e2=aux;}

template<typename K>
void triBulles(K T[], int tailleT)
{
	int i=tailleT-2,j; bool ech=true;
	while (i>=0 && ech)
	{
		ech=false;
		for (j=0; j<=i; j++)
		if (T[j]>T[j+1])
		{
			echange(T[j],T[j+1]); ech=true;}
		i--;
	}
}

int main () 
{
	string s ="erer";
	string t="uiou";
	cout << "s=" <<s<<" t=" << t <<endl; 
	echange(s, t);
	cout << "s=" <<s<<" t=" << t <<endl;
	string tab[] = {"za","m", "iii" };
	triBulles(tab, 3);

	return 0;
} 
/*
B classe derivée de A
A a = new B(); marche
Vector<A> va = new Vector<B>(); marche pas
A[] a2 = new B() marche

*/