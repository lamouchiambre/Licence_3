package cercleSportif;

/**
 * ListChainee
 */
public class ListChainee {

    private Node racine;
    private int nbListe;

    private static class Node {
        private String nom;
        private Node successeur;
        
        public Node(String nom) {
            this.nom = nom;
            this.successeur = null;
        }

        public void setSuccesseur(Node suc) {
            this.successeur = suc;
        }
        public String getNom() {
            return nom;
        }
        public Node getSuccesseur() {
            return successeur;
        }
        
        public String toString() {
            return nom;
        }
    }
    public ListChainee(Node noeue){
        nbListe = 1;
        racine = noeue;
    }
    public Node getRacine() {
        return racine;
    }
    public int getNbListe() {
        return nbListe;
    }

    public String toString() {
        String result = "";
        result += racine;
        for(int i = 1; i < nbListe; i++)
        {
          result +=i;
        }
        return result;
    }
    public static void main(String[] args) {
        ListChainee l = new ListChainee(new ListChainee("premier"));
    }
}