/*
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * a2 + b2 = c2
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 * 
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
*/
package project_eular;

public class Question9 {

	public static void main(String[] args) {
		int MAX_VALUE=1000;
		for(int a=1;a<MAX_VALUE;a++) {
			for(int b=1;b<MAX_VALUE;b++) {
				for(int c=1;c<MAX_VALUE;c++) {
					if((a+b+c)==1000) {
						int lhs=(int) (Math.pow(a, 2)+Math.pow(b, 2));
						int rhs=(int)Math.pow(c, 2);
						if(lhs==rhs) {
							long product= a*b*c;
							System.out.print(product);
							return;
						}
					}
				}
			}

		}
		
	}
	
}
/*
 * Output 
 * 31875000*/
