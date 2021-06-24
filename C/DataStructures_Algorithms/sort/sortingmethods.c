#include "sortingmethods.h"
// #include "../datastructures/binarytrees.h"

void _bubbleSort(intArray *arr, sortLog *log)
{
    for (int i = 0; i < (arr->len - 1); i++)
    {
        for (int j = i + 1; j < arr->len; j++)
        {
            if (arr->data[i] > arr->data[j])
            {
                _swap(&arr->data[i], &arr->data[j]);

                log->ifblocks++;
                log->swaps++;
            }

            log->iterations++;
        }

        log->iterations++;
    }
}

void _selectionSort(intArray *arr, sortLog *log)
{
    for (int i = 0; i < (arr->len - 1); i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < arr->len; j++)
        {
            if (arr->data[j] < arr->data[minIndex])
            {
                minIndex = j;

                log->ifblocks++;
            }

            log->iterations++;
        }

        if (i != minIndex)
        {
            _swap(&arr->data[i], &arr->data[minIndex]);

            log->ifblocks++;
            log->swaps++;
        }

        log->iterations++;
    }
}

void _insertionSort(intArray *arr, sortLog *log)
{
    for (int i = 1; i < arr->len; i++)
    {
        int j = i;

        while (arr->data[j] < arr->data[j - 1] && j != 0)
        {
            _swap(&arr->data[j], &arr->data[j - 1]);
            j--;

            log->swaps++;
            log->ifblocks++;
            log->iterations++;
        }

        log->iterations++;
    }
}

void _shellSort(intArray *arr, sortLog *log)    // At the moment, log is limited; Might require refactor
{
    for (int gap = arr->len / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < arr->len; i++)
        {
            int temp = arr->data[i];
            int j = i;

            for (j; j >= gap && arr->data[j - gap] > temp; j -= gap)
            {
                _swap(&arr->data[j], &arr->data[j - gap]);

                log->ifblocks++;
                log->swaps++;
            }

            arr->data[j] = temp;
            log->iterations++;
        }

        log->iterations++;
    }
}

void _mergeSort(intArray *arr, int lowerIndex, int higherIndex)
{
    if (lowerIndex < higherIndex)
    {
        int middleIndex = lowerIndex + (higherIndex - lowerIndex) / 2;

        _mergeSort(arr, lowerIndex, middleIndex);
        _mergeSort(arr, middleIndex + 1, higherIndex);
        _merge(arr, lowerIndex, middleIndex, higherIndex);
    }
}

void _merge(intArray *arr, int lowerIndex, int middleIndex, int higherIndex)
{
    int lowerBound = middleIndex - lowerIndex + 1;
    int upperBound = higherIndex - middleIndex;

    int localLowerArr[lowerBound], localUpperArr[upperBound];

    for (int i = 0; i < lowerBound; i++)
    {
        localLowerArr[i] = arr->data[lowerIndex + i];
    }
    for (int i = 0; i < upperBound; i++)
    {
        localUpperArr[i] = arr->data[middleIndex + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = lowerIndex;
    while (i < lowerBound && j < upperBound)
    {
        if (localLowerArr[i] <= localUpperArr[j])
        {
            arr->data[k] = localLowerArr[i];
            i++;
        }
        else
        {
            arr->data[k] = localUpperArr[j];
            j++;
        }

        k++;
    }

    while (i < lowerBound)
    {
        arr->data[k] = localLowerArr[i];
        i++;
        k++;
    }
    while (j < upperBound)
    {
        arr->data[k] = localUpperArr[j];
        j++;
        k++;
    }
}

void _quickSort(intArray *arr, int lowerIndex, int higherIndex)
{
    if (lowerIndex < higherIndex)
    {
        int partitioningIndex = _partition(arr, lowerIndex, higherIndex);

        _quickSort(arr, lowerIndex, partitioningIndex - 1);
        _quickSort(arr, partitioningIndex + 1, higherIndex);
    }
}

int _partition(intArray *arr, int lowerIndex, int higherIndex)
{
    int pivot = arr->data[higherIndex];
    int i = lowerIndex - 1;

    for (int j = lowerIndex; j < higherIndex; j++)
    {
        if (arr->data[j] < pivot)
        {
            i++;
            _swap(&arr->data[i], &arr->data[j]);
        }
    }

    _swap(&arr->data[i + 1], &arr->data[higherIndex]);

    return i + 1;
}

void _swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}