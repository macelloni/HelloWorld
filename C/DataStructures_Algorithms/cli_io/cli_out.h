#ifndef CLI_OUT_H
#define CLI_OUT_H

#include "../menu/menu.h"
#include "../sort/intarray.h"
#include "../sort/sort.h"
#include "../graph/graph.h"

typedef enum DisplayArrayArgument
{
    SingleLine,
    NewLine
} arr_ViewMode;

void displayMenu(menu m);

// Below: To be modularized in ./x_out.c and ./x_out.h

void displayArray(intArray arr, arr_ViewMode mode);
void displaySortResult(sortResult result);

void displayGraphAdj(int order, graphVertex *nodes);
void _displayVtxList(int order, graphVertex *nodes);
void _displayVtxAdj(int order, graphVertex v);

#endif