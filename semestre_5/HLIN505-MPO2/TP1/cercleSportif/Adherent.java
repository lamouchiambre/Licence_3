package cercleSportif;

import cercleSportif.EtatCivil;

public class Adherent {
    private String nom;
    private static int nombreAdherent = 0;
    private int num;
    private EtatCivil etatCivil;
    private int anneeAdhesion;

    public Adherent(String nom, EtatCivil etatCivil, int annee) {
        this.nom = nom;
        nombreAdherent++ ;
        num = nombreAdherent;
        this.etatCivil = etatCivil;
        this.anneeAdhesion = annee;
    }

    public int getNum(){
        return num;
    }

    public String toString(){
        return this.nom + " " + "numero adherant :"+ " " + this.num + " " +this.anneeAdhesion;
    }

    public void reAdhesion(int annee){
        anneeAdhesion = annee;
    }

    public EtatCivil getEtatCivil(){
        return this.etatCivil;
    }
    public static void main(String[] args) {
        System.out.println("bonjour");

        Adherent Ambre = new Adherent("Ambre",EtatCivil.F, 2019);
        Adherent Alexandre = new Adherent("Alexandre", EtatCivil.M, 2019);
        System.out.println(Ambre);
        System.out.println(Alexandre);
    }
}