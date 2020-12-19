/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
*/
package project_eular;

import java.util.ArrayList;

public class Question10 {

	public static void main(String[] args) {
		int curr_num=2;
	    long sum=0L;
	    ArrayList<Integer> primeArray=new ArrayList<>();
	    while(curr_num<2000000) {
	    	
	    	int prime=checkPrime(curr_num,primeArray);
	    	if(prime>-1) {
	    		primeArray.add(prime);
		    	sum+=prime;
	    	}
	    	if(curr_num==2) {
		    	curr_num++;
	    	}else
	    		curr_num=curr_num+2;
	    }
	    
	    System.out.println(sum);

	}

	private static int checkPrime(int curr_num, ArrayList<Integer> primeArray) {
		for(int i=0;i<primeArray.size();i++) {
    		if (curr_num % primeArray.get(i)== 0) {
    			return -1;
  	        }
    	}
		return curr_num;
	}

}
/*
 * Output
 * 142913828922
 * */
