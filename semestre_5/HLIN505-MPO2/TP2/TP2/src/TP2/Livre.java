package TP2;

public class Livre extends Document{
	private int nbChapitres;
	public int getNbChapitres(){
		return nbChapitres;
	}
	
	public Livre(String titre, int nbChapitres){
		super(titre);
		this.nbChapitres = nbChapitres;
	}
	
}
