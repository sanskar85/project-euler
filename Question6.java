/*
 * The sum of the squares of the first ten natural numbers is,
 * The square of the sum of the first ten natural numbers is,
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is .
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
package project_eular;

public class Question6 {
	public static void main(String[] args) {
		int sum_of_squares=0,sum_of_natural_numbers=0;
		for(int i=1;i<=100;i++) {
			sum_of_natural_numbers+=i;
			sum_of_squares+=Math.pow(i, 2);
		}
		System.out.print(((int)Math.pow(sum_of_natural_numbers,2)-sum_of_squares));

	}

}
/*Output
 * 25164150
 * */
