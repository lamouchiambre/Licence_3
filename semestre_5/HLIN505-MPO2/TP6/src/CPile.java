import java.util.*;

public class CPile<A> implements IPile<A> {
	
	private LinkedList<A> list;
	public CPile(){
		list = new LinkedList<A>();
	}
	public A depile(){
		return list.removeFirst();
	}
	public void empile(A a){
		list.addFirst(a);
	}
	public boolean estVide(){
		return list.size()==0;
	}
	public int nbElements(){
		return list.size();
	}
	public A sommet(){
		return list.peek();
	}
//	public void toString(){
//		str
//	}
}
