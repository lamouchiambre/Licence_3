package tpStream;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Promotion {
	private ArrayList<Etudiant> etudiant;

	public ArrayList<Etudiant> getEtudiant() {
		return etudiant;
	}

	public void setEtudiant(ArrayList<Etudiant> etudiant) {
		this.etudiant = etudiant;
	}
	
	public int ageMinEtudiant(){
		return etudiant.stream()
				.filter(e->e.getModalite() == ModaliteCandidature.eCandidat)
				.mapToInt(e->e.getAge())
				.min()
				.getAsInt();
	}
	
	
	public int nbEtudiant(ModaliteCandidature M){
		return (int) etudiant.stream()
				.filter(e->e.getModalite() == M)
				.count();
	}
	
	public List<Etudiant> plusVieuxEtudiant(){
		int ageMax = etudiant.stream()
				.mapToInt(e->e.getAge())
				.max()
				.getAsInt();
		return etudiant.stream()
				.filter(e->e.getAge()== ageMax)
				.collect(Collectors.toList());
	}
}
