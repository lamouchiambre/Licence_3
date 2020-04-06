#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include<arpa/inet.h>
#include<string.h>

/* Rôle du client : envoyer une demande de connexion à un serveur,
   envoyer une chaîne de caractères à ce serveur (la chaîne de
   caractère est à saisir au clavier), recevoir un entier et comparer
   cet entier avec le nombre d'octets envoyés. L'idée est de mettre en
   place les bases qui vous permettront par la suite une mise en
   oeuvre correcte des communications en TCP et de vérifier les
   échanges effectués */



  int TCPsend(int sock, char * msg, int sizeMsg){

    int cpt=0;
    int r;
    int envoie=0;
    while(envoie < sizeMsg){
      r = send(sock, msg, sizeMsg-envoie , 0);
      if (r == 0)
      {
        return 0;
      }
      else if (r == -1){
        return -1;
      }
      else{
        envoie = envoie + r;
        cpt++;
      }
    }
    printf("J'ai fais %i tour de boucle send\n",cpt);
    return envoie;
  }



int main(int argc, char *argv[]) {

  /* je passe en paramètre l'adresse de la socket d'écoute du serveur
     (IP et numéro de port). Je teste donc le passage de parametres */

  if (argc != 4){
    printf("utilisation : %s ip_serveur port_serveur et ittération de boucle \n", argv[0]);
    exit(0);
  }

  /* Etape 1 : créer une socket */   
  int ds = socket(PF_INET, SOCK_STREAM, 0);

  /* /!\ : Il est indispensable de tester les valeurs de retour de
     toutes les fonctions et agir en fonction des valeurs possibles.*/
  if (ds == -1){
    printf("Client : pb creation socket\n");
    exit(1); // je choisis ici d'arrêter le programme car le reste
	     // dépendent de la réussite de la création de la socket.
  }
  
  /* J'alimente le programme avec des traces d'exécution pour observer ce
     qui se produit à l'exécution et pour mieux localiser les erreurs. */
  printf("Client: creation de la socket : ok\n");
  
  // Je peux déjà tester l'exécution de cette étape avant de passer à la suite.
  
  /* Etape 2 : designer la socket du serveur : avoir une structure qui
     contient l'adresse de cette socket (IP + numéro de port. */
  struct sockaddr_in adrServ;
  adrServ.sin_addr.s_addr = INADDR_ANY ;
  adrServ.sin_family = AF_INET;
  adrServ.sin_port = htons(atoi(argv[2]));
    
  int lgAdr = sizeof(struct sockaddr_in);
    
  /* Etape 3 : envoyer une demande de connexion au serveur.*/
  int conn = connect(ds, (struct sockaddr *) &adrServ, lgAdr) ;
  // je traite les valeurs de retour
  if (conn <0){
    perror ("Client: pb au connect :");
    close (ds); // je libère les ressources avant de terminer.
    exit (1); // je choisi de quitter le programme : la suite dépend
	      // de la réussite de l'envoi de la demande de connexion.
  }

  // je continue à alimenter le programme avec traces d'exécution
  printf("Client : demande de connexion reussie \n");

  // Je peux tester l'exécution de cette étape avant de passer à la suite.
  
  /* Etape 4 : envoyer un message au serveur. Ce message est une chaîne de caractères saisie au clavier. Vous pouvez utiliser une autre fonction pour la saisie. */

  printf("saisir un message à envoyer (moins de 1500 caracteres) \n");
  char m[1500]; 
  fgets(m, sizeof(m), stdin); // copie dans m la chaîne saisie que
			      // clavier (incluant les esaces et le
			      // saut de ligne à la fin).
  //m[strlen(m)-1]  = '\0'; // je retire le saut de ligne                                      

  int snd = 0;
  int cpt =0;

  int nbeOctet=strlen(m);

if (strlen(m)> 202)
  {
    for (int i = 0; i < atoi(argv[3]); ++i)
    {
      TCPsend(ds, (char *) &nbeOctet, sizeof(int));   // Envoie de la taille qu'aura la chaine (prevenir le serveur)

      snd = snd + TCPsend(ds, (char *) &m, nbeOctet);
      printf("Envoie %i: %i octets envoyés \n",i ,snd);
      cpt++;
    }

  }
  else{
    for (int i = 0; i < atoi(argv[3]); ++i)
    {
        TCPsend(ds, (char *) &nbeOctet, sizeof(int));
        snd = snd + TCPsend(ds, (char *) &m, nbeOctet);
        printf("Envoie %i: %i octets envoyés  \n",i ,snd);
        cpt++;
    }  
  }



  if (snd == -1){
    printf("Client : send n'a pas fonctionné");
    close(ds);
    exit(1);
  }

  /* Afficher le nombre d'octets EFFECTIVEMENT déposés dans le buffer
     d'envoi de la socket cliente. : /!\ Faire la différence entre le
     nombre d'octet qu'on demande à déposer / envoyer et le nombre
     d'octets qu'on a effectivement déposés.*/
  
  printf("Client : j'ai déposé %d octets \n", snd);
  printf("J'ai fais %i tour de boucle TCPsend \n\n",cpt);


  // Je peux tester l'exécution de cette étape avant de passer à la suite. 
  
  /* Etape 5 : reception d'une réponse du serveur. La réponse est un
     entier représentant le nombre d'octets du message que le serveur
     a effectivement reçu à l'étape précédente. Pour cet exercice,
     faire un seul appel de la fonction recv(..). */

  /* /!\j'alimente toujours le programme avec traces d'exécution. A noter
     qu'il est aussi important d'afficher un message avant une action
     qui peut être bloquante. Vous saurez ainsi à quelle étape de
     l'exécution le blocage se produit. */

  printf("Client : envoi fait, j'attends la reponse du serveur \n");
  
  int reponse;
  int rcv = recv  (ds, &reponse, sizeof(int), 0) ;
  /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
  if (rcv == -1){
     printf("Client : recv n'a pas fonctionné");
  }

  /* Etape 6 : je compare le nombre d'octets déposés (envoyés) avec
     la valeur reçue. L'objectif est d'avoir la même valeur. */

  printf("Client : j'ai envoyé %d octets  \n", snd) ;


  /* Etape 7 : je termine proprement. */

  close (ds);
  printf("Client : je termine\n");
}



/*

  char test[50];
  scanf("%s",test);

*/