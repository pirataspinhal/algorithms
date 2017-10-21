#include <iostream>
using namespace std;

int* bubbleSort(int* A, int size) {
    int temp;
    for (int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-1; j++) {
            if(A[j] > A[j+1]) {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    return A;
}

int main() {

    int* A = new int[5];
    for (int i = 0; i < 5; i++) {
        A[i] = 4-i;
        cout << A[i] << " ";
    }
    cout << endl;

    A = bubbleSort(A, 5);

    for (int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
