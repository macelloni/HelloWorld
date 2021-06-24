#ifndef SORT_H
#define SORT_H

#include <time.h>
#include "intarray.h"

typedef enum MethodEmployed
{
    Unsorted = 0,
    BubbleSort,
    SelectionSort,
    InsertionSort,
    ShellSort,
    MergeSort,
    QuickSort,
    HeapSort
} methodEmployed;

typedef struct SortLog
{
    methodEmployed method;
    double duration;
    unsigned int ifblocks;
    unsigned int iterations;
    unsigned int swaps;
} sortLog;

typedef struct SortResult
{
    intArray arr;
    sortLog log;
} sortResult;

sortResult sort_byBubble(intArray input);
sortResult sort_bySelection(intArray input);
sortResult sort_byInsertion(intArray input);
sortResult sort_byShellsMethod(intArray input);

sortResult _initSortResult(intArray input, methodEmployed arg);
double _formatTime(clock_t start, clock_t end);

#endif