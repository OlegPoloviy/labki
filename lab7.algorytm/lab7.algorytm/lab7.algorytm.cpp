#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
    int n, maxVal;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the maximum value of the elements: ";
    cin >> maxVal;

    int* arr = new int[n];

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    CountingSort(arr, n, maxVal);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}