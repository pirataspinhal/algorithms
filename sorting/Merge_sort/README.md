## Merge Sort

The idea of the [merge sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm is to sort smaller arrays (or lists) and then combine those arrays (lists) together (merge them) in sorted order. It's a [divide-and-conquer](https://en.wikipedia.org/wiki/Divide_and_conquer_algorithm), [recursive](https://en.wikipedia.org/wiki/Recursion) algorithm.

**Outline**

````java
Sort the left half of the array/list assuming size of array/list n > 1
Sort the right half of the array/list assuming size of array/list n > 1
Merge the two halves together
````

- **Worst-case scenario**
We have to split n elements up and then recombine them, effectively doubling the sorted subarrays (sublists) as we build them up. (Combining sorted 1-element arrays into 2-element arrays, combining sorted 2-element arrays into 4-element arrays, ...)

- **Best-case scenario**
The arrays is already perfectly sorted. But we still have to split and recombine it back together with this algorithm.

- **Time Complexity**
  Merge sort has a performance of Θ(n log n) : each merge operation is Θ(n), and each recursive call works on only half of the given array (list).
