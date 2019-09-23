package tp3;

import java.io.*;

public class FicText2 {
    public static void main(String args[]) throws IOException {
	BufferedReader lectureFichier = new BufferedReader(new FileReader("essai.txt"));
	System.out.println("Lecture du fichier essai.txt");
	String s = lectureFichier.readLine();

	/* readLine() retourne :
la ligne lue jusqu'au retour chariot (lu mais non retourne)
donc une chaine vide si la ligne ne comporte qu'un RC
la valeur null s'il n'y a rien à lire (fin du flux de données)
	*/
	while(s != null) {
	    System.out.println(s);
	    s = lectureFichier.readLine();
	}
	lectureFichier.close();
	System.out.println("Fin du fichier");
    }
}