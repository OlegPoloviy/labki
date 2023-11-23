#include "Heap.h"


void Heap::MaxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = Left(i);
    int r = Right(i);
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        MaxHeapify(arr, n, largest);
    }
}

void Heap::MinHeapify(int arr[], int n, int i) {
    int smallest = i;
    int l = Left(i);
    int r = Right(i);

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        MinHeapify(arr, n, smallest);
    }
}

void Heap::BuildMaxHeap(int arr[], int n) {
    for (int i = n / 2; i >= 0; i--) {
        MaxHeapify(arr, n, i);
    }
}

void Heap::BuildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heap::MinHeapify(arr, n, i);
}

void HeapSort(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heap::MaxHeapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        Heap::MaxHeapify(arr, i, 0);
    }
}
void Heap::HeapSortDescending(int arr[], int n) {
    Heap::BuildMinHeap(arr, n);
    for (int i = n - 1; i >= 1; i--) {
        std::swap(arr[0], arr[i]);
        Heap::MinHeapify(arr, i, 0);
    }
}


int Heap::Parent(int i) {
    return (i - 1) / 2;
}

int Heap::Left(int i) {
    return 2 * i + 1;
}

int Heap::Right(int i) {
    return 2 * i + 2;
}
