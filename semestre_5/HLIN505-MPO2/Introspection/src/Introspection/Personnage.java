package Introspection;

public abstract class Personnage {
	private String nom;
	private Integer nombrePoint;
	private Integer nombreVie;
	
	
	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public Integer getNombrePoint() {
		return nombrePoint;
	}

	public void setNombrePoint(Integer nombrePoint) {
		this.nombrePoint = nombrePoint;
	}

	public Integer getNombreVie() {
		return nombreVie;
	}

	public void setNombreVie(Integer nombreVie) {
		this.nombreVie = nombreVie;
	}
	
	public void addPointVie(Integer p){
		this.nombreVie +=p;
	}

	public Personnage(String nom, Integer nombrePoint, Integer nombreVie) {
		this.nom = nom;
		this.nombrePoint = nombrePoint;
		this.nombreVie = nombreVie;
	}
	public Personnage() {
		this.nom = "Random";
		this.nombrePoint = 0;
		this.nombreVie = 100;
	}

	
}
