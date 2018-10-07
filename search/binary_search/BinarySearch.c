#include <stdio.h>

int binarySearch(int*, int, int, int);

int main()
{
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);

	int A[n];
	printf("Enter %d numbers:\n", n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &A[i]);

	int key;
	printf("Enter the number you want to search: ");
	scanf("%d", &key);

	int index = binarySearch(A, 0, n-1, key);

	if(index == -1)
		printf("Not found!\n");
	else
		printf("Number is at %d position\n", index+1);
	return 0;
}

int binarySearch(int A[], int low, int high, int key)
{
	if(low > high)
		return -1;

	int mid = (low+high)/2;

	if(A[mid] == key)
		return mid;
	else if(A[mid] > key)
		return binarySearch(A, low, mid-1, key);
	else
		return binarySearch(A, mid+1, high, key);
}