#include <iostream>
#include "CompteBancaire.h"
#include "CompteDepot.h"
using namespace std;

CompteDepot::CompteDepot(){cout << "la d" <<endl;}

CompteDepot::~CompteDepot(){
	solde -= 100;
}

void CompteDepot::depot(float d){
	solde += d - 1;
	if (d> 1000)
	 {
	 	solde += 10;
	 } 
}