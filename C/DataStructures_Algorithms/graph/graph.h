#ifndef GRAPH_H
#define GRAPH_H

typedef struct GraphVertex
{
    char label[3 + 1]; // intended for: "v99"
    int data;          // by default, 0 to MAX unless specified
    int *adjacency;
} graphVertex;

typedef struct SimpleGraph
{
    char name[16 + 1];
    graphVertex *nodes;
    // int **adjMatrix;
    unsigned short int order;
} simpleGraph;

graphVertex create_Vertex(char *labelInput, int dataInput);
simpleGraph create_RandSG(char *nameInput, int order, int ceil);
void destroy_SimpleGraph(simpleGraph *sg);

simpleGraph _create_BlankSG(char *nameInput);
char *_genDefaultVtxLabel(int i);

#endif