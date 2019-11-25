#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack> 

using namespace std;


//ex1 création d'un graphe aléatoire
// pas de symetrie, pas de boucle, pas d'arête multiple

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
//affichage du tableau de voisin
void print_voisins(int n, vector<int> voisins[]) {
  cout << "tableau de voisin" << endl;
  for (int i=0; i < n; i++) {
    cout << "v(" << i << ") = ";
    for (int j=0; j < voisins[i].size(); j++) {
      cout << voisins[i][j] << " ";
    } 
    cout << endl;
  }
}

//ex2 Parcours en largeur
void parcoursLargeur(int n, vector<int> voisins[], int niveau[], int ordre[], int pere[]){
  queue<int> AT; int v; int t;
  int dv[n]; int r = 0; 
  for (int i = 0 ; i< n; i++)
  {
    dv[i] = 0;
  }
  t = 2; dv[r] = 1; ordre[r]=1; pere[r]= r; niveau[r]=0;
  AT.push(r);
  while (AT.size() != 0)
  {
    v = AT.front(); AT.pop();
    for ( int x : voisins[v])
    {
      if (dv[x] ==0)
      {
        dv[x]=1;
        AT.push(x);
        ordre[x] = t; t +=1;
        pere[x] = v;
        niveau[x] = niveau[v] + 1; 
      } 
    }
  }  
}

//ex3 Ecriture niveau
void ecrtureNiveau(int n, int niveau[]){
  int nb[n]; int nbComp0 = 0;
  //initialisation de nb[n]
  for (size_t i = 0; i < n; i++)
  {
    nb[i]=0;
  }
  //calcule de nb
  for (size_t i = 0; i < n; i++)
  {
    if(niveau[i] != 1){ nbComp0++;}
    for(size_t j = 0; j < n; j++){
      if (i == niveau[j])
      {
        nb[i]=nb[i]+1;
      }
    }
    if(nb[i] != 0){
      cout <<"Il y a "<< nb[i] <<" sommets au niveau " << i <<endl;
    }
  }
  cout<< "Il y a " << nbComp0 - 1 <<" sommets qui ne sont pas dans la composante de 0"<<endl;  
}
//ex4 Parcours en profondeur
void parcoursProfondeur(int n,vector<int> voisins[], int niveau[],int debut[], int fin[], int pere[]){
  stack<int> pile;
  
  int dejaVu[n]={0};
  //ordre={-1};
  //int fin[n]={-1};
  
  dejaVu[0]=1;
  niveau[0]=0;
  pile.push(0);

  debut[0]=1;

  int t=2;

  while(!(pile.empty())){
    int sommetCourant = pile.top();
    if (0==voisins[sommetCourant].size()){
      fin[sommetCourant]=t;
      t++;
      pile.pop(); 
    }
    else{
      int y=voisins[sommetCourant][0];
      voisins[sommetCourant].erase( voisins[sommetCourant].begin());
      if(dejaVu[y]==0){
        dejaVu[y]=1;
        pile.push(y);
        debut[y]=t;
        t++;
        pere[y]=sommetCourant;
        niveau[y]=niveau[pere[y]]+1;
      }
    }
  }
}
void print(int tab[], int n){
  for (size_t i = 0; i < n; i++)
  {
    cout << tab[i] << ", ";
  }
  cout <<endl;
}

int main()
{
  int n;                                    // Le nombre de sommets.
  int m;                                    // Le nombre d'aretes.
  cout << "Entrer le nombre de sommets: ";
  cin >> n;
  cout << "Entrer le nombre d'aretes: ";
  cin >> m;
  vector<int> voisins[n];                   // Les listes des voisins. 
  voisinsRandom(n, m, voisins);
  print_voisins(n, voisins);
  
  //parcours niveau
  int pereP[n];
  int pereL[n];                              // L'arbre en largeur.
  int ordre[n];                             // L'ordre de parcours.
  int niveau[n];
  int debut[n];                            // Le niveau du point.
  int fin[n];

  //initialisation
  for(int i = 0; i < n; i++){
    pereP[i] = -1;
    pereL[i] = -1;
    ordre[i] = -1;
    debut[i] = -1;
    fin[i] = -1;
    niveau[i] = -1;
  }
  cout << "Parcours en Largeur" <<endl;
  parcoursLargeur(n, voisins, niveau, ordre, pereL);  
  //affichage
  cout <<"pereL ";
  print(pereL, n);
  cout <<"ordre ";
  print(ordre, n);
  cout <<"niveau ";
  print(niveau, n);
  cout << "-------------------------"<<endl;
  ecrtureNiveau(n, niveau);
  cout << "-------------------------"<<endl;
  
  parcoursProfondeur(n, voisins, niveau, debut, fin, pereP);
  cout << "Parcours en Profondeur" << endl;
  //affichage
  cout <<"pereP ";
  print(pereP, n);
  cout <<"niveau ";
  print(niveau, n);
  cout <<"debut ";
  print(debut, n);
  cout <<"fin ";
  print(fin, n);
  return EXIT_SUCCESS;
}
