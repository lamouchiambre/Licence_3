#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool recherche(vector<int> tab, int elem){
  for(int i =0; i < tab.size();i++){
    if( tab[i] == elem)
      return true;
  }
  return false;
}


void voisinsRandom(int n, int m, vector<int>voisins[]){
  //assert 
  
  srand(time(NULL));
  int i=0;
  while(i<m){
    int x=rand()%n;
    int y=rand()%n;
    if( x!=y){
      if( !(recherche(voisins[x],y)) and !(recherche(voisins[y],x))){
    voisins[x].push_back(y);
    voisins[y].push_back(x);
    i++;
      }
    }
  }
}
int
main()
{
  int n;                                    // Le nombre de sommets.
  int m;                                    // Le nombre d'aretes.
  cout << "Entrer le nombre de sommets: ";
  cin >> n;
  cout << "Entrer le nombre d'aretes: ";
  cin >> m;
  vector<int> voisins[n];                   // Les listes des voisins. 
  int pere[n];                              // L'arbre en largeur.
  int ordre[n];                             // L'ordre de parcours.
  int niveau[n];                            // Le niveau du point.

  return EXIT_SUCCESS;
}
