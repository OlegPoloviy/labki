#include <iostream>
#include <cmath> 
#include "Heap.h"'
#include "Heap.cpp"
using namespace std;
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arr[1000];
    int heap_size = 0;
    int choice, key;
    bool exit = false;

    while (!exit) {
        cout << "Enter your choice:" << endl;
        cout << "1. Enter array" << endl;
        cout << "2. Build Max Heap" << endl;
        cout << "3. MaxHeapInsert" << endl;
        cout << "4. HeapIncreaseKey" << endl;
        cout << "5. HeapExtractMax" << endl;
        cout << "6. HeapSortDescending" << endl;
        cout << "7. HeapMin" << endl;
        cout << "8. HeapExtractMin" << endl;
        cout << "9. MinHeapInsert" << endl;
        cout << "10. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Enter size of array: ";
                cin >> n;
                cout << "Enter array elements:" << endl;
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                    heap_size++;
                }
                break;
            }
            case 2: {
                Heap::BuildMaxHeap(arr, heap_size);
                cout << "Max heap built: ";
                printArray(arr, heap_size);
                break;
            }
            case 3: {
                cout << "Enter key to insert: ";
                cin >> key;
                Heap::MaxHeapInsert(arr, heap_size, key);
                heap_size++;
                cout << "Key inserted." << endl;
                break;
            }
            case 4: {
                int i, k;
                cout << "Enter index of element to increase: ";
                cin >> i;
                cout << "Enter new key value: ";
                cin >> k;
                try {
                    Heap::HeapIncreaseKey(arr, i, k);
                    cout << "Key increased." << endl;
                } catch (const char* msg) {
                    cerr << msg << endl;
                }
                break;
            }
            case 5: {
                int max = Heap::HeapExtractMax(arr, heap_size);
                heap_size--;
                cout << "Max element extracted: " << max << endl;
                break;
            }
            case 6: {
                Heap::HeapSortDescending(arr, heap_size);
                cout << "Heap sorted in descending order: ";
                printArray(arr, heap_size);
                break;
            }
            case 7: {
                Heap::BuildMinHeap(arr, heap_size);
                cout << "Min heap built: ";
                printArray(arr, heap_size);
                break;
            }
            case 8: {
                int min = Heap::HeapExtractMin(arr, heap_size);
                heap_size--;
                cout << "Min element extracted: " << min << endl;
                break;
            }
            case 9: {
                cout << "Enter key to insert: ";
                cin >> key;
                Heap::MinHeapInsert(arr, heap_size, key);
                heap_size++;
                cout << "Key inserted." << endl;
                break;
            }
            case 10: {
                exit = true;
                break;
            }
            default: {
                cout << "Invalid choice. Try again." << endl;
                break;
            }
        }
    }

    return 0;
}

