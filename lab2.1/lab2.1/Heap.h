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
    void HeapSort(int arr[], int n );
    void HeapSortDescending(int arr[], int n);
} 

#endif