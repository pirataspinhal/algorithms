#include <iostream>
using namespace std;

void insertionSort(int list[], int size) {
    int i, j;
    int key;
    for (i = 1; i < size; i++) {
        key = list[i];
        j = i - 1;
        while ((j > -1) && (list[j] > key)) {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
}

int main() {
    
    int list[5] = {5, 4, 2, 1, 3};
    for (int i = 0; i < 5; i++) {
        cout << list[i];
    }
    cout << endl;
    
    insertionSort(list, 5);
    
    for (int i = 0; i < 5; i++) {
        cout << list[i];
    }
    cout << endl;
    
    return 0;
}