package cercleSportif;

import java.util.ArrayList;
public enum Lieu {
	stade1("stade de foot"),
	piscine2("piscine du centre");
	
	private String nom;
	private ArrayList<Creneau> creneauDisponibles = new ArrayList<Creneau>();
	
	private Lieu(String nom){
		this.setNom(nom);
	}
	
	public void ajoutCreneau(Creneau c){
		creneauDisponibles.add(c);
	}
	
	public boolean estDisponiblePendant(Creneau c){
		boolean result = false;
		for (Creneau cr:creneauDisponibles){
			if (cr.getJour() == c.getJour() &&
				cr.getHeureDebut() == c.getHeureDebut() &&
				cr.getHeureFin() == c.getHeureFin()) {
				result = true;
			}
		}
		return result;
	}

	public String getNom() { return nom; }
	public void setNom(String nom) { this.nom = nom; }
	public ArrayList<Creneau> getCreneauDisponibles() { return creneauDisponibles; }

	public static void main(String[] args) {

		Creneau c = new Creneau(Jour.Jeudi, 
			new HeureSimple(14,21), 
			new HeureSimple(15,21));
		
		Creneau s = new Creneau(Jour.Jeudi,
			new HeureSimple(9, 00),
			new HeureSimple(11, 00));

		stade1.ajoutCreneau(c);
		//stade1.ajoutCreneau(s);

		System.out.println(stade1.estDisponiblePendant(s));
		System.out.println(stade1.getNom());
		System.out.println(stade1.estDisponiblePendant(c));
		System.out.println("Les creneaux de stade1 :");
		for (Creneau cre : stade1.getCreneauDisponibles()) {
			System.out.println(cre.getHeureDebut() + " - " + cre.getHeureFin());
		}
	}
}
