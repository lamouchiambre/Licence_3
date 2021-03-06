#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//ex1 création d'un graphe aléatoir G à n sommet et m arêtes
void grapheRandom(int n, int m, int edge[][2]){
  srand(time(NULL));
  for(int i = 0; i<m ; i++){
    edge[i][0]=rand()%n;
    edge[i][1]=rand()%n;
  }
}

//ex2 calcul des composantes connexes
void composantes(int n, int m, int edge[][2], int comp[]){
  int x, y,aux;
  
  for(int i = 0; i<n; i++){
    comp[i]=i;
  }
  for(int i = 0; i<m; i++){
    x = edge[i][0];
    y = edge[i][1];
    if(comp[x]!=comp[y]){
      aux = comp[x];
      for(int k = 0; k<n; k++){
      	if(comp[k]==aux){
	      comp[k] = comp[y];
	      }
      }
    }
  }
}

//ex3 retourner la tailles des composantes connexes
// -Elle affiche le nombre de point isolés (les composantes de tailles 1)
// -Les nombre de composantes des autres tailles, dans l'ordre croissant
void ecritureTailles(int n, int m, int comp[]){
  int nbeComp[n]={0};
  for(int i=0; i<n;i++){
    nbeComp[comp[i]]++;
  }
  //nbeComp represente le nombre de point (nbeComp[i]) qui est dans la composant (i)
  int nbOcc[n]={0};
  for(int j=0;j<n;j++){
      if (nbeComp[j]>0){
	nbOcc[nbeComp[j]]++;
      }
  }
  cout <<endl;
  for(int k=0;k<n;k++){
    if (nbOcc[k]>0){
      cout<<"il y a "<< nbOcc[k] <<" composantes de taille "<< k<<endl;
    }
  }
  // nbOcc represente le nombre de composantes (nbOcc[i]) pour chaque taille (i)
}

// void afficheNbComp(int n, int tab[]) {
//   cout << endl;
//   for (int i = 1; i < n; i++) {
//     if (i == 0 && tab[i] != 0) {
//       cout << "Il y a " << tab[0] << " point(s) isole(s)." << endl;
//     }
//     if (tab[i] != 0) {
//       cout << "Il y a " << tab[i] << " composante(s) de taille " << i << "." << endl;     
//     }
//   }
//   cout << endl;
// }

//exo 4 Optimisation de l'algorithme
void composantesOpti(int n, int m, int edge[][2], int comp[]) {
    int t[n] = {0}; // taille de comp[x]
    stack<int> L[n]; // liste des sommets de comp[x], gérée par une pile
    
    for (int i = 0; i < n; i++) {
        comp[i] = i;
        L[comp[i]].push(i);
        t[comp[i]] = 1;
    }
    for (int i = 0; i < m; i++) {
        int x = edge[i][0];
        int y = edge[i][1];
        if (comp[x] != comp[y]) {
            if (t[comp[x]] > t[comp[y]]) {
                swap(x, y);
            }
            int aux = comp[x];
            t[comp[y]] += t[aux];
            while (!L[aux].empty()) {
                comp[L[aux].top()] = comp[y];
                L[comp[y]].push(L[aux].top());
                L[aux].pop();
                t[aux]--;
            }
        }
    }
//     cout << endl << "T = ";
//     for (int i = 0; i < n ; i++){
//         cout << "[" << i << "|" << t[i] <<"]";
//     }
//     cout << endl;
}
int main()
{ 
  int n;     // Nombre de sommets.	
  int m;     // Nombre d'aretes.	
  cout << "Entrer le nombre de sommets:";
  cin >> n;
  cout << "Entrer le nombre d'aretes:";
  cin >> m;
  int edge[m][2];    // Tableau des aretes.
  int comp[n];       // comp[i] est le numero de la composante contenant i.
  
  grapheRandom(n,m,edge);
  cout << "Egde =" <<endl;
  for(int i = 0; i<m; i++){
    cout <<'['<<edge[i][0]<<"|"<<edge[i][1]<<"]";
  }
  
  cout <<endl;
  composantes(n,m, edge, comp);
  cout << "Comp =" <<endl;
  for(int i = 0; i<n; i++){
    cout <<'['<<i<<"|"<<comp[i]<<"]";
  }
  cout <<endl;
  composantesOpti(n,m, edge, comp);
  cout << "Comp =" <<endl;
  for(int i = 0; i<n; i++){
    cout <<'['<<i<<"|"<<comp[i]<<"]";
  }
  cout <<endl;
  //ecritureTailles( n, m, comp);
  
  
  ecritureTailles(n, m, comp);
  //afficheNbComp(n, nbComp);
  
  cout <<endl;
  
  return EXIT_SUCCESS;
}
