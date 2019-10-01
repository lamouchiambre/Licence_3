#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
//#include "affichage.cc"

using namespace std;
typedef struct coord{int abs; int ord;} coord;


void pointRandom(int n, coord point[]){
  for (size_t i = 0; i < n; i++)
  {
    point[i].abs = rand() % 612;
    point[i].ord = rand() % 792;
  }
  
}

void distance(int n, int m, coord point[], int edge[][3]){
  int k = 0;
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = i + 1; j < n; j++)
    {
      edge[k][0] = i;
      edge[k][1] = j;
      edge[k][2] = (point[i].abs - point[j].abs)*(point[i].abs - point[j].abs) + (point[j].ord - point[i].ord)*(point[j].ord - point[i].ord); 
      k++;
    }
    
  }
  
}
void affectation(int tmp[3], int tab[3]){
  tmp[0]=tab[0];
  tmp[1]=tab[1];
  tmp[2]=tab[2];
}
void echanger(int tab[][3], int i, int j)
     {
     int memoire[3] = {0,0,0};
     swap(memoire,tab[i]);
     swap(tab[i], tab[j]);
     swap(tab[j],memoire);
     }
int partition(int tableau[][3], int deb, int fin)
    {
    int compt=deb;
    int pivot=tableau[deb][2];
    int i;

    for(i=deb+1;i<=fin;i++)
        {
        if(tableau[i][2]<pivot)
            {
            compt++;
            echanger(tableau,compt,i);
            }
        }
    echanger(tableau,compt,deb);
    return(compt);
    }

void tri_rapide_bis(int tableau[][3],int debut,int fin)
    {
    if(debut<fin)
        {
        int pivot=partition(tableau,debut,fin);
        tri_rapide_bis(tableau,debut,pivot-1);
        tri_rapide_bis(tableau,pivot+1,fin);
        }
    }

void tri_rapide(int tableau[][3],int longueur)
     {
     tri_rapide_bis(tableau,0,longueur-1);
     }
void printEdge(int m, int edge[][3]) {
  for (int i=0; i<m; i++) {
    cout << edge[i][0] << " " << edge[i][1] << " " << edge[i][2] << endl;
  }
}
void printAbre(int m, int edge[][2]) {
  for (int i=0; i<m; i++) {
    cout << edge[i][0] << " " << edge[i][1] << endl;
  }
}
void kruskal(int n, int m, int edge[][3], int arbre[][2]){
  tri_rapide(edge, m);
  int x, y,aux;
  int h = 0;
  int comp[n-1];
  for(int i = 0; i<n-1; i++){
    comp[i]=i;
  }
  for(int i = 0; i<m; i++){
    x = edge[i][0];
    y = edge[i][1];
    if(comp[x]!=comp[y]){
      aux = comp[x];
      arbre[h][0] = x;
      arbre[h][1] = y;
      h++;
      for(int k = 0; k<n; k++){
	      if(comp[k]==aux){
	      comp[k] = comp[y];
	    }
      }
    }
  }

}
void affichageGraphique(int n, coord point[], int arbre[][2]){
  ofstream output;                           
  output.open("Exemple.ps",ios::out);
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
  for(int i=0;i<n-1;i++)
   {
     output << point[arbre[i][0]].abs << " " << point[arbre[i][0]].ord 
	    << " moveto" << endl;
     output << point[arbre[i][1]].abs << " " << point[arbre[i][1]].ord
	    << " lineto" << endl;
     output << "stroke" << endl;
     output << endl;
   }
  output << "showpage";
  output << endl;
}
int 
main()
{
  int n;             //Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n;
  int m=n*(n-1)/2;   // Le nombre de paires de points.
  coord point[n];    // Les coordonnees des points dans le plan.
  int edge[m][3];    // Les paires de points et le carre de leur longueur.
  int arbre[n-1][2]; // Les aretes de l'arbre de Kruskal. 
  pointRandom(n, point);
  distance(n, m, point, edge);
  for (size_t i = 0; i < n; i++)
  {
    cout <<'['<< point[i].abs << " ," << point[i].ord << ']' << endl; 
  }

  int tab[7] ={5,6,4,2,1,3,7};
  int tab2[7]  = {1,2,3,4,5,5,6};
  //swap(tab, tab2);
  //cout << tab[0] << " " << tab2[0];
  tri_rapide(edge, m);
  printEdge(m ,edge);

  kruskal(n, m, edge, arbre);
  cout << "arbre:" << endl;
  printAbre(n-1, arbre);
  //affichageGraphique(n, point, arbre);
  affichageGraphique(n, point, arbre);
  return EXIT_SUCCESS;
}
