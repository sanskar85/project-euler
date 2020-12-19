/*
 * A palindromic number reads the same both ways. 
 * The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * */
package project_eular;

public class Question4 {
	public static void main(String[] args) {
		int curr_res=0;
		for(int num1=999;num1>=100;num1--) {
			for(int num2=999;num2>=100;num2--) {
				int product =num1*num2;
				StringBuffer sb=new StringBuffer(product+"");
				if(sb.toString().equals(sb.reverse().toString())) {
					if(product>curr_res) {
						curr_res=product;
//						this replace the newly found palindrome to previously found result
					}
				}
			}
		}
		System.out.print(curr_res);
	}

}
/*
 * Output
 * 906609
 * */
 
