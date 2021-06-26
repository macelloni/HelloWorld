#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"
#include "sortingmethods.h"

sortResult sort_byBubble(intArray input)
{
    sortResult out = _initSortResult(input, BubbleSort);

    clock_t start = clock();
    _bubbleSort(&out.arr, &out.log);
    clock_t end = clock();

    out.log.duration = _formatTime(start, end);

    return out;
}

sortResult sort_bySelection(intArray input)
{
    sortResult out = _initSortResult(input, SelectionSort);

    clock_t start = clock();
    _selectionSort(&out.arr, &out.log);
    clock_t end = clock();

    out.log.duration = _formatTime(start, end);

    return out;
}

sortResult sort_byInsertion(intArray input)
{
    sortResult out = _initSortResult(input, InsertionSort);

    clock_t start = clock();
    _insertionSort(&out.arr, &out.log);
    clock_t end = clock();

    out.log.duration = _formatTime(start, end);

    return out;
}

sortResult sort_byShellsMethod(intArray input)
{
    sortResult out = _initSortResult(input, ShellSort);

    clock_t start = clock();
    _shellSort(&out.arr, &out.log);
    clock_t end = clock();

    out.log.duration = _formatTime(start, end);

    return out;
}

sortResult sort_byMerge(intArray input)
{
    sortResult out = _initSortResult(input, MergeSort);

    clock_t start = clock();
    _mergeSort(&out.arr, &out.log, 0, out.arr.len - 1);
    clock_t end = clock();

    out.log.duration = _formatTime(start, end);

    return out;
}

sortResult sort_Quick(intArray input)
{
    sortResult out = _initSortResult(input, QuickSort);

    clock_t start = clock();
    _quickSort(&out.arr, &out.log, 0, out.arr.len - 1);
    clock_t end = clock();

    out.log.duration = _formatTime(start, end);

    return out;
}

sortResult sort_Heap(intArray input)
{
    // Currently counts first heapify as well
    sortResult out = _initSortResult(input, HeapSort);

    clock_t start = clock();
    _heapSort(&out.arr, &out.log);
    clock_t end = clock();

    out.log.duration = _formatTime(start, end);

    return out;
}

sortResult _initSortResult(intArray input, methodEmployed arg)
{
    sortResult out;

    out.arr.name = malloc(strlen(input.name) + 24 * sizeof(char));
    sprintf(out.arr.name, "%s, sorted", input.name);
    out.arr.len = input.len;
    
    out.arr.data = malloc(input.len * sizeof(int));
    for (int i = 0; i < input.len; i++)
    {
        out.arr.data[i] = input.data[i];
    }

    out.log.method = arg;
    out.log.ifblocks = 0;
    out.log.iterations = 0;
    out.log.swaps = 0;

    return out;
}

double _formatTime(clock_t start, clock_t end)
{
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}