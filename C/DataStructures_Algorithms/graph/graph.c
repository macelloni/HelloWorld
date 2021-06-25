#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "graph.h"

graphVertex create_Vertex(char *labelInput, int dataInput)
{
    graphVertex out;

    strcpy(out.label, labelInput);
    out.data = dataInput;

    return out;
}

simpleGraph create_RandSG(char *nameInput, int order, int ceil)
{
    simpleGraph out = _create_BlankSG(nameInput);

    out.order = order;
    out.nodes = malloc(order * sizeof(graphVertex));
    // out.adjMatrix = malloc(order * sizeof(int *));

    for (int i = 0; i < order; i++)
    {

        out.nodes[i] = create_Vertex(_genDefaultVtxLabel(i), rand() % ceil);
        out.nodes[i].adjacency = malloc(out.order * sizeof(int));

        for (int j = 0; j < out.order; j++)
        {
            out.nodes[i].adjacency[j] = rand() % 2;
        }

        // out.adjMatrix[i] = out.nodes[i].adjacency;
    }

    return out;
}

void destroy_SimpleGraph(simpleGraph *sg)
{
    for (int i = 0; i < sg->order; i++)
    {
        free(sg->nodes[i].adjacency);
    }
    // free(sg->adjMatrix);
    free(sg->nodes);
}

simpleGraph _create_BlankSG(char *nameInput)
{
    simpleGraph out;

    out.order = 0;
    strcpy(out.name, nameInput);

    return out;
}

char *_genDefaultVtxLabel(int i)
{
    char localLabel[3 + 1];
    sprintf(localLabel, "v%d", i + 1);

    char *out = localLabel;
    return out;
}