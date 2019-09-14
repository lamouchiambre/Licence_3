package cercleSportif;

public class HeureSimple {
	private int heure;
	private int minute;
	
	public HeureSimple(int h, int m) {
		if (h >= 0 && h <= 23) {
			heure = h;
		} else {
			System.out.println("ERROR : Les heures sont comprisent entre 0 et 23.");
		}
		if (m >= 0 && m <= 59 ) {
			minute = m - m%5;
		} else {
			System.out.println("ERROR : Les minutes sont comprisent entre 0 et 59. (Granularité de 5 minutes)");
		}
	}
	
	public int getHeure() { return heure; }
	public void setHeure(int h) { 
		if (h >= 0 && h <= 23) {
			this.heure = h; 
		} else {
			System.out.println("ERROR : Les heures sont comprisent entre 0 et 23.");
		}
	}
	
	public int getMinute() { return minute; }
	public void setMinute(int m) {
		if (m >= 0 && m <= 59) {
			this.minute = m - m%5; 
		} else {
			System.out.println("ERROR : Les minutes sont comprisent entre 0 et 59. (Granularité de 5 minutes)");
		}
	}
	
	public String toString() {
		String result = "";
		if (heure < 10){
			result += "0";
		}
		result += heure + ":";

		if (minute < 10) {
			result += "0";
		}
		result += minute;

		return result;
	}

	public boolean sup(HeureSimple h){
		if(this.getHeure() >= h.getHeure() && this.getMinute() >= h.getMinute()){
			return true;
		}
		else{
			return false;		
		}
	}

	public static void main(String[] args) 
	{
		HeureSimple hs = new HeureSimple(17, 56);
		System.out.println(hs);
	}
	
}
