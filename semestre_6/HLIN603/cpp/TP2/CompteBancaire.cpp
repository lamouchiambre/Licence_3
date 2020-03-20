#include <iostream>
#include "CompteBancaire.h"
using namespace std;

void CompteBancaire::getSolde(){
	cout << "Le solde actuel est de " << solde << endl;
}

CompteBancaire::CompteBancaire(): solde(0){cout <<"la"<<endl;}

CompteBancaire::~CompteBancaire(){
	cout<<"On vous doit "<< solde <<endl;
}

void CompteBancaire::depot(float d){
	solde+=d;
}

