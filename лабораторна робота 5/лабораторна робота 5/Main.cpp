#include <iostream>
#include "Sort.h"
#include "Sort.cpp"

using namespace std;

int main() {
    int arr[] = { 8, 4, 2, 5, 9, 1, 6, 3, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    MergeSort(arr, size);

    cout << "After sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}