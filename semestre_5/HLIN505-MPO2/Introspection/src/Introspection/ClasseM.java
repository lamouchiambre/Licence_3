package Introspection;

import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ClasseM {
	private List<Object> list;
	public List<Object> getList() {
		return list;
	}
	public void setList(List<Object> list) {
		this.list = list;
	}
	
	public Method[] getMethode(int i){
		Method[] m = list.get(i).getClass().getMethods();
		List<Method> listMethodes = Arrays.asList(m);
		System.out.println("Class :" +list.get(i).getClass().getName());
		System.out.println("Methodes :");
		for( Method x : listMethodes){
			System.out.println(x.getParameterCount() +" "+ x.getName());
		}
		return m;
		
	}
	
	
	public ClasseM(List<Object> list) {
		super();
		this.list = list;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<Object> l = new ArrayList(); 
		l.add(1);
		l.add(2);
		l.add("Moi");
		ClasseM c = new ClasseM(l);
		
		Method[] m = c.getMethode(1);
		
	}

}