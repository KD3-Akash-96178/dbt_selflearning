
import java.util.Comparator;
import java.util.Arrays;

public class SLQ12 {

    static <T> void selectionSort(T[] arr, Comparator<T> c) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (c.compare(arr[i], arr[j]) > 0) {
                    T temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        Integer[] intArray = {5, 2, 8, 1, 9};
        System.out.println("Original Integer Array: " + Arrays.toString(intArray));

        selectionSort(intArray, Comparator.naturalOrder());
        System.out.println("Sorted Integer Array (Ascending): " + Arrays.toString(intArray));

        String[] strArray = {"Apple", "Banana", "Orange", "Mango"};
        System.out.println("\nOriginal String Array: " + Arrays.toString(strArray));

        selectionSort(strArray, Comparator.reverseOrder());
        System.out.println("Sorted String Array (Descending): " + Arrays.toString(strArray));
    }
}
