package Introspection;

public class PersonageInvisible extends Personnage {
	private boolean estInvisible;
	private Integer tempsInvisible;

	public boolean isEstInvisible() {
		return estInvisible;
	}

	public void setEstInvisible(boolean estInvisible) {
		this.estInvisible = estInvisible;
	}

	public Integer getTempsInvisible() {
		return tempsInvisible;
	}

	public void setTempsInvisible(Integer tempsInvisible) {
		this.tempsInvisible = tempsInvisible;
	}
	
	public void rendreInvisible(){
		estInvisible = true;
	}
	public Integer tempsAttente(){
		return getTempsInvisible();
	}

	public PersonageInvisible() {
		super();
		this.estInvisible = false;
		this.tempsInvisible = 10;
		// TODO Auto-generated constructor stub
	}

	public PersonageInvisible(String nom, Integer nombrePoint, Integer nombreVie, boolean estInvisible, Integer tempsInvisible) {
		super(nom, nombrePoint, nombreVie);
		// TODO Auto-generated constructor stub
		this.estInvisible = estInvisible;
		this.tempsInvisible = tempsInvisible;
	}
	
	
}
