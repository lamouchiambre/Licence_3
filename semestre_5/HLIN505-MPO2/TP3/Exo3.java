package TP3;

import java.io.*;

public class Exo3 {
  private String name;

  public void createFile(String name) throws IOException {
    BufferedReader lectureClavier = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter ecritureFichier = new BufferedWriter(new FileWriter(name));
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

  public void readFile(String name) throws IOException {
    BufferedReader lectureFichier = new BufferedReader(new FileReader("essai.txt"));
    System.out.println("Lecture du fichier " + name);

    String s = lectureFichier.readLine();
    while(s != null) {
      System.out.println(s);
      s = lectureFichier.readLine();
    }
    lectureFichier.close();
    System.out.println("Fin du fichier");
  }

  public static void main(String[] args) {
    System.out.print("hello");
  }
}