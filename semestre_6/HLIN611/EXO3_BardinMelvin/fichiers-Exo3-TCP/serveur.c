#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

// Rôle du serveur : accepter la demande de connexion d'un client,
// recevoir une chaîne de caractères, afficher cette chaîne et
// renvoyer au client le nombre d'octets reçus par le serveur.



  int TCPrecv (int sock, char * msg, int sizeMsg){  // FOnction qui gère la fragmentation des paquets TCP 

    int cpt=0;
    int r;
    int reception=0;
    while(reception < sizeMsg){
      r = recv(sock, msg, sizeMsg-reception , 0);
      if (r == 0)
      {
        return 0;
      }
      else if (r == -1){
        return -1;
      }
      else{
        reception = reception + r;
        cpt++;
      }
    }
    printf("Nombre d'appel total à rcv : %i\n",cpt);
    return reception;
    
  }


int main(int argc, char *argv[])
{
  // je passe en paramètre un numero de port pour la socket
  // d'écoute. Je teste donc le passage de paramètres
  
  if (argc<2){
    printf("utilisation: %s numero_port\n", argv[0]);
    exit(1);
  }
  
  /* Etape 1 : créer une socket (la socket qui permettra de recevoir
     les demandes de connexion.*/
 
  int ds = socket(PF_INET, SOCK_STREAM, 0);
  /* /!\ : Il est indispensable de tester les valeurs de retour de
     toutes les fonctions et agir en fonction des valeurs possibles.*/
  if (ds == -1){
    perror("Serveur : probleme creation socket");
    exit(1); // je choisis ici d'arrêter le programme car le reste
	     // dépendent de la réussite de la création de la socket.
  }
  

  // J'alimente le programme avec traces d'exécution pour observer ce
  // qui se produit à l'exécution et mieux localiser les erreurs. 
  printf("Serveur: creation de la socket : ok\n");


  // Je peux déjà tester l'exécution de cette étape avant de passer à la suite.
  
  /* Etape 2 : nommer la socket. Elle aura une ou des IP de la machine
     sur laquelle le programme sera exécuté et le numéro de port passé
     en paramètre*/

  
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(atoi(argv[1]));
  
  if(bind(ds, (struct sockaddr*)&server, sizeof(server)) < 0){
    perror("Serveur : erreur bind");
    close(ds); // je libère les ressources avant de terminer.
    exit(1); // je choisis de quitter le programme : la suite dépend de la réussite du nommage.
  }

  // je continue à alimenter le programme avec traces d'exécution
  printf("Serveur: nommage : ok\n");


  // Je peux tester l'exécution de cette étape avant de passer à la suite.


  /* Etape 3 : mise en ecoute de la socket nommée. Cette opération
     dédie la socket à la réception des demandes de connexion. Pour
     cet exercice, limiter la file des demandes de connexions à 5. */
  
  int ecoute = listen(ds, 10);
  if (ecoute < 0){
    printf("Serveur : je suis sourd(e)\n");
    close (ds);
    exit (1);
  } 
 
  // je continue à alimenter le programme avec traces d'exécution
  printf("Serveur: mise en écoute : ok\n");


  // Je peux tester l'exécution de cette étape avant de passer à la suite.

 
  /* etape 4 : attendre et traiter une demande de connexion d'un
     client. Rappel : lorsque le serveur accepte une demande de
     connexion, il crée une nouvelle socket. Cette dernière est
     connectée à celle du client et elle est à utiliser pour
     communiquer avec lui.*/

  // avant un appel à une fonction bloquante, il est intéressant
  // d'afficher un message le signalant. Vous saurez ainsi à quelle
  // étape de l'exécution le blocage se produit.
  printf("Serveur : j'attends la demande d'un client (accept) \n"); 
  
  struct sockaddr_in adCv ; // pour obtenir l'adresse du client accepté.
  socklen_t lgCv = sizeof (struct sockaddr_in);

  int dsCv = accept(ds, (struct sockaddr *) &adCv, &lgCv);
  if (dsCv < 0){ // je pense toujours à traiter les valeurs de retour.
    perror ( "Serveur, probleme accept :");
    close(ds);
    exit (1);
  }
  /* je peux afficher l'adresse de la socket du client accepté :
     adresse IP et numéro de port de la structure adCv. Attention à
     faire les conversions du format réseau vers le format
     hôte. Utiliser la fonction inet_ntoa(..) pour l'IP.*/
  printf("Serveur: le client %s:%d est connecté  \n", inet_ntoa(adCv.sin_addr),  htons(server.sin_port));

  // Je peux tester l'exécution de cette étape avant de passer à la suite.
 
  /* Etape 5 : réception d'un message de type chaîne de caractères */
  scanf("Attente du message");

  char buffer[500];

  int taille;
  int cpt=0;
  int oct_rcv =0;


  /* attendre un message dont la taille maximale est 500 octets. Pour
     cet exercice, il est demandé de ne faire qu'un seul appel à recv
     pour recevoir un message. */

  //int rcv = recv (dsCv, buffer, sizeof(buffer), 0) ;
  
  while(1){
    recv (dsCv, &taille, sizeof(int), 0);   // Recupère la taille de la prochaine chaine
    printf("Taille: %i\n",taille );  // Affiche La taille de la prochaine chaine ! (le client envoie la taille avant la chaine)
    

    int rcv = TCPrecv (dsCv, buffer, taille);  // Reception de la chaine avec gestion de la fragmentation de paquets
    
     // VERIFICATION DU RETOUR DE RCV
    if (rcv == -1){
      printf("Serveur : recv n'a pas fonctionné");
    }

    // Incrementation du compteur et des octets 
    oct_rcv = oct_rcv + rcv;
    cpt++;
    printf("Nombre d'appel total à TCPrcv: %i\n",cpt);
    printf("Nombre d'octets reçu depuis le debut: %i\n\n",oct_rcv);



  }


  //buffer[rcv]  = '\0'; //pour l'étape 1 de l'ex2
  

  /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
/*
  if (rcv == -1){
     printf("Serveur : recv n'a pas fonctionné");
  } */
  /* Afficher le nombre d'octets EFFECTIVEMENT reçus. : /!\ Faire la
     différence entre le nombre d'octets qu'on demande à extraire
     depuis le buffer de réception d'une socket et le nombre d'octets
     qu'on a effectivement réussi à extraire.*/
  /*
  printf("Serveur : j'ai recu %d octets \n",  rcv);
  printf("Serveur : contenu du message : %s \n",  buffer);
*/
  
  /* Etape 6 : répondre au client en lui envoyant le nombre d'octets
     effectivement reçus à l'étape 5. Pour cet exercice, faire un seul
     appel de la fonction send.*/ 
  
  //int snd = send(dsCv, &recv, sizeof(int), 0);
  
  /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
 /*
  if (snd == -1){
     printf("Serveur : send n'a pas fonctionné");
  }
 */
  /* Etape 7 : fermeture de la socket du client */ 
  printf("Serveur : fin du dialogue avec le client\n");
  close (dsCv);
  
  // Etape 8 : pour cet exercice, je ne traite qu'un client, donc, je termine proprement.
  close (ds);
  printf("Serveur : je termine\n");
}








