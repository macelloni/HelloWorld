#include <stdio.h>
#include <string.h>

#include "cli_out.h"
#include "graph_out.h"
#include "linkedlist_out.h"

void displayMenu(menu m)
{
    printf(" %s\n", m.title);

    for (int i = 0; i < m.amountOfItems; i++)
    {
        printf("    %d - %s\n", i + 1, m.items[i]);
    }

    switch (m.type)
    {
    case MainMenu:
        printf("\n    0 - Exit\n");
        break;
    default:
        printf("\n    0 - Back\n");
        break;
    }
}

void displayArray(intArray arr, arr_ViewMode mode)
{
    char separator[2 + 1];
    char prefix[8 + 1];

    switch (mode)
    {
    case SingleLine:
        strcpy(separator, ",");
        strcpy(prefix, " ");
        break;
    case NewLine:
        strcpy(separator, "\n");
        strcpy(prefix, "    ");
        break;
    }

    if (mode == SingleLine)
    {
        printf("   ");
    }

    for (int i = 0; i < arr.len - 1; i++)
    {
        printf("%s%d%s", prefix, arr.data[i], separator);
    }
    printf("%s%d\n\n", prefix, arr.data[arr.len - 1]);
}

void displaySortResult(sortResult result)
{
    displayArray(result.arr, SingleLine);

    printf("  Sort Data: ");

    if (result.log.method)
    {
        printf("\n");
        char method[32 + 1];

        switch (result.log.method)
        {
        case BubbleSort:
            strcpy(method, "Bubble Sort");
            break;
        case SelectionSort:
            strcpy(method, "Selection Sort");
            break;
        case InsertionSort:
            strcpy(method, "Insertion Sort");
            break;
        case ShellSort:
            strcpy(method, "Shell Sort");
            break;
        case MergeSort:
            strcpy(method, "Merge Sort");
            break;
        case QuickSort:
            strcpy(method, "Quick Sort");
            break;
        case HeapSort:
            strcpy(method, "Heap Sort");
            break;
        }

        printf("    Method             : %s\n", method);
        printf("    Time               : %f seconds\n", result.log.duration);
        printf("    # of iterations    : %d\n", result.log.iterations);
        printf("    If-blocks executed : %d\n", result.log.ifblocks);
        printf("    # of swaps         : %d\n", result.log.swaps);
    }
    else
    {
        printf("Array was not sorted yet.");
    }
}

void displayGraphAdj(int order, graphVertex *nodes)
{
    printf("    Adjacency Matrix: \n\n");

    _displayVtxList(order, nodes);
    for (int i = 0; i < order; i++)
    {
        printf("\n");
        _displayVtxAdj(order, nodes[i]);
    }

    printf("\n\n");
}

void displayLinkedList(linkedList list)
{
    if (list.len > 0)
    {
        if (list.type == SinglyLinkedList || list.type == DoublyLinkedList)
        {
            _displayList(list);
        }
        else if (list.type == CircularList || list.type == DoublyCircularList)
        {
            _displayCircList(list);
        }
    }
    else
    {
        printf("List is empty!\n");
    }
}