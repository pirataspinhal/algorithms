public class BinarySearch {

    private int binarySearch(int array[], int l, int r, int x) {
        if (r >= l) {
            int mid = l + (r - l) / 2;

            if (array[mid] == x) {
                return mid;
            }

            if (array[mid] > x) {
                return binarySearch(array, l, mid - 1, x);
            }
            return binarySearch(array, mid + 1, r, x);
        }
        return -1;
    }

    // Driver method to test above
    public static void main(String args[]) {
        BinarySearch binarySearch = new BinarySearch();
        int array[] = {5, 10, 1, 15, 40};
        int x = 10;
        int result = binarySearch.binarySearch(array, 0, array.length - 1, x);

        if (result == -1) {
            System.out.println("Element not present");
        } else {
            System.out.println("Element found at index " + result);
        }
    }
}