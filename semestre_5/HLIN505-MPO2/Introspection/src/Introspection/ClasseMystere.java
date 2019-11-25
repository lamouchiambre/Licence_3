package Introspection;

import java.lang.reflect.*;
//import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;

//import java.util.*;
//import java.lang.*;

public class ClasseMystere<E> {
	private List<E> list;
	
	public Method[] getMethode(int i){
		return list.get(i).getClass().getDeclaredMethods();
		
	}
	
	
	public List<E> getList() {
		return list;
	}


	public void setList(List<E> list) {
		this.list = list;
	}
	

	public ClasseMystere(List<E> list) {
		this.list = list;
	}


	public static void main(String[] args){
		List<Integer> l = new ArrayList(); 
		l.add(1);
		l.add(2);
		ClasseMystere<Integer> c = new ClasseMystere<Integer>(l);
		
		Method[] m = c.getMethode(1);
		
		System.out.println(m[0]);
	}
	

	
	
}