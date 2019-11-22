#include <iostream>
#include <vector>
//#include "villes.cc"

using namespace std;

const int N=5;
const int M=6;
const int INF=9999;                      //La valeur infinie.    

void floydWarshall(int longueur[][N],int dist[][N],int chemin[][N]){
    for(int i = 0; i < N; i++){
    
      for(int j = 0; j < N; j++){
        if (longueur[i][j] != INF){
          dist[i][j] = longueur[i][j];
           cout<<"dist["<<i<<"]["<<j<<"] ="<< longueur[i][j]<<endl;
          chemin[i][j] = j;
        }
        else{
          dist[i][j] = INF;
          chemin[i][j] = 0;
        }
      }
      dist[i][i] = 0;
      chemin[i][i] = i;
    }
      for(int k = 0; k < N; k++){
        for(int i = 0; i < N ; i++){
          for(int j = 0; j < N; j++){
            if(dist[i][j]> dist[i][k]+ dist[k][j]){
              dist[i][j] = dist[i][k]+ dist[k][j];
              chemin[i][j] = chemin[i][k];
            }
          }
        }
      }
      for(int i = 0; i < N; i++ ){
        if(dist[i][i] < 0){
          //cout<<"Il exsite un clycle oritente de poin <0"<<endl;
        }
      }
    
  }
void afficheDist(int dist[][N]){
  for(int i = 0; i < N ; i++){
    cout<<"---------------------"<<endl;
    for(int j = 0; j < N; j++){
      cout << "| ";
      if(dist[i][j]>=0){
      cout <<" ";  
      }
      cout << dist[i][j];
    }
    cout << "|" << endl;
  }
  cout<<"---------------------"<<endl;
}
void afficheDist(int dist[][M]){
  for(int i = 0; i < N ; i++){
    cout<<"---------------------"<<endl;
    for(int j = 0; j < N; j++){
      cout << "| ";
      if(dist[i][j]>=0){
      cout <<" ";  
      }
      cout << dist[i][j];
    }
    cout << "|" << endl;
  }
  cout<<"---------------------"<<endl;
}

void affichage(int dist[][N],int chemin[][N]);
void itineraire(int i,int j,int chemin[][N]){
  cout << "Entrer le depart "<< i << endl;
  cout << "Entrer la destination " << j << endl;
  cout << "L'itineraire est ";
  cout << i;
  int a = i; 
  int b = chemin[i][j];
  while ( b != a){
    cout <<" "<< b;
    a = b;
    b = chemin[a][j]; 
  }

}

void fermetureTransitive(int arc[][M], int fermeture[][M]){
  for(int i = 0; i < M; i++){
      for(int j = 0; j < M; j++){
        fermeture[i][j] = arc[i][j];
      }
  }
  for(int k = 0; k < M; k++){
    for(int i = 0; i < M; i++){
      for(int j = 0; j < M; j++){
        if(fermeture[i][k]+fermeture[k][j] >= 2){
          fermeture[i][j] = 1;
        }
      }
    }
  }
}

void fermetureTransitive2(int arc[][M], int fermeture[][M]){
  
  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      if(arc[i][j]==1)
    fermeture[i][j]=1;
      else
    fermeture[i][j]=0;
    }
    //fermeture[i][i]=i;
  }
      
  for(int k=0;k<M;k++)
    for(int i=0;i<M;i++)
      for(int j=0;j<M;j++)
    if(fermeture[i][k]+fermeture[k][j]==2){
      fermeture[i][j]=1;
    }
  }


void compFortConnexe(int n, int fermeture[][M]){
  int comp[M]; int aux;
  for(int i = 0; i < M; i++){
    comp[i] = i;
  }
  for(int i = 0; i < M; i++){
    for(int j = i; j < M; j++){
      if(fermeture[i][j] + fermeture[j][i] == 2 ){
        aux = i;
        for(int k = 0; k < M; k++){
          if(comp[k] == aux){
            comp[k] = comp[j];
          }
        }
      }
    }
  }
  for(int i = 0; i < M; i++){
    cout << "comp[" << i << "] = " << comp[i] <<endl;
  }
}

int
main()
{
  int longueurs[N][N]={
          {0,2,INF,4,INF},   //Les longueurs des arcs.
		      {INF,0,2,INF,INF}, //longueur[i][j]=INF si l'arc ij n'existe pas
		      {INF,INF,0,2,INF},
		      {INF,-3,INF,0,2},
		      {2,INF,INF,INF,0}};
  int arc[6][6] = {
                  {0,0,0,1,0,1},
                  {1,0,1,1,0,0},
                  {0,0,0,1,0,0},
                  {0,0,0,0,1,1},
                  {0,0,1,0,0,1},
                  {0,0,1,0,0,0}
                  };                
  int dist[N][N];                        //Le tableau des distances.
  int chemin[N][N];                      //Le tableau de la premiere etape du chemin de i a j.
  floydWarshall(longueurs,dist,chemin);
  cout<< "tableau dist" <<endl;
  afficheDist(dist);
  cout<<"tableau chemin"<< endl;
  afficheDist(chemin);
  //affichage(dist,chemin);  
  itineraire(4, 2, chemin);
  int fermeture[M][M];
  fermetureTransitive(arc, fermeture);
  afficheDist(fermeture);
  fermetureTransitive2(arc, fermeture);
  afficheDist(fermeture);
  compFortConnexe(6, fermeture);
  
  return EXIT_SUCCESS;
}
