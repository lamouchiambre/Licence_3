#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


void grapheRandom(int n, int m, int edge[][2]){
  srand(time(NULL));
  for(int i = 0; i<m ; i++){
    edge[i][0]=rand()%n;
    edge[i][1]=rand()%n;
  }
}

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

void ecritureTailles(int n, int m, int comp[]){
  int nombreCompo[n];
  int nbCop[m];
  int tmp;
  for(int i = 0; i<n; i++){
    nombreCompo[i]=0;
  }
  for(int i = 0; i<m; i++){
    nbCop[i]=0;
  }
  for(int i = 0; i<n; i++){
    tmp=comp[i];
    nombreCompo[tmp]++;
    cout <<"tmp="<<tmp<<" nombreCompo[tmp]:"<<nombreCompo[tmp]<<endl;
  }
  for(int i = 0; i<n; i++){
    cout<<'['<<i<<','<<nombreCompo[i]<<']';
  }
  cout<<endl;
  for(int i = 0; i<m; i++){
    nbCop[nombreCompo[i]]++;  
  }
  for(int i = 0; i<m;i++){
    //if(nombreCompo[i] != 0){
    cout<< i+1<<" : "<<nbCop[i]<<endl;
    // }
  }
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
  ecritureTailles( n, m, comp);
  
  cout <<endl;
  
  return EXIT_SUCCESS;
}
