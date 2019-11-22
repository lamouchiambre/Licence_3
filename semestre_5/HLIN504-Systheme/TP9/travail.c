#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void* travail(void*arg){
  printf("%u: travail(%s)\n",pthread_self(),(char*) arg);
  return (void*)"fini !";}





int main(int argc, char*argv[]){
  pthread_t tid; /*id du thread*/
  if (0 != pthread_create (&tid, NULL, travail, "Bonjour !"))
    {
      // (id, attributs, fonction à exécuter, arg de la fon)
      printf("création du thread impossible !\n");
      exit(1);}
  printf("\n %u: thread %u créé et lancé !\n",pthread_self(),tid);
  void*res;pthread_join(tid, &res); // wait du thread et récup  retour

  printf("%u: thread %u terminé en renvoyant \"%s\"\n",pthread_self(), tid, (char*)res);
  return 0;
  
  }