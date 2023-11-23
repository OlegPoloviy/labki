#include <iostream>
#include "Sort.h"
#include "Sort.cpp"

int main()
{
    const int size = 10;
    int arr[size] = { 10, 3, 8, 6, 2, 7, 1, 5, 4, 9 };

    std::cout << "Before sorting:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    MergeSort(arr, 0, size - 1);

    std::cout << "After sorting:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
