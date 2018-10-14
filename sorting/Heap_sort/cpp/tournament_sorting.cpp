// C++ program to implement tournament sort
// More info can be found: https://en.wikipedia.org/wiki/Tournament_sort


#include <iostream>
#include <vector>
using namespace std;

void sort(int arr[], int n)
{
    int leafNodes[4];
    int subTree[2];
    int root;

    for (int i = 0; i < 4; ++i)
    {
        leafNodes[i] = arr[i];
        cout << leafNodes[i] << endl;       
    }

	for(int i = 0; i < n - 1; ++i)
    {
        min(leafNodes[i], leafNodes[i+1]);
        cout << "min of " << arr[i] << " and " << arr[i + 1] << " is " << min(arr[i], arr[i + 1]) << endl;

    }
}

/* A utility function to print integers */
void printIntegers(int arr[], int n)
{    
	for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
	cout << "\n";
}

// Test program
int main()
{
	int myInts[] = {12, 11, 9, 2, 6, 7, 10, 1, 3, 4, 8, 5};
    int size = sizeof(myInts)/sizeof(myInts[0]);

	sort(myInts, size);

	cout << "Sorted array is \n";
	printIntegers(myInts, size);
}
