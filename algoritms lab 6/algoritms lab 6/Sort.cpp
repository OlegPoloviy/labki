#include "Sort.h"

void Merge(int arr[], int left[], int leftSize, int right[], int rightSize)
{
    int i = 0, j = 0, k = 0;

    // ������ ���� ������ � ����������� �����������
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

    // ��������� ����� �������� � ����� ������
    while (i < leftSize)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    // ��������� ����� �������� � ������� ������
    while (j < rightSize)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int size)
{
    if (size < 2) // ������� �������
        return;

    // ��������� ������ �� �� �������
    int
}
