
public class SLQ11 {

    public static <T extends Number & Comparable<T>> T findMin(T[] array) {
        if (array == null || array.length == 0) {
            throw new IllegalArgumentException("Array cannot be null or empty.");
        }

        T min = array[0];
        for (T element : array) {
            if (element.compareTo(min) < 0) {
                min = element;
            }
        }
        return min;
    }

    public static void main(String[] args) {

        Integer[] intArray = {10, 5, 20, 3, 15};
        Double[] doubleArray = {12.5, 3.7, 8.9, 2.1};

        System.out.println("Minimum in intArray: " + findMin(intArray));
        System.out.println("Minimum in doubleArray: " + findMin(doubleArray));
    }
}