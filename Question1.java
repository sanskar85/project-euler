/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
 *  The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
*/

package project_eular;

public class Question1 {
public static final int num1=3,num2=5,max_number=20;
	public static void main(String[] args) {
		int sum=0;
		int max_multiple3=max_number/num1;
		int max_multiple5=max_number/num2;

		sum+=getSummation(num1,max_multiple3);
		sum+=getSummation(num2,max_multiple5);
		

		System.out.print(sum);

	}
	static int getSummation(int number,int multiple_count ){
		int sum=0;
		for(int i=1;i<=multiple_count;i++) {
			int res=number*i;
			if(res>=max_number) {
				break;
			}
			sum+=res;
		
		}
		return sum;
	}

}
/*
 * Output
 * 266333
 * 
 * */
