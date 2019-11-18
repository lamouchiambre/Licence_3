package tpStream;

import java.util.List;

public class CollectionFeuilleSalaire {
	private List<FeuilleSalaire> feuilles = new ArrayList<>();
	
	public void print(){
		feuilles.stream().forEach(f->System.out.println(f));
	}
	public void printbis(){
		feuilles.forEach(System.out::println);
	}
	public void sortv1(){
		Collection.sort(feuilles, new MonComparator()){}
	}
	public void sort_v2(feuilles,
			new Comparator<FeuilleSalaire>(){
			public int compare(FeuilleSalaire f1, FeuillesSalaire f2{ return;})
			)
	}
	public void sort_v3(){
		Collection.sort(feuilles, f1, F2)->Doublr.compare(f1, f2));
	}
}
