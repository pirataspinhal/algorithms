public class InsertionSort<T extends Comparable<T>> {

	public void sort(T[] array) {

		for (int i = 0; i < array.length; i++) {
			insertInOrdered(array, i);
		}
	}

	private void insertInOrdered(T[] array, int index) {

		while (index != 0) {
			if (array[index].compareTo(array[index - 1]) >= 0)
				break;
			swap(array, index, index - 1);
			index = index - 1;
		}
	}

	private void swap(T[] array, int indexA, int indexB) {
		T aux = array[indexA];
		array[indexA] = array[indexB];
		array[indexB] = aux;
	}

}
