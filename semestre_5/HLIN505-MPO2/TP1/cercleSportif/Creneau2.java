package cercleSportif;


public class Creneau2 {
	private Jour jour;
	private Heure heureDebut;
	private Heure heureFin;
    
    private static class Heure {
        private int minute;
        private int heure;
        
        public Heure(int h, int m){
            this.heure=h;
            this.minute=m;
        }
        /*public int getHeure(){
            return this.heure;
        }

        public int getMinute(){
            return this.minute;
        }*/

        public String toString(){
            String result = "";

            if (heure<10) {
                result += "0";
            }

            result += heure;
            result += ":";

            if (minute<10){
                result +="0";
            }
            result += minute;
            
            return result;
        }

        
    }

    //Accesseur
    public Heure getHeureDebut(){
        return this.heureDebut;
    }

    public Heure getHeureFin(){
        return this.heureFin;
    }

    public Jour getJour(){
        return this.jour;
    }

    //Construteur
	public Creneau2 (Jour j, Heure hd, Heure hf) {
		jour = j;
		heureDebut = hd;
		heureFin = hf;
	
    }

    public String toString() {
        
        String result = "";
        result += jour + " " + heureDebut + " " + heureFin;
        return result;
    }
    
    public Heure createHeure(int h, int m){
        Creneau2.Heure heur = new Creneau2.Heure(h, m);
        return heur;
    }

	public static void main(String[] args) 
	{
        //Creneau2.Heure h = new Creneau2.Heure(11,22);
        Creneau2 c = new Creneau2(Jour.Jeudi, new Creneau2.Heure(10,20), new Creneau2.Heure(20,20));
        System.out.println(c);
	}
}
