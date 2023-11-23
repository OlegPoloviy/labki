#include "Sort.h"
using namespace std;



void CountingSort(int arr[], int n, int maxVal)

{
    int* count = new int[maxVal + 1];
    int* sorted = new int[n];

    for (int i = 0; i <= maxVal; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        sorted[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sorted[i];
    }

    delete[] count;
    delete[] sorted;
}
