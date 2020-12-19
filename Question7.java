/*
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * What is the 10 001st prime number?
*/
package project_eular;

import java.util.ArrayList;

public class Question7 {
	public static void main(String[] args) {
		int prime_index = 10001;
	    int curr_num, count, i;
	    curr_num=1;
	    count=0;
	 
	    while (count < prime_index){
	    	curr_num=curr_num+1;
	      for (i = 2; i <= curr_num; i++){ //Here we will loop from 2 to the last number checked +1
	        if (curr_num % i == 0) {
	          break;
	        }
	      }
	      if ( i == curr_num){
	    	  //if it is not prime i will never reach to curr_num as it will be breaked in between so if i==curr_num is true  curr_num is a prime number
	    	  
	        count = count+1;
	      }
	    }
	    System.out.println(curr_num);
  }
}
/*
 * Output 
 * 104743
 * */
