package Arithmetique;

public class ExpressionComplexe extends Expression{
	private Expression op1;
	private Expression op2;
	private char operateur;
	
	public ExpressionComplexe(Expression a, char op, Expression b){
		this.op1 = a;
		this.op2 = b;
		this.operateur = op;
	}
	
	public float eval(){
		float result = 88;
		System.out.println(operateur);
		switch(operateur){
			case '+':
				return op1.eval() + op2.eval();
			case '-':
				return op1.eval() - op2.eval();
			case '*':
				return op1.eval() * op2.eval();
			case '/':
				return op1.eval() / op2.eval();
		}
		
		return result;
	}
}
