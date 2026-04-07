
import java.util.Scanner;
import java.util.stream.IntStream;

public class SLQ9 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of integers: ");
        int n = sc.nextInt();

        int[] numbers = new int[n];
        System.out.println("Enter " + n + " integers:");

        for (int i = 0; i < n; i++) {
            numbers[i] = sc.nextInt();
        }

        // Using streams to calculate sum
        int sum = IntStream.of(numbers).sum();

        System.out.println("Sum of the integers is: " + sum);

        sc.close();
    }
}