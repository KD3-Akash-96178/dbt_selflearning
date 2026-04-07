
import java.util.IntSummaryStatistics;
import java.util.stream.IntStream;

public class SLQ10 {
    public static void main(String[] args) {

        // Create IntStream from 1 to 10
        IntStream numbers = IntStream.rangeClosed(1, 10);

        // 1️⃣ Sum of numbers
        int sum = numbers.sum();
        System.out.println("Sum of numbers from 1 to 10: " + sum);

        // Need a new stream for summaryStatistics (streams cannot be reused)
        IntStream numbers2 = IntStream.rangeClosed(1, 10);

        // 2️⃣ Summary statistics
        IntSummaryStatistics stats = numbers2.summaryStatistics();

        System.out.println("\n--- Summary Statistics ---");
        System.out.println("Count: " + stats.getCount());
        System.out.println("Sum: " + stats.getSum());
        System.out.println("Min: " + stats.getMin());
        System.out.println("Max: " + stats.getMax());
        System.out.println("Average: " + stats.getAverage());
    }
}