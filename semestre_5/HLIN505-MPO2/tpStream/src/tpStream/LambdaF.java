package tpStream;

import java.util.stream.Stream;

public class LambdaF {

	static Stream<Integer> SuiteFbonacci(){
		int[] fibo = {0, 1};
		Stream<Integer> stream = Stream.generate(
				()->{
					int result = fibo[1];
					int fib3 = fibo[0] + fibo[1];
					fibo[0]= fibo[1]
					fibo[1] = fib3;
					return result;
				}) 
	}
}
