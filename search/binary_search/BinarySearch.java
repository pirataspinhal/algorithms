import java.util.Arrays;
import java.util.List;

/**
 * Generic binary search algorithm implementation.
 *
 * @author Solange U. Gasengayire
 * @since 24/10/2017
 */
public class BinarySearch<T extends Comparable<T>> {

    /**
     * Determine whether element T is part of the list data.
     * This algorithm assumes that the list is sorted in natural order.
     *
     * @param element the element to look for
     * @param data the list of elements of type T
     * @return true if data contains element, false otherwise
     */
    public boolean search(final T element, final List<T> data) {
        if (data == null || data.isEmpty() || element == null) {
            return false;
        }

        final int midIndex = data.size() / 2;
        final T midElement = data.get(midIndex);

        if (element.compareTo(midElement) == 0) {
            return true;
        } else if (element.compareTo(midElement) < 0) {
            return search(
                    element,
                    data.subList(0, midIndex));
        } else {
            final int n = data.size();
            return search(
                    element,
                    data.subList(midIndex + 1, n));
        }
    }

    /**
     * Determine whether element T is part of the array of elements of type T.
     * This algorithm assumes that the array is sorted in natural order.
     *
     * @param element the element to search for
     * @param array the elements array
     * @return true if the element is part of the array,
     *         false otherwise
     */
    public boolean search(final T element, final T[] array) {
        final int n = array.length;
        return search(element, array, 0, n);
    }

    /**
     * Helper method
     * @param element the element to search for
     * @param elements an array of elements of type T
     * @param lo the start index
     * @param hi the stop index
     * @return true if element is found in elements,
     *         false otherwise
     */
    private boolean search(final T element, final T[] elements,
                           final int lo, final int hi) {
        if (hi <= lo) {
            return false;
        }

        int mid = lo + (hi - lo) / 2;
        int comp = element.compareTo(elements[mid]);

        if (comp == 0) {
            return true;
        } else if (comp < 0) {
            return search(element, elements, lo, mid);
        } else {
            return search(element, elements, mid + 1, hi);
        }

    }

    /**
     * Tester method
     * @param args command-line arguments
     */
    public static void main(String... args) {

        BinarySearch<Double> doubleBS = new BinarySearch<>();
        Double[] doubles = {1.0, 4.0, 12.0, 26.0, 48.0, 104.0};
        List<Double> doubleList = Arrays.asList(doubles);
        System.out.printf("Is %.0f part of doubles? %s \n", 4.0,
                doubleBS.search(4.0, doubles) ? "YES" : "NO");
        System.out.printf("Is %.0f part of doubleList? %s \n", 3.0,
                doubleBS.search(4.0, doubleList) ? "YES" : "NO");

        BinarySearch<String> stringBS = new BinarySearch<>();
        String[] words = {"alpha", "bravo", "charlie", "delta", "echo", "foxtrot"};
        List<String> wordList = Arrays.asList(words);
        System.out.printf("Is %s part of words ? %s \n", "delta",
                stringBS.search("delta", words) ? "YES" : "NO");
        System.out.printf("Is %s part of words ? %s \n", "tango",
                stringBS.search("tango", wordList) ? "YES" : "NO");

    }

}
