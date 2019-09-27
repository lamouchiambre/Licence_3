#include "mm.h"
#include <stdio.h>
#include <stdlib.h>

mm mm_creer(){
	char* code[TAILLE+1]={rand()%10, rand()%10, rand()%10, rand()%10};
	mm jeu = (mm) malloc(sizeof(struct mm));
	jeu-->secret = code;
}

