

import java.util.*;

class TextAnalyzer {

    private String text;

    TextAnalyzer(String text) {
        this.text = text;
    }

    public void analyze() {
        int vowels = 0, consonants = 0, digits = 0, spaces = 0, special = 0;

        text = text.toLowerCase();

        for (int i = 0; i < text.length(); i++) {
            char ch = text.charAt(i);

            if (ch >= 'a' && ch <= 'z') {
                if ("aeiou".indexOf(ch) != -1)
                    vowels++;
                else
                    consonants++;
            } else if (ch >= '0' && ch <= '9') {
                digits++;
            } else if (ch == ' ') {
                spaces++;
            } else {
                special++;
            }
        }

        int totalChars = text.length();
        int letters = vowels + consonants;

        System.out.println("----- TEXT ANALYSIS -----");
        System.out.println("Original Text: " + text);
        System.out.println("Total Characters: " + totalChars);
        System.out.println("Letters: " + letters);
        System.out.println("Vowels: " + vowels);
        System.out.println("Consonants: " + consonants);
        System.out.println("Digits: " + digits);
        System.out.println("Spaces: " + spaces);
        System.out.println("Special Characters: " + special);

        System.out.println("\n----- STATISTICS -----");
        System.out.printf("Vowel %%: %.2f%%\n", (vowels * 100.0) / totalChars);
        System.out.printf("Consonant %%: %.2f%%\n", (consonants * 100.0) / totalChars);
        System.out.printf("Digit %%: %.2f%%\n", (digits * 100.0) / totalChars);
        System.out.printf("Special Char %%: %.2f%%\n", (special * 100.0) / totalChars);
    }
}

public class SLQ5 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String input = sc.nextLine();

        TextAnalyzer analyzer = new TextAnalyzer(input);
        analyzer.analyze();

        sc.close();
    }
}
