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

int Heap::HeapMaximum(int arr[]) {
    return arr[0];
}

int Heap::HeapExtractMax(int A[], int& heap_size) {
    if (heap_size < 1) {
        std::cerr << "Heap underflow" << std::endl;
        return -1;
    }
    int max = A[0];
    A[0] = A[heap_size - 1];
    heap_size--;
    MaxHeapify(A, heap_size, 0); // оновлено виклик MaxHeapify()
    return max;
}

int Heap::HeapExtractMin(int A[], int& heap_size) {
    if (heap_size < 1) {
        std::cerr << "Heap underflow" << std::endl;
        return -1;
    }
    int min = A[0];
    A[0] = A[heap_size - 1];
    heap_size--;
    MinHeapify(A, heap_size, 0); // оновлено виклик MinHeapify()
    return min;
} 

void Heap::MaxHeapInsert(int arr[], int& n, int key) {
    n++;
    arr[n - 1] = INT_MIN;
    Heap::HeapIncreaseKey(arr, n - 1, key);
}

void Heap::HeapIncreaseKey(int A[], int i, int key) {
    if (key < A[i]) {
        std::cerr << "New key is smaller than current key\n";
        return;
    }
    A[i] = key;
    while (i > 0 && A[Parent(i)] < A[i]) {
        std::swap(A[i], A[Parent(i)]);
        i = Parent(i);
    }
}

void Heap::HeapDecreaseKey(int A[], int i, int key) {
    if (key > A[i]) {
        std::cerr << "New key is greater than current key\n";
        return;
    }
    A[i] = key;
    while (i > 0 && A[Parent(i)] > A[i]) {
        std::swap(A[i], A[Parent(i)]);
        i = Parent(i);
    }
}


void Heap::MinHeapInsert(int arr[], int& n, int key) {
    n++;
    arr[n - 1] = INFINITY;
    Heap::HeapDecreaseKey(arr, n - 1, key);
}

int Heap::HeapMin(int arr[]) {
    return arr[0];
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