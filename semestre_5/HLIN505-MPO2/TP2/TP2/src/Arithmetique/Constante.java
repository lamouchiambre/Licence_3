package Arithmetique;

public class Constante extends Expression{
	private float val;
	public Constante(float val){
		this.val = val;
	}

	public float eval(){
		return val;
	}
}
