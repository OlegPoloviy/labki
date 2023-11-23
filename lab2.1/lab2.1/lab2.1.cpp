#include <iostream>
#include "Heap.h"
#include "Heap.cpp"

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int* arr = new int[n];
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int choice;
    std::cout << "Choose the type of heap to build:\n1. Max Heap\n2. Min Heap\n";
    std::cin >> choice;

    if (choice == 1) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            Heap::MaxHeapify(arr, n, i);
        }
        std::cout << "Max Heap: " << std::endl;
    }
    else {
        for (int i = n / 2 - 1; i >= 0; i--) {
            Heap::MinHeapify(arr, n, i);
        }
        std::cout << "Min Heap: " << std::endl;
    }

    
    int levels = log2(n) + 1; 
    int levelIndex = 0; 

    for (int i = 0; i < levels; i++) { 
        int elementsInLevel = pow(2, i); 
        int padding = (n - elementsInLevel) / 2; 
        for (int j = 0; j < padding; j++) {
            std::cout << "   ";
        }
        for (int j = 0; j < elementsInLevel && levelIndex < n; j++) {
            std::cout << arr[levelIndex++] << "   ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl; 
    std::cout << "Choose the sorting order:\n1. Ascending\n2. Descending\n";
    std::cin >> choice;

    if (choice == 1) {
        HeapSort(arr, n);
        std::cout << "Sorted array (ascending order): ";
    }
    else {
        
        for (int i = n / 2 - 1; i >= 0; i--) {
            Heap::MaxHeapify(arr, n, i);
        }
       
        Heap::HeapSortDescending(arr, n);
        std::cout << "Sorted array (descending order): ";
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    delete[] arr; 

    return 0;
}
