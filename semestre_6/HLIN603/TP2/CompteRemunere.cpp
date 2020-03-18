#include <iostream>
#include <iomanip>
#include "CompteBancaire.h"
#include "CompteRemunere.h"

using namespace std;

CompteRemunere::CompteRemunere():bonus(10){}
CompteRemunere::~CompteRemunere(){
	solde += solde*bonus*0.01;
}
void CompteRemunere::depot(float d){
	solde += d*1.1;
};