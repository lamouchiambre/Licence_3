#include <stdio.h>
#include <stdlib.h>

int appartien(char* tab, int taille, char k){
    int i = 0;
    while (i < taille)
    {
        if (tab[i] == k)
        {
            return 1;
        }     
        i++;   
    }
    return 0;
    
}


int main(int argc, char const *argv[])
{
    if( argc != 2){
        perror("nombre de parametre inccorect");
        return -1;
    }
    FILE *f = fopen(argv[1], "r");
    int c;
    if (f == NULL)
    {
        perror("le fichier est inexitant ou vide");
        return -1;
    }
    fseek(f, 0, SEEK_END);
    int taille = ftell(f);
    printf("%li\n", ftell(f));
    char caracteres[taille];
    fseek(f, 0, SEEK_SET);
    int i =0;
    while ((c = fgetc(f)) != EOF)
    {
        printf("%c ",c);
        printf("%i\n", appartien(caracteres, taille, c));
        if(appartien(caracteres, taille, c)==0){
            caracteres[i] = c;
            i++;
        }
    }
    for (int j = 0; j < taille; j++)
    {
        printf("%i = %c\n",j,caracteres[j]);
        
    }
    printf("%i caractères differents : ", i);
    for (int j = 0; j < i; j++)
    {
        printf("%c ,",caracteres[j]);
        
    }

    


    return 0;
}
