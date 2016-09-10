#include <iostream>
#include <cmath>
using namespace std;

int* merge(int* A, int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    // create L and R
    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++) {
        L[i] = A[p+i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = A[q+j+1];
    }

    L[n1] = INFINITY;
    R[n2] = INFINITY;

    i = 0;
    j = 0;
    k = p;

    // check if not at end of divided lists
    while(i < n1 && j < n2) {
        if (R[j] < L[i]) {
            A[k++] = R[j++];
        } else {
            A[k++] = L[i++];
        }
    }

    // if one of the indices reaches
    // the end of its correspondent list
    // copy the rest to the array
    while(i < n1) {
        A[k++] = L[i++];
    }
    while(j < n2) {
        A[k++] = R[j++];
    }

    return A;
}

int* mergesort(int* A, int p, int r) {
    if (p < r) {
        int q = floor((p+r)/2);
        A = mergesort(A, p, q);
        A = mergesort(A, q+1, r);
        A = merge(A, p, q, r);
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

    A = mergesort(A, 0, 4);

    for (int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
