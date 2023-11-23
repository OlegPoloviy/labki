#include <iostream>
#include "Sort.h"
#include "Sort.cpp"
#include <Windows.h>

using namespace std;

int main() {

    SetConsoleOutputCP(CP_UTF8);

    int size;
    cout << "Input array size: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Input array elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Array before sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    MergeSort(arr, size);

    cout << "Array after sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; 

    return 0;
}
