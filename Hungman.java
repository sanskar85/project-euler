package others; // change this accordingly

import java.util.Scanner;

public class hungman {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		char proceed='y';
		do {
			System.out.print("Enter maximum prefered length (should be >6) ");
			int length = scanner.nextInt();
			StringBuffer text = new StringBuffer(generateRandomString(length));
			String tempText = text.toString();
			StringBuffer hiddenText = new StringBuffer(getHiddenChar(length));
			int missCounter=0;
			while(!tempText.equalsIgnoreCase(hiddenText.toString())) {
				System.out.print("Enter a letter in word "+hiddenText.toString()+" > ");
				char c = scanner.next().toLowerCase().charAt(0);
				int index = text.indexOf(c+"");
				int in = hiddenText.indexOf(c+"");
				if(index>-1) {
					hiddenText.replace(index, index+1, c+"");
					text.replace(index, index+1, "*");
				}else if(in != -1) {
					System.out.println(c+" is already in the word");
				}
				else {
					System.out.println(c + " is not in the word");
					missCounter++;
				}
			}
			System.out.println("The word is "+hiddenText.toString()+". You missed "+missCounter+" times");
			System.out.print("Do you want to guess another word? Enter y or n >");
			proceed = scanner.next().toLowerCase().charAt(0);
		}while(proceed=='y');

	}

	private static String getHiddenChar(int length) {
		StringBuffer sBuffer = new StringBuffer();
		while(length-->0) {
			sBuffer.append("*");
		}
		return sBuffer.toString();
		// this method will generate random text
	}

	private static String generateRandomString(int length) {
		StringBuffer sb = new StringBuffer();
		while (length-->0) {
			int randomChar = 97 + (int) (Math.random() * 26);
			char c =(char) randomChar;
			sb.append(c);
		}
		return sb.toString();
		// this method will generate * as hidden text
	}

}
