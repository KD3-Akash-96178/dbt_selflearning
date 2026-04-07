
import java.util.Scanner;
import java.util.stream.IntStream;
import java.math.BigInteger;

public class SLQ8 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int number = sc.nextInt();

        if (number < 0) {
            System.out.println("Factorial is not defined for negative numbers.");
            return;
        }

        BigInteger factorial = IntStream.rangeClosed(1, number)
                .mapToObj(BigInteger::valueOf)
                .reduce(BigInteger.ONE, BigInteger::multiply);

        System.out.println("Factorial of " + number + " is: " + factorial);

        sc.close();
    }
}