#ifndef SORTINGMETHODS_H
#define SORTINGMETHODS_H

#include "intarray.h"
#include "sort.h"

void _swap(int *a, int *b);

void _bubbleSort(intArray *arr, sortLog *log);
void _selectionSort(intArray *arr, sortLog *log);
void _insertionSort(intArray *arr, sortLog *log);
void _shellSort(intArray *arr, sortLog *log);

void _mergeSort(intArray *arr, sortLog *log, int lowerIndex,
                int higherIndex);
void _merge(intArray *arr, sortLog *log, int lowerIndex,
            int middleIndex, int higherIndex);

void _quickSort(intArray *arr, sortLog *log, int lowerIndex,
                int higherIndex);
int _partition(intArray *arr, sortLog *log, int lowerIndex,
               int higherIndex);

void _heapSort(intArray *arr, sortLog *log);
void _heapify(intArray *arr, sortLog *log, int len, int i);

#endif