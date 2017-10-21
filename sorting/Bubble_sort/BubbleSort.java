public class BubbleSort<T extends Comparable<T>> {
	
	public void sort(T[] array) {

		int limit = array.length-1;

		for (int i = 0; i < array.length; i++) {
			
			int j = 0;
			while (j < limit) {
				if (array[j].compareTo(array[j + 1]) > 0) {
					swap(array, j, j + 1);
				}
				j++;
			}
			limit--;
			
		}
	}

	private void swap(T[] array, int indexA, int indexB) {
		T aux = array[indexA];
		array[indexA] = array[indexB];
		array[indexB] = aux;
	}

}
