#include "Sort.h"

void Merge(int arr[], int left[], int leftSize, int right[], int rightSize)
{
    int i = 0, j = 0, k = 0;

    // злиття двох масивів у відсортовану послідовність
    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // додавання решти елементів з лівого масиву
    while (i < leftSize)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    // додавання решти елементів з правого масиву
    while (j < rightSize)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int size)
{
    if (size < 2) // базовий випадок
        return;

    // розділення масиву на дві частини
    int
}
