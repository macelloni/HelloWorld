#ifndef SORT_H
#define SORT_H

#include "intarray.h"

/*
typedef enum SortMethod
{
    Unsorted,
    BubbleSort,
    SelectionSort,
    InsertionSort,
    ShellSort,
    MergeSort,
    QuickSort,
    HeapSort
} sortMethod;

typedef struct SortLog
{
    sortMethod method;
    float duration;
    int iterations;
    int swaps;
} sortLog;

typedef struct SortResult
{
    intArray arr;
    sortLog log;
} sortResult;
*/

void sort_byBubble(intArray *arr);
void sort_bySelection(intArray *arr);
void sort_byInsertion(intArray *arr);
void sort_ShellsMethod(intArray *arr);
// void sort_byMerge(intArray *arr);
// void sort_Quick(intArray *arr);
// void sort_Heap(intArray *arr);

void _mergeSort(intArray *arr, int lowerIndex, int higherIndex);
void _merge(intArray *arr, int lowerIndex, int middleIndex, int higherIndex);
void _quickSort(intArray *arr, int lowerIndex, int higherIndex);
int _partition(intArray *arr, int lowerIndex, int higherIndex);
void _swap(int *a, int *b);

#endif