#ifndef HEAP_H
#define HEAP_H
namespace Heap {
    int Parent(int i);
    int Left(int i);
    int Right(int i);
    void MaxHeapify(int arr[], int n, int i);
    void MinHeapify(int arr[], int n, int i);
    void BuildMaxHeap(int arr[], int n);
    void BuildMinHeap(int arr[], int n);
    void HeapSort(int arr[], int n);
    void HeapSortDescending(int arr[], int n);
    int HeapMaximum(int arr[]);
    int HeapExtractMax(int A[], int& heap_size);
    void HeapIncreaseKey(int A[], int i, int key);
    void MaxHeapInsert(int arr[], int& heap_size, int key);
    void HeapDecreaseKey(int A[], int i, int key);
    int HeapExtractMin(int A[], int& heap_size);
    void MinHeapInsert(int arr[], int& n, int key);
    int HeapMin(int arr[]);
}

#endif