package tp3;

import java.io.*;

public class FicText1 {
    public static void main(String args[]) throws IOException {
	BufferedReader lectureClavier = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter ecritureFichier = new BufferedWriter(new FileWriter("essai.txt"));

	System.out.println("Entrez des lignes (Return pour terminer)");
	String s = lectureClavier.readLine();
	while (s.length() != 0) {
	    ecritureFichier.write(s); // TQ pas chaine vide
	    ecritureFichier.newLine();
	    s = lectureClavier.readLine();
	}
	ecritureFichier.close(); // ferme le fichier associe
	System.out.println("Fin saisie");
    }
}