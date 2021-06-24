#ifndef SORTINGMETHODS_H
#define SORTINGMETHODS_H

#include "intarray.h"
#include "sort.h"

void _swap(int *a, int *b);

void _bubbleSort(intArray *arr, sortLog *log);
void _selectionSort(intArray *arr, sortLog *log);
void _insertionSort(intArray *arr, sortLog *log);
void _shellSort(intArray *arr);

void _mergeSort(intArray *arr, int lowerIndex, int higherIndex);
void _merge(intArray *arr, int lowerIndex, int middleIndex, int higherIndex);

void _quickSort(intArray *arr, int lowerIndex, int higherIndex);
int _partition(intArray *arr, int lowerIndex, int higherIndex);

// ... heapsort;

#endif