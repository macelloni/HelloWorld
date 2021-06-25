#include <stdio.h>
#include <string.h>

#include "cli_out.h"

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

void _displayVtxList(int order, graphVertex *nodes)
{
    printf("           ");

    for (int i = 0; i < order; i++)
    {

        printf("%s  ", nodes[i].label);
    }
}

void _displayVtxAdj(int order, graphVertex v)
{
    printf("       %s  ", v.label);
    for (int i = 0; i < order; i++)
    {
        printf("%d   ", v.adjacency[i]);
    }
}

void displayLinkedList(linkedList list)
{
    if (list.type == SinglyLinked || list.type == DoublyLinked)
    {
        _displayList(list);
    }
    else if (list.type == Circular || list.type == DoublyCircular)
    {
        _displayCircList(list);
    }
}

void _displayLNode(linkableNode *ln)
{
    printf("Node value: %d\n", ln->data);

    char previousData[32 + 1];
    char nextData[32 + 1];

    if (ln->previous != NULL)
    {
        sprintf(previousData, "    Previous: %d", ln->previous->data);
    }
    else
    {
        sprintf(previousData, "    Previous: Null");
    }

    if (ln->next != NULL)
    {
        sprintf(nextData, "    Next: %d", ln->next->data);
    }
    else
    {
        sprintf(nextData, "    Next: Null");
    }

    printf("%s%s", previousData, nextData);
    printf("\n");
}

void _displayList(linkedList list)
{
    for (linkableNode *current = *list.head;
         current != (*list.tail)->next;
         current = current->next)
    {
        _displayLNode(current);
    }
}

void _displayCircList(linkedList list)
{
    _displayLNode(*list.head);
    
    for (linkableNode *current = (*list.head)->next;
         current != (*list.tail)->next;
         current = current->next)
    {
        _displayLNode(current);
    }
}