#include <stdio.h>

#include "graph_out.h"

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