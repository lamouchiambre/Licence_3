package cercleSportif;

public class Creneau {
	private Jour jour;
	private HeureSimple heureDebut;
	private HeureSimple heureFin;
	
	public Creneau (Jour j, HeureSimple hd, HeureSimple hf) {
		jour = j;
		if (hf.sup(hd)) {
			heureDebut = hd;
			heureFin = hf;
		}
		else{
			heureDebut = hf;
			heureFin = hd;
		}
	}

	public boolean chevauche(Creneau c){
		boolean result = false;
		int hd1 = this.heureDebut.getHeure();
		int md1 = this.heureDebut.getMinute();
		int hf1 = this.heureFin.getHeure();
		int mf1 = this.heureFin.getMinute();

		int hd2 = c.heureDebut.getHeure();
		int md2 = c.heureDebut.getMinute();
		int hf2 = c.heureFin.getHeure();
		int mf2 = c.heureFin.getMinute();

		if (hf1 > hd2 
			||
			hf1 == hd2 && mf1 > md2 
			||
			hd1 < hf2 
			||
			hd1 == hf2 && md1 < mf2 
			) {
			result = true;
		}
		
		return result;
	}
	
	public boolean inclus(Creneau c){
		boolean result = false;
		
		if (this.heureDebut.getHeure() <= c.heureDebut.getHeure() &&
			this.heureFin.getHeure() >= c.heureFin.getHeure() ||

			this.heureDebut.getHeure() == c.heureDebut.getHeure() &&
			this.heureDebut.getMinute() <= c.heureDebut.getMinute() &&
			this.heureFin.getHeure() == c.heureFin.getHeure() &&
			this.heureFin.getMinute() >= c.heureFin.getMinute() ||

			this.heureDebut.getHeure() == c.heureDebut.getHeure() &&
			this.heureDebut.getMinute() <= c.heureDebut.getMinute() &&
			this.heureFin.getHeure() >= c.heureFin.getHeure() ||

			this.heureFin.getHeure() == c.heureFin.getHeure() &&
			this.heureFin.getMinute() >= c.heureFin.getMinute() &&
			this.heureDebut.getHeure() >= c.heureDebut.getHeure()) 
		{
			result = true;
		}
		
		return result;
	}

	public Jour getJour() { return jour; }
	public void setJour(Jour jour) { this.jour = jour; }
	public HeureSimple getHeureDebut() { return heureDebut; }
	public void setHeureDebut(HeureSimple heureDebut) { this.heureDebut = heureDebut; }
	public HeureSimple getHeureFin() { return heureFin; }
	public void setHeureFin(HeureSimple heureFin) { this.heureFin = heureFin; }

	public static void main(String[] args) 
	{
		Creneau c1 = new Creneau(Jour.Lundi, 
			new HeureSimple(9, 0),
			new HeureSimple(10, 0));

		Creneau c2 = new Creneau(Jour.Lundi, 
			new HeureSimple(9, 30),
			new HeureSimple(10, 30));

		Creneau c3 = new Creneau(Jour.Lundi, 
			new HeureSimple(10, 0),
			new HeureSimple(11, 0));

		System.out.println(c1.chevauche(c2)); 
		System.out.println(c1.chevauche(c3));
		System.out.println(c2.chevauche(c3));

		System.out.println(c1.inclus(c2)); 
		System.out.println(c1.inclus(c3));
		System.out.println(c2.inclus(c3));
	}
}
