package Arithmetique;

public abstract class Expression {
	public abstract float eval();
	public boolean equals(Object o){
		if (o instanceof Expression){
			return eval() == ((Expression)o).eval();
		}else{
			return false;
		}
	}
}
