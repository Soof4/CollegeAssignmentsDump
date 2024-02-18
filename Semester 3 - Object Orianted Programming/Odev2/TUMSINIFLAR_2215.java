//Main_2215.java

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Main_2215 {
	private static char[] vowels = "aeuüoöıiAEUÜOÖIİ".toCharArray();

	
	public static void main(String[] args) {
		for (String sentence : CumlelereAyir("araba insan hayatını kolaylaştırır. birlik beraberlik güzeldir. türkçe olarak yaz.")) {
			HecelereAyir(sentence);
		}
	}
	
	
	public static String[] CumlelereAyir(String text) {
		String[] sentenceArr = text.split("[.]");
		
		for (int i = 0; i < sentenceArr.length; i++) {
			sentenceArr[i] = sentenceArr[i].trim() + ".";
		}

		return sentenceArr;
	}
	
	public static void HecelereAyir(String sentence) {
		String[] words = sentence.split(" ");
		
		for (int i = 0; i < words.length; i++) {
			String word = words[i];
			String newWord = word;
			int dashCount = 0;
			
			for (int j = 0; j < word.length(); j++) {
				
				// Rule 1
				if (j < word.length() - 2 &&
					word.charAt(j + 2) != '.' &&
					isVowel(word.charAt(j)) &&
					!isVowel(word.charAt(j + 1)) &&
					isVowel(word.charAt(j + 2))) {
						newWord = newWord.substring(0, j + 1 + dashCount) + "-" + newWord.substring(j + 1 + dashCount, word.length() + dashCount);
						dashCount++;
					}
				
				// Rule 2
				if (j < word.length() - 3 &&
					word.charAt(j + 1) != '.' &&
					isVowel(word.charAt(j)) &&
					!isVowel(word.charAt(j + 1)) &&
					!isVowel(word.charAt(j + 2)) &&
					isVowel(word.charAt(j + 3))) {
						newWord = newWord.substring(0, j + 2 + dashCount) + "-" + newWord.substring(j + 2 + dashCount, word.length() + dashCount);
						dashCount++;
				}
				
				// Rule 3
				if (j < word.length() - 2 &&
					word.charAt(j + 2) != '.' &&
					!isVowel(word.charAt(j)) &&
					!isVowel(word.charAt(j + 1)) &&
					!isVowel(word.charAt(j + 2))) {
						newWord = newWord.substring(0, j + 2 + dashCount) + "-" + newWord.substring(j + 2 + dashCount, word.length() + dashCount);
						dashCount++;
				}
			}
			
			System.out.print(newWord + " ");
		}
		
		System.out.println();
	}
	
	public static boolean isVowel(char c) {
		for (char v : vowels) {
			if (c == v) {
				return true;
			}
		}
		return false;
	}
}
