package Introspection;

import java.lang.reflect.*;

public class FabriquePersonnage {

	public Personnage creerPersonnage(String s){
		Class<Personnage> c = (Class<Personnage>).getClass().forName(s);
		return c.newInstance();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//FabriquePersonnage F =  
	}

}