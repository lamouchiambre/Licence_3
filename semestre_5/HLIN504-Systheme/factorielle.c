#include <stdio.h>
#include <stdlib.h>

int factorielle(int n){
  if( n ==0){
    return 1;
  }
  else{
    return n * factorielle(n-1);
  }
}

int** pascal(int n){
  int **triangle = (int**) malloc(n*sizeof(int*));  
  for(int i = 0; i < n; i++){
    triangle[i] = (int*) malloc(n *sizeof(int));
        for(int j = 0; j < n; i++){
	  if(j==0){
	    triangle[i][j]=1;
	      }
	  else{
	    triangle[i][j]=0;
	  }
    }
  }

  for(int i = 1; i < n; i++){
        for(int j = 1; j < n; i++){
	  triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
	  printf("%i ", triangle[i][j]);
    }
	printf("\n");
  }
  return triangle;
}
int main(){

  //printf("%i",factorielle(3));
  pascal(4);
  factorielle(3);

}
