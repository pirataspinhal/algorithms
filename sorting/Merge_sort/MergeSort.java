import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Generic Java implementation of the merge-sort algorithm.
 * @author Solange U. Gasengayire
 * @since 24/10/2017
 */
public class MergeSort<T extends Comparable<T>> {

    /**
     * Returned a sorted list of elements of type T
     * @param elements the list to sort
     * @return the sorted list
     */
    public List<T> sort(final List<T> elements) {
        if (elements.size() < 2) {
            return elements;
        }

        final int endIndex = elements.size();
        final int midIndex = endIndex / 2;
        final List<T> leftHalf = elements.subList(0, midIndex);
        final List<T> rightHalf = elements.subList(midIndex, endIndex);

        return merge(sort(leftHalf), sort(rightHalf));
    }

    /**
     * Merge two sorted lists while preserving the order
     * @param left the first sorted list
     * @param right the second sorted list
     * @return the merged sorted list
     */
    private List<T> merge(final List<T> left, final List<T> right) {
        int leftIndex = 0;
        int rightIndex = 0;

        final List<T> merged = new ArrayList<>(
                left.size() + right.size());

        while (leftIndex < left.size() && rightIndex < right.size()) {
            //Compare the current element in the left list to the current
            // element in the right list to preserve the sorting order
            if (left.get(leftIndex).compareTo(right.get(rightIndex)) < 0) {
                merged.add(left.get(leftIndex));
                leftIndex++;
            } else {
                merged.add(right.get(rightIndex));
                rightIndex++;
            }
        }

        // Let's add the remaining elements from the left list
        // (if there are any left)
        while (leftIndex < left.size()) {
            merged.add(left.get(leftIndex));
            leftIndex++;
        }

        // Let's add the remaining elements from the right list
        // (if there are any left)
        while (rightIndex < right.size()) {
            merged.add(right.get(rightIndex));
            rightIndex++;
        }

        return merged;
    }

    /**
     * Tester method
     * @param args command-line arguments
     */
    public static void main(String... args) {
        // Sort a list of integers
        List<Integer> numbers = new ArrayList<>(
                Arrays.asList(56, 98, 74, 36, 24, 104, 222, 4));
        MergeSort<Integer> intSort = new MergeSort<>();
        List<Integer> sorted = intSort.sort(numbers);
        sorted.forEach(element -> System.out.print(element + " "));
        System.out.println();

        // Sort a list of strings
        List<String> words = new ArrayList<>(
                Arrays.asList("Java","Scala", "Kotlin", "Clojure", "Groovy", "Jython"));
        MergeSort<String> strSort = new MergeSort<>();
        List<String> result = strSort.sort(words);
        result.forEach(word -> System.out.print(word + " "));
    }
}
