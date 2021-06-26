#ifndef CLI_OUT_H
#define CLI_OUT_H

#include "../menu/menu.h"
#include "../sort/intarray.h"
#include "../sort/sort.h"
#include "../graph/graph.h"
#include "../datastructures/linkedlist.h"

typedef enum ArrayViewMode
{
    SingleLine,
    NewLine
} arr_ViewMode;

void displayMenu(menu m);

void displayArray(intArray arr, arr_ViewMode mode);
void displaySortResult(sortResult result);

void displayGraphAdj(int order, graphVertex *nodes);

void displayLinkedList(linkedList list);


#endif