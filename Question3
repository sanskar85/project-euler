/*
 * Question
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 * */
package project_eular;

public class Question3 {

	public static void main(String[] args) {
		long num=600851475143L;
		long greatestFactor=0L;
		while(num%2==0) {
			greatestFactor=2;
			num/=2;
		}
		//we are using 3 in next loop as we have filtered out 2 from previous loop
		for(int i=3;i<=Math.sqrt(num);i+=2) {
			while(num%i==0) {
				greatestFactor=i;
				num/=i;
			}
		}
		//checking still if number can be more factorised if yes then the left is the result
		// or the previous outcome will be the result
		if (num > 2) greatestFactor=num;
		System.out.print(greatestFactor);
	}

}
/*
 * Output :
 * 6857
 * */
