/*
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

package project_eular;

public class Question5 {
	public static void main(String[] args) {
		int[] arr=new int[20];
		int lcm=1;
		int[] primes=new int[] {2,3,5,7,11,13,17,19};
		for(int a=1;a<=20;a++) {
			arr[a-1]=a; //initialises array of 1 to 20
		}
		int curr_checking_prime_index=0;
		while (true) { //a while loop to execute till all elements from 1 to 20 becomes 1
            int counter = 0; //we  know to generate lcm it takes maximum to the length of elements array 
            boolean can_be_divided = false; 
              
            for (int i = 0; i < 20; i++) { 
  
                if (arr[i] == 0) { 
                	System.out.print(0);
                    return ; 
                } 
                else if (arr[i] < 0) { 
                    arr[i] = arr[i] * (-1); //converts the negative number to positive
                } 
                if (arr[i] == 1) { 
                    counter++; //determines the current element has became proceed for next element
                } 
                if (arr[i] % primes[curr_checking_prime_index] == 0) { 
                	can_be_divided = true; 
                    arr[i] = arr[i] / primes[curr_checking_prime_index]; 
                } 
            } 
            	/*
            	 * if the number can be divided so we will multiply
            	 * the lcm with the prime number to get new lcm value*/
            if (can_be_divided) { 
                lcm = lcm * primes[curr_checking_prime_index]; 
            } 
            else { 
            	curr_checking_prime_index++; 
            } 
  
            // Check if all elements became  1 indicate  
            // we found all factors and terminate while loop. 
            if (counter == 20) { 
                System.out.print(lcm);
                return;
            } 
        } 
	}
}
/*Output
 * 232792560
 */
