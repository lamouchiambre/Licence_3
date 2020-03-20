#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

const int N=1400;
const int M=(N*(N-1))/2;
  
typedef struct coord{int abs; int ord;} coord;

//void pointRandom(int n,coord point[]);
//float distance(coord p1,coord p2);
//void voisins(int n,int dmax,coord point[],vector<int> voisin[],int &m);
//bool existe(int n,int dis[],bool traite[],int &x);

//int construireArbre(int n,int arbre[][2],int pere[]);
bool recherche(vector<int> tab, int elem){
  for(int i =0; i < tab.size();i++){
    if( tab[i] == elem)
      return true;
  }
  return false;
}
bool recherche(int tab[], int n, int elem){
  for(int i =0; i < n;i++){
    if( tab[i] == elem)
      return true;
  }
  return false;
}

void printArrete(int M, int arete[][2]){
  for(int i = 0; i < M; i++){
      cout << '[' << arete[i][0] << ", " << arete[i][1] << ']' << endl;
  }
}


bool existe(int n,int dis[],bool traite[],int &x){
  bool rep=false;
  int dmin=-1;
  for(int i=0;i<n;i++){
    if(traite[i]==false){
      rep=true;
      if(dmin == -1 || dis[i]<dmin){
    x=i;
    dmin=dis[i];
      }
    }   
  }
  return rep;
}


int distanceE(coord a, coord b){
  return sqrt(pow(a.abs-b.abs,2)+ pow(a.ord-b.ord, 2));
}



void voisins2arete(int n,vector<int>voisin[],int arete[][2]){
  int k = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < voisin[i].size(); j++){
      if(i <= voisin[i][j]){
        arete[k][0] = i; 
        arete[k][1] = voisin[i][j];
        k++;
      }
    }
  }
}

//ex1 Création du graphe
//
void pointRandom(int n, coord point[]){
  srand(time(NULL));
  for (size_t i = 0; i < n; i++)
  {
    point[i].abs = rand() % 612;
    point[i].ord = rand() % 792;
  }
  
}

//construit un tableau de voisin
void voisins(int n,int dmax,coord point[],vector<int> voisin[],int &m){
  srand(time(NULL));
  int x=0;
  m = 0;
  //cout << "je rentre dans la fonction"<< endl;
  while(x<n){
    //cout << "je rentre dans le while " << endl;
    for( int y = 0; y < n; y++){
      //cout << x << ", " << y <<" d = " << distanceE(point[x], point[y])<<endl;
      if( x != y && distanceE(point[x], point[y]) <= dmax ){
        //cout << "je suis dans le premier if " << endl;
        
        if( !(recherche(voisin[x],y)) && !(recherche(voisin[y],x))){
          voisin[x].push_back(y);
          voisin[y].push_back(x);
          //cout << "je suis la" << endl;
          m++;
        }
      }
    }
  x++;
  }
}
void print_voisins(int n, vector<int> voisin[]) {
  for (int i=0; i < n; i++) {
    cout << "v(" << i << ") = ";
    for (int j=0; j < voisin[i].size(); j++) {
      cout << voisin[i][j] << " ";
    } 
    cout << endl;
  }
}

//ex2 Affichage du graphe
void affichageGraphique(int n,int m,coord point[],int arete[][2], string name){
  ofstream output;                           
  output.open(name +".ps",ios::out);
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;  
  for(int i=0;i<n;i++)
    {
      output << point[i].abs << " " << point[i].ord << " 3 0 360 arc" <<endl;
      output << "0 setgray" <<endl;
      output << "fill" <<endl;
      output << "stroke"<<endl;
      output << endl;
    }
  output << endl;
  for(int i=0;i<m;i++)
   {
     output << point[arete[i][0]].abs << " " << point[arete[i][0]].ord 
	    << " moveto" << endl;
     output << point[arete[i][1]].abs << " " << point[arete[i][1]].ord
	    << " lineto" << endl;
     output << "stroke" << endl;
     output << endl;
   }
  output << "showpage";
  output << endl;
}

//ex3 Arbre de Dijkstra
void dijkstra2(int n, vector<int> voisin[], coord point[], int pere[]) {
  int r = 0;
  int d[n];
  bool traite[n];
  int x;

  for (int i=0; i<n; i++) {
    d[i] = 100000;
    pere[i] = -1;
    traite[i] = 0;
  }
  d[r] = 0;
  pere[r] = r;

  while (existe(n, d, traite, x)) {
    traite[x] = true;
    for (int i=0; i<voisin[x].size(); i++) {
      int y = voisin[x][i];
      if (traite[y] == 0 && d[y] > d[x] + distanceE(point[x], point[y])) {
        d[y] = d[x] + distanceE(point[x], point[y]); // x est racourci pour atteindre y
        pere[y] = x;
      }
    }
  }
  for (int i = 0; i < n ; i++){
    cout << "pere[" << i <<"] = " << pere[i]<< endl;
  }
}
void dijkstra3(int n,vector<int> voisin[],coord point[],int pere[]){
  int d[n];
  bool traite[n];
  for(int k=0;k<n;k++){
    d[k]=50000; // ou -1;
    traite[k]=false;
    pere[k]=-1;
  }
  pere[0]=0;
  d[0]=0;
  int x;
  while( existe(n,d,traite,x)){
    traite[x]=true;

    for( int y =0; y<voisin[x].size(); y++){
      //cout<<"voisin de x :"<<x<<" nombre: "<<voisin[x].size()<<" valeur voisin: "<<voisin[x][y]<<endl;
      if(traite[voisin[x][y]] == false && d[voisin[x][y]] >
					    d[x]+distanceE(point[x], point[voisin[x][y]])){
	cout<<"test if y : "<<y<<endl;

	d[voisin[x][y]]= d[x]+distanceE(point[x], point[voisin[x][y]]);
	pere[voisin[x][y]]=x;
      }
    } 
  } 
}

//ex4 Affichage de l'arbre
int construireArbre(int n,int arbre[][2],int pere[]){
  int k = 0;
  for(int i = 0; i < n; i++){
    arbre[i][0] = i;
    arbre[i][1] = i;
  }
  for( int i = 0; i < n; i++){
    if(pere[i] != -1)
      arbre[i][1] = pere[i];
      arbre[i][0] = i;
      k++;
    }
  return k;

}



// void voisins2arete(int n,vector<int>voisins[],int arete[][2]){
//   int m=0;
//   for( int i =0; i<n;i++){
//     for (int j=0; j<voisins[i].size();j++){
//       arete[m][0]=i;
//       arete[m][1]=voisins[i][j];
//       m++;
//     }
//   }
// }


// void dijkstra(int n,vector<int> voisin[],coord point[],int pere[]){
//   int dis[n];
//   bool traite[n];
//   int x = 0;
//   for(int k = 0; k < n; k++){
//     dis[k] = -1;
//     traite[k] = false;
//   }
//   pere[0] =  0;
//   dis[0] = 0;
//   while( existe( n, dis, traite, x)){
//     traite[x] = true;
//     for(int y: voisin[x]){
//       if(!(traite[y]) && dis[y] > dis[x] + distanceE(point[y], point[x]) ){
//         dis[y] = dis[x] + distanceE(point[y], point[x]);
//         pere[y] = x;
//       }
//     }
//   }
//   for (int i = 0; i < n ; i++){
//     cout << "pere[" << i <<"] = " << pere[i]<< endl;
//   }
// }



int
main()
{
  int n;                           // Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n; 
  int dmax=50;                     // La distance jusqu'a laquelle on relie deux points.
  coord point[N];                  // Les coordonnees des points.
  vector<int> voisin[N];           // Les listes de voisins.          
  int arbre[N-1][2];               // Les aretes de l'arbre de Dijkstra.
  int pere[N];                     // La relation de filiation de l'arbre de Dijkstra.
  int m;                           // Le nombre d'aretes
  
                   // Les aretes du graphe

  pointRandom(n, point);
  voisins(n, dmax, point,voisin,m);
  //print_voisins(n, voisin);
  int arete[m][2];
  voisins2arete(n, voisin, arete);
  printArrete(m, arete);
  affichageGraphique(n, m, point, arete, "graphe");
  dijkstra2(n, voisin, point, pere);
  int k = construireArbre(n, arbre, pere);
  affichageGraphique(n, k, point, arbre, "arbre");

  return EXIT_SUCCESS;
}
