package Introspection;

public class PersonnageBonus extends Personnage {
	private Integer seuilPoint;
	private Integer nbSeuillePoint;

	public Integer getSeuilPoint() {
		return seuilPoint;
	}

	public void setSeuilPoint(Integer seuilPoint) {
		this.seuilPoint = seuilPoint;
	}

	@Override
	public void addPointVie(Integer p) {
		// TODO Auto-generated method stub
		if(this.getNombrePoint() >= this.seuilPoint*this.nbSeuillePoint){
			this.nbSeuillePoint++;
			super.addPointVie(p);
		}
		
	}

	public PersonnageBonus(String nom, Integer nombrePoint, Integer nombreVie, Integer seuilPoint,
			Integer nbSeuillePoint) {
		super(nom, nombrePoint, nombreVie);
		this.seuilPoint = seuilPoint;
		this.nbSeuillePoint = nbSeuillePoint;
	}

	public PersonnageBonus() {
		super();
		// TODO Auto-generated constructor stub
	}
	public PersonnageBonus(String nom) {
		super(nom, 0, 100);
		// TODO Auto-generated constructor stub
	}
	
	
	
}
